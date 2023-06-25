import {test, expect} from '@jest/globals';
import libtorrent from '../index.js';

test('session is valid', () => {
	expect(libtorrent).toBe(libtorrent);
});
