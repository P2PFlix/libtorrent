import {test, expect} from '@jest/globals';
import lt from '../index.js';

test('gets libtorrent version', () => {
	expect(lt.getLibTorrentVersion()).toBe('2.1.0.0');
});
