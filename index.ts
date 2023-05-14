import {createRequire} from 'node:module';

type GetClientInfoReturnModel = {
	readonly downlodRate: number;
	readonly uploadRte: number;
	readonly progress: number;
	readonly peers: number;
	readonly ratio: number;
	readonly nb_torrents: number;
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

type TorrentHandleType = any;

type TorrentModel = {
	pause: () => boolean;
	resume: () => boolean;
	setLimit: (limit: number, type: TorrentType) => boolean;
	getFiles: () => {data: TorrentFileModel[]};
	info: () => TorrentInfoModel;
};

type ClientModel = {
	addTorrent: (savePath: string, torrent: string) => number;
	hasTorrents: () => boolean;
	isDestroyed: () => boolean;
	removeTorrent: () => undefined;
	getTorrents: () => TorrentHandleType[];
	getTorrent: (torrentId: number) => TorrentModel;
	getClientInfo: () => GetClientInfoReturnModel;
};

declare class Torrent implements TorrentModel {
	pause: () => boolean;
	resume: () => boolean;
	setLimit: (limit: number, type: TorrentType) => boolean;
	getFiles: () => {data: TorrentFileModel[]};
	info: () => TorrentInfoModel;
}

declare class Client implements ClientModel {
	getClientInfo: () => GetClientInfoReturnModel;
	addTorrent(savePath: string, torrent: string): number;
	hasTorrents(): boolean;
	isDestroyed(): boolean;
	removeTorrent(): undefined;
	getTorrent(torrentId: number): TorrentModel;
	getTorrents(): TorrentHandleType[];
}

type LibtorrentNode = {
	getLibTorrentVersion: () => string;
	Client: typeof Client;
};

const require = createRequire(import.meta.url);
const libtorrentNode
  = require('../build/Release/libtorrentNode.node') as LibtorrentNode;

export default libtorrentNode;
