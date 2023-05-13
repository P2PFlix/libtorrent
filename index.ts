import {createRequire} from 'node:module';

declare class Client {
	addTorrent(savePath: string, torrent: string): number;
}

type LibtorrentNode = {
	version: () => '2.1.0.0';
	Client: typeof Client;
};

const require = createRequire(import.meta.url);
const libtorrentNode = require('../build/Release/libtorrentNode.node') as LibtorrentNode;

export default libtorrentNode;
