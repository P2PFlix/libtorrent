import {createRequire} from 'node:module';
import path from 'node:path';

type GetClientInfoReturnModel = {
	downlodRate: number;
	uploadRte: number;
	progress: number;
	peers: number;
	ratio: number;
	nb_torrents: number;
};

type TorrentFileModel = {
	size: number;
	filename: string;
	path: string;
};

type TorrentInfoModel = {
	id: number;
	downloadLimit: number;
	uploadLimit: number;
	name: string;
	progress: number;
	done: boolean;
	totalSize: number;
	magnetURI: string;
	downloaded: number;
	state: string;
	uploadRate: number;
	downloadRate: number;
	path: string;
	numPeers: number;
	isAutoManaged: boolean;
	isPaused: boolean;
	savePath: string;
};

type TorrentType = 'upload' | 'download';

declare class Torrent {
	pause(): boolean;
	resume(): boolean;
	setLimit(limit: number, type: TorrentType): boolean;
	getFiles(): TorrentFileModel[];
	info(): TorrentInfoModel;
}

declare class Client {
	getClientInfo(): GetClientInfoReturnModel;
	addTorrent(savePath: string, torrent: string): number;
	hasTorrents(): boolean;
	isDestroyed(): boolean;
	removeTorrent(): undefined;
	getTorrent(torrentId: number): Torrent;
	getTorrents(): Torrent[];
}

type LibtorrentNode = {
	getLibTorrentVersion: () => string;
	Client: typeof Client;
};

const id = path.join('..', 'build', 'Release', 'libtorrentNode.node');
const require = createRequire(import.meta.url);
const libtorrentNode = require(id) as LibtorrentNode;

export default libtorrentNode;
