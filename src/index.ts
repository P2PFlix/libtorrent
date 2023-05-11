import {createRequire} from 'node:module';

type LibtorrentNode = {
	hello: () => 'world';
};

const require = createRequire(import.meta.url);
const hello = require('../../build/Release/libtorrentNode.node') as LibtorrentNode;

export default hello;
