import {createRequire} from 'node:module';

// Interface iGetClientInfoReturnModel {
//   readonly downlodRate: number;
//   readonly uploadRte: number;
//   readonly progress: number;
//   readonly peers: number;
//   readonly ratio: number;
//   readonly nb_torrents: number;
// }
declare class Client {
	addTorrent(savePath: string, torrent: string): number;
	//   GetTorrents()
	hasTorrents(): boolean;
	isDestroyed(): boolean;
}

type LibtorrentNode = {
	getLibTorrentVersion: () => string;
	Client: typeof Client;
};

const require = createRequire(import.meta.url);
const libtorrentNode
  = require('../build/Release/libtorrentNode.node') as LibtorrentNode;

export default libtorrentNode;
