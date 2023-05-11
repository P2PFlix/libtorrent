import {createRequire} from 'node:module';

type LibtorrentNode = {
	hello: () => 'world';
	shuffle: () => never;
};

const require = createRequire(import.meta.url);
const libtorrentNode = require('../build/Release/libtorrentNode.node') as LibtorrentNode;

export default libtorrentNode;
