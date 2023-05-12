import {createRequire} from 'node:module';

type LibtorrentNode = {
	version: () => '2.1.0.0';
};

const require = createRequire(import.meta.url);
const libtorrentNode = require('../build/Release/libtorrentNode.node') as LibtorrentNode;

export default libtorrentNode;
