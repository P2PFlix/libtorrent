#include <iostream>
#include <libtorrent/session.hpp>
#include <libtorrent/alert_types.hpp>
#include <libtorrent/alert.hpp>
#include <libtorrent/magnet_uri.hpp>

// #include <node_api.h>
#include <uv.h>

#include "test.hpp"

std::string my_listen_interfaces = "0.0.0.0:6881"; // "0.0.0.0:6881,[::]:6881"  "{E4F0B674-0DFC-48BB-98A5-2AA730BDB6D6}:7777"
std::string target_torrentfile_path = "../../test.torrent";

int main(int argc, char *argv[])
{
    try
    {
        lt::settings_pack session_params;
        session_params.set_int(lt::settings_pack::alert_mask, lt::alert_category::all);

        if (my_listen_interfaces.length() != 0)
        {
            session_params.set_str(lt::settings_pack::listen_interfaces, my_listen_interfaces);
        }

        lt::session session(session_params);

        lt::add_torrent_params torrent_params;
        lt::error_code ec;

        torrent_params.save_path = ".";
        lt::parse_magnet_uri(magUrl, torrent_params, ec);

        // torrent_params.save_path = "./data";
        // torrent_params.ti = std::make_shared<lt::torrent_info>(target_torrentfile_path);

        lt::torrent_handle h = session.add_torrent(std::move(torrent_params));

        bool allBreak = false;

        while (true)
        {
            if (allBreak)
                break;

            std::vector<lt::alert *> alerts;
            session.pop_alerts(&alerts);

            lt::state_update_alert *st;
            for (lt::alert *a : alerts)
            {
                if (allBreak)
                    break;
                std::cout << ".";
                switch (a->type())
                {
                case lt::state_update_alert::alert_type:
                    // lt::state_update_alert
                std::cout<<"updating\n";
                    st = (lt::state_update_alert *)(a);
                    {
                        lt::torrent_status const &s = st->status[0];
                        std::cout << (s.download_payload_rate / 1000) << " kB/s "
                                  << (s.total_done / 1000) << " kB ("
                                  << (s.progress_ppm / 10000) << "%) downloaded ("
                                  << s.num_peers << " peers)";
                        std::cout.flush();
                    }
                    break;
                case lt::torrent_finished_alert::alert_type:
                    std::cout << ">> finished : ==" << std::endl;
                    allBreak = true;
                    break;
                case lt::torrent_error_alert::alert_type:
                    std::cout << ">> error : ==" << std::endl;
                    allBreak = true;
                    break;
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}