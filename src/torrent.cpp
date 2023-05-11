#include "torrent.hpp"

void LibtorrentNodeRandom::printVec(std::vector<int> &vec)
{
    for (int i : vec)
    {
        std::cout << i << " ";
    }
}

void LibtorrentNodeRandom::shuffle()
{
    std::cout << "before: ";
    printVec(this->vec);

    libtorrent::aux::random_shuffle<std::vector<int>>(vec);

    std::cout << "after: ";
    printVec(vec);
}