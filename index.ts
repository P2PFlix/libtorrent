import {type Buffer} from 'node:buffer';
import {createRequire} from 'node:module';

declare class SettingsPack {
	settingsPack: never;
	userAgent: number;
	announceIp: number;
	handshakeClientVersion: number;
	outgoingInterfaces: number;
	listenInterfaces: number;
	proxyHostname: number;
	proxyUsername: number;
	proxyPassword: number;
	i2pHostname: number;
	peerFingerprint: number;
	dhtBootstrapNodes: number;
	allowMultipleConnectionsPerIp: number;
	sendRedundantHave: number;
	useDhtAsFallback: number;
	upnpIgnoreNonrouters: number;
	useParoleMode: number;
	autoManagePreferSeeds: number;
	dontCountSlowTorrents: number;
	closeRedundantConnections: number;
	prioritizePartialPieces: number;
	rateLimitIpOverhead: number;
	announceToAllTiers: number;
	announceToAllTrackers: number;
	preferUdpTrackers: number;
	disableHashChecks: number;
	allowI2pMixed: number;
	noAtimeStorage: number;
	incomingStartsQueuedTorrents: number;
	reportTrueDownloaded: number;
	strictEndGameMode: number;
	enableOutgoingUtp: number;
	enableIncomingUtp: number;
	enableOutgoingTcp: number;
	enableIncomingTcp: number;
	noRecheckIncompleteResume: number;
	anonymousMode: number;
	reportWebSeedDownloads: number;
	seedingOutgoingConnections: number;
	noConnectPrivilegedPorts: number;
	smoothConnects: number;
	alwaysSendUserAgent: number;
	applyIpFilterToTrackers: number;
	banWebSeeds: number;
	supportShareMode: number;
	reportRedundantBytes: number;
	listenSystemPortFallback: number;
	announceCryptoSupport: number;
	enableUpnp: number;
	enableNatpmp: number;
	enableLsd: number;
	enableDht: number;
	preferRc4: number;
	proxyHostnames: number;
	proxyPeerConnections: number;
	autoSequential: number;
	proxyTrackerConnections: number;
	enableIpNotifier: number;
	dhtPreferVerifiedNodeIds: number;
	dhtRestrictRoutingIps: number;
	dhtRestrictSearchIps: number;
	dhtExtendedRoutingTable: number;
	dhtAggressiveLookups: number;
	dhtPrivacyLookups: number;
	dhtEnforceNodeId: number;
	dhtIgnoreDarkInternet: number;
	dhtReadOnly: number;
	pieceExtentAffinity: number;
	validateHttpsTrackers: number;
	ssrfMitigation: number;
	allowIdna: number;
	enableSetFileValidData: number;
	socks5UdpSendLocalEp: number;
	trackerCompletionTimeout: number;
	trackerReceiveTimeout: number;
	stopTrackerTimeout: number;
	trackerMaximumResponseLength: number;
	pieceTimeout: number;
	requestTimeout: number;
	requestQueueTime: number;
	maxAllowedInRequestQueue: number;
	maxOutRequestQueue: number;
	wholePiecesThreshold: number;
	peerTimeout: number;
	urlseedTimeout: number;
	urlseedPipelineSize: number;
	urlseedWaitRetry: number;
	filePoolSize: number;
	maxFailcount: number;
	minReconnectTime: number;
	peerConnectTimeout: number;
	connectionSpeed: number;
	inactivityTimeout: number;
	unchokeInterval: number;
	optimisticUnchokeInterval: number;
	numWant: number;
	initialPickerThreshold: number;
	allowedFastSetSize: number;
	suggestMode: number;
	maxQueuedDiskBytes: number;
	handshakeTimeout: number;
	sendBufferLowWatermark: number;
	sendBufferWatermark: number;
	sendBufferWatermarkFactor: number;
	chokingAlgorithm: number;
	seedChokingAlgorithm: number;
	diskIoWriteMode: number;
	diskIoReadMode: number;
	outgoingPort: number;
	numOutgoingPorts: number;
	peerDscp: number;
	activeDownloads: number;
	activeSeeds: number;
	activeChecking: number;
	activeDhtLimit: number;
	activeTrackerLimit: number;
	activeLsdLimit: number;
	activeLimit: number;
	autoManageInterval: number;
	seedTimeLimit: number;
	autoScrapeInterval: number;
	autoScrapeMinInterval: number;
	maxPeerlistSize: number;
	maxPausedPeerlistSize: number;
	minAnnounceInterval: number;
	autoManageStartup: number;
	seedingPieceQuota: number;
	maxRejects: number;
	recvSocketBufferSize: number;
	sendSocketBufferSize: number;
	maxPeerRecvBufferSize: number;
	optimisticDiskRetry: number;
	maxSuggestPieces: number;
	localServiceAnnounceInterval: number;
	dhtAnnounceInterval: number;
	udpTrackerTokenExpiry: number;
	numOptimisticUnchokeSlots: number;
	maxPexPeers: number;
	tickInterval: number;
	shareModeTarget: number;
	uploadRateLimit: number;
	downloadRateLimit: number;
	dhtUploadRateLimit: number;
	unchokeSlotsLimit: number;
	connectionsLimit: number;
	connectionsSlack: number;
	utpTargetDelay: number;
	utpGainFactor: number;
	utpMinTimeout: number;
	utpSynResends: number;
	utpFinResends: number;
	utpNumResends: number;
	utpConnectTimeout: number;
	utpLossMultiplier: number;
	mixedModeAlgorithm: number;
	listenQueueSize: number;
	torrentConnectBoost: number;
	alertQueueSize: number;
	maxMetadataSize: number;
	hashingThreads: number;
	checkingMemUsage: number;
	predictivePieceAnnounce: number;
	aioThreads: number;
	trackerBackoff: number;
	shareRatioLimit: number;
	seedTimeRatioLimit: number;
	peerTurnover: number;
	peerTurnoverCutoff: number;
	peerTurnoverInterval: number;
	maxHttpRecvBufferSize: number;
	maxRetryPortBind: number;
	alertMask: number;
	outEncPolicy: number;
	inEncPolicy: number;
	allowedEncLevel: number;
	inactiveDownRate: number;
	inactiveUpRate: number;
	proxyType: number;
	proxyPort: number;
	i2pPort: number;
	urlseedMaxRequestBytes: number;
	webSeedNameLookupRetry: number;
	closeFileInterval: number;
	utpCwndReduceTimer: number;
	maxWebSeedConnections: number;
	resolverCacheTimeout: number;
	sendNotSentLowWatermark: number;
	rateChokerInitialThreshold: number;
	upnpLeaseDuration: number;
	maxConcurrentHttpAnnounces: number;
	dhtMaxPeersReply: number;
	dhtSearchBranching: number;
	dhtMaxFailCount: number;
	dhtMaxTorrents: number;
	dhtMaxDhtItems: number;
	dhtMaxPeers: number;
	dhtMaxTorrentSearchReply: number;
	dhtBlockTimeout: number;
	dhtBlockRatelimit: number;
	dhtItemLifetime: number;
	dhtSampleInfohashesInterval: number;
	dhtMaxInfohashesSampleCount: number;
	maxPieceCount: number;
	metadataTokenLimit: number;
	diskWriteMode: number;
	mmapFileSizeCutoff: number;
	i2pInboundQuantity: number;
	i2pOutboundQuantity: number;
	i2pInboundLength: number;
	i2pOutboundLength: number;
	stringTypeBase: number;
	intTypeBase: number;
	boolTypeBase: number;
	typeMask: number;
	indexMask: number;
	alwaysPwrite: number;
	alwaysMmapWrite: number;
	autoMmapWrite: number;
	noPieceSuggestions: number;
	suggestReadCache: number;
	fixedSlotsChoker: number;
	rateBasedChoker: number;
	roundRobin: number;
	fastestUpload: number;
	antiLeech: number;
	enableOsCache: number;
	disableOsCache: number;
	writeThrough: number;
	preferTcp: number;
	peerProportional: number;
	peForced: number;
	peEnabled: number;
	peDisabled: number;
	pePlaintext: number;
	peRc4: number;
	peBoth: number;
	none: number;
	socks4: number;
	socks5: number;
	socks5Pw: number;
	http: number;
	httpPw: number;
	// eslint-disable-next-line @typescript-eslint/naming-convention
	connectSeedEveryNDownload: number;
	constructor(settingsPack?: SettingsPack);
	setStr(name: number, value: string): void;
	setInt(name: number, value: number): void;
	setBool(name: number, value: boolean): void;
	getStr(name: number): string;
	getInt(name: number): number;
	getBool(name: number): boolean;
	hasVal(name: number): boolean;
	clear(name?: number): boolean;
}
declare class SessionParameters {
	sessionParams: never;
	dhtState: DhtState;
	constructor(settingsPack?: SessionParameters | SettingsPack);
}
declare class Session {
	session: never;
	constructor(sessionParameters?: SessionParameters | SettingsPack);
	popAlerts(alerts: Alert[]): void;
	sessionState(): SessionParameters;
	isValid(): boolean;
	postDhtStats(): void;
	postSessionStats(): void;
	postTorrentUpdates(): void;
	dhtSampleInfohashes(endpoint: Endpoint, sha1Hash: Sha1Hash): void;
}
declare class Endpoint {
	endpoint: never;
	constructor(endpoint?: Endpoint);
	port(port: number): void;
	address(address: Address): void;
}
declare class DhtState {
	dhtState: never;
	nodes: Endpoint[];
	constructor(dhtState?: DhtState);
}
declare class Address {
	address: never;
	constructor(address?: Address);
}
declare class DhtSampleInfohashesAlert {
	dhtSampleInfohashesAlert: never;
	constructor();
	samples(): Sha1Hash[];
}
declare class MetadataReceivedAlert {
	metadataReceivedAlert: never;
	handle: TorrentHandle;
	constructor();
}
declare class Sha1Hash {
	sha1Hash: never;
	constructor(sha1Hash?: Sha1Hash);
	assign(hex: Buffer): void;
}
declare class TorrentHandle {
	torrentHandle: never;
	constructor(torrentHandle?: Sha1Hash);
}
declare class Alert {
	alert: never;
	constructor();
	type(): number;
	what(): string;
	message(): string;
}
type Udp = {
	Endpoint: typeof Endpoint;
};
type Dht = {
	DhtState: typeof DhtState;
};
type Libtorrent = {
	SettingsPack: typeof SettingsPack;
	SessionParams: typeof SessionParameters;
	Session: typeof Session;
	Sha1Hash: typeof Sha1Hash;
	TorrentHandle: typeof TorrentHandle;
	Alert: typeof Alert;
	DhtSampleInfohashesAlert: typeof DhtSampleInfohashesAlert;
	MetadataReceivedAlert: typeof MetadataReceivedAlert;
	Address: typeof Address;
	udp: Udp;
	dht: Dht;
	version(): string;
	makeAddress(address: string): Address;
};
const require = createRequire(import.meta.url);
const libtorrent = require('../build/Release/libtorrent.node') as Libtorrent;
// //
// const crypto = await import('node:crypto');
// const session = new libtorrent.Session();
// setInterval(() => {
// 	const alerts: Alert[] = [];
// 	session.popAlerts(alerts);
// 	for (const alert of alerts) {
// 		const type = alert.what();
// 		if (type === 'dht_sample_infohashes') {
// 			const dhtSampleInfohashesAlert = new libtorrent.DhtSampleInfohashesAlert();
// 			dhtSampleInfohashesAlert.dhtSampleInfohashesAlert = alert.alert;
// 			console.log(dhtSampleInfohashesAlert.samples());
// 		} else {
// 			console.log(alert.message());
// 		}
// 	}
// });
// setInterval(() => {
// 	for (const node of session.sessionState().dhtState.nodes) {
// 		const sha = new libtorrent.Sha1Hash();
// 		sha.assign(crypto.randomBytes(20));
// 		session.dhtSampleInfohashes(node, sha);
// 	}
// });
// //
export default libtorrent;
