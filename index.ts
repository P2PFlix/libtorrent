import {type Buffer} from 'node:buffer';
import {createRequire} from 'node:module';

declare class SettingsPack {
	settingsPack: never;
	readonly userAgent: number;
	readonly announceIp: number;
	readonly handshakeClientVersion: number;
	readonly outgoingInterfaces: number;
	readonly listenInterfaces: number;
	readonly proxyHostname: number;
	readonly proxyUsername: number;
	readonly proxyPassword: number;
	readonly i2pHostname: number;
	readonly peerFingerprint: number;
	readonly dhtBootstrapNodes: number;
	readonly allowMultipleConnectionsPerIp: number;
	readonly sendRedundantHave: number;
	readonly useDhtAsFallback: number;
	readonly upnpIgnoreNonrouters: number;
	readonly useParoleMode: number;
	readonly autoManagePreferSeeds: number;
	readonly dontCountSlowTorrents: number;
	readonly closeRedundantConnections: number;
	readonly prioritizePartialPieces: number;
	readonly rateLimitIpOverhead: number;
	readonly announceToAllTiers: number;
	readonly announceToAllTrackers: number;
	readonly preferUdpTrackers: number;
	readonly disableHashChecks: number;
	readonly allowI2pMixed: number;
	readonly noAtimeStorage: number;
	readonly incomingStartsQueuedTorrents: number;
	readonly reportTrueDownloaded: number;
	readonly strictEndGameMode: number;
	readonly enableOutgoingUtp: number;
	readonly enableIncomingUtp: number;
	readonly enableOutgoingTcp: number;
	readonly enableIncomingTcp: number;
	readonly noRecheckIncompleteResume: number;
	readonly anonymousMode: number;
	readonly reportWebSeedDownloads: number;
	readonly seedingOutgoingConnections: number;
	readonly noConnectPrivilegedPorts: number;
	readonly smoothConnects: number;
	readonly alwaysSendUserAgent: number;
	readonly applyIpFilterToTrackers: number;
	readonly banWebSeeds: number;
	readonly supportShareMode: number;
	readonly reportRedundantBytes: number;
	readonly listenSystemPortFallback: number;
	readonly announceCryptoSupport: number;
	readonly enableUpnp: number;
	readonly enableNatpmp: number;
	readonly enableLsd: number;
	readonly enableDht: number;
	readonly preferRc4: number;
	readonly proxyHostnames: number;
	readonly proxyPeerConnections: number;
	readonly autoSequential: number;
	readonly proxyTrackerConnections: number;
	readonly enableIpNotifier: number;
	readonly dhtPreferVerifiedNodeIds: number;
	readonly dhtRestrictRoutingIps: number;
	readonly dhtRestrictSearchIps: number;
	readonly dhtExtendedRoutingTable: number;
	readonly dhtAggressiveLookups: number;
	readonly dhtPrivacyLookups: number;
	readonly dhtEnforceNodeId: number;
	readonly dhtIgnoreDarkInternet: number;
	readonly dhtReadOnly: number;
	readonly pieceExtentAffinity: number;
	readonly validateHttpsTrackers: number;
	readonly ssrfMitigation: number;
	readonly allowIdna: number;
	readonly enableSetFileValidData: number;
	readonly socks5UdpSendLocalEp: number;
	readonly trackerCompletionTimeout: number;
	readonly trackerReceiveTimeout: number;
	readonly stopTrackerTimeout: number;
	readonly trackerMaximumResponseLength: number;
	readonly pieceTimeout: number;
	readonly requestTimeout: number;
	readonly requestQueueTime: number;
	readonly maxAllowedInRequestQueue: number;
	readonly maxOutRequestQueue: number;
	readonly wholePiecesThreshold: number;
	readonly peerTimeout: number;
	readonly urlseedTimeout: number;
	readonly urlseedPipelineSize: number;
	readonly urlseedWaitRetry: number;
	readonly filePoolSize: number;
	readonly maxFailcount: number;
	readonly minReconnectTime: number;
	readonly peerConnectTimeout: number;
	readonly connectionSpeed: number;
	readonly inactivityTimeout: number;
	readonly unchokeInterval: number;
	readonly optimisticUnchokeInterval: number;
	readonly numWant: number;
	readonly initialPickerThreshold: number;
	readonly allowedFastSetSize: number;
	readonly suggestMode: number;
	readonly maxQueuedDiskBytes: number;
	readonly handshakeTimeout: number;
	readonly sendBufferLowWatermark: number;
	readonly sendBufferWatermark: number;
	readonly sendBufferWatermarkFactor: number;
	readonly chokingAlgorithm: number;
	readonly seedChokingAlgorithm: number;
	readonly diskIoWriteMode: number;
	readonly diskIoReadMode: number;
	readonly outgoingPort: number;
	readonly numOutgoingPorts: number;
	readonly peerDscp: number;
	readonly activeDownloads: number;
	readonly activeSeeds: number;
	readonly activeChecking: number;
	readonly activeDhtLimit: number;
	readonly activeTrackerLimit: number;
	readonly activeLsdLimit: number;
	readonly activeLimit: number;
	readonly autoManageInterval: number;
	readonly seedTimeLimit: number;
	readonly autoScrapeInterval: number;
	readonly autoScrapeMinInterval: number;
	readonly maxPeerlistSize: number;
	readonly maxPausedPeerlistSize: number;
	readonly minAnnounceInterval: number;
	readonly autoManageStartup: number;
	readonly seedingPieceQuota: number;
	readonly maxRejects: number;
	readonly recvSocketBufferSize: number;
	readonly sendSocketBufferSize: number;
	readonly maxPeerRecvBufferSize: number;
	readonly optimisticDiskRetry: number;
	readonly maxSuggestPieces: number;
	readonly localServiceAnnounceInterval: number;
	readonly dhtAnnounceInterval: number;
	readonly udpTrackerTokenExpiry: number;
	readonly numOptimisticUnchokeSlots: number;
	readonly maxPexPeers: number;
	readonly tickInterval: number;
	readonly shareModeTarget: number;
	readonly uploadRateLimit: number;
	readonly downloadRateLimit: number;
	readonly dhtUploadRateLimit: number;
	readonly unchokeSlotsLimit: number;
	readonly connectionsLimit: number;
	readonly connectionsSlack: number;
	readonly utpTargetDelay: number;
	readonly utpGainFactor: number;
	readonly utpMinTimeout: number;
	readonly utpSynResends: number;
	readonly utpFinResends: number;
	readonly utpNumResends: number;
	readonly utpConnectTimeout: number;
	readonly utpLossMultiplier: number;
	readonly mixedModeAlgorithm: number;
	readonly listenQueueSize: number;
	readonly torrentConnectBoost: number;
	readonly alertQueueSize: number;
	readonly maxMetadataSize: number;
	readonly hashingThreads: number;
	readonly checkingMemUsage: number;
	readonly predictivePieceAnnounce: number;
	readonly aioThreads: number;
	readonly trackerBackoff: number;
	readonly shareRatioLimit: number;
	readonly seedTimeRatioLimit: number;
	readonly peerTurnover: number;
	readonly peerTurnoverCutoff: number;
	readonly peerTurnoverInterval: number;
	readonly maxHttpRecvBufferSize: number;
	readonly maxRetryPortBind: number;
	readonly alertMask: number;
	readonly outEncPolicy: number;
	readonly inEncPolicy: number;
	readonly allowedEncLevel: number;
	readonly inactiveDownRate: number;
	readonly inactiveUpRate: number;
	readonly proxyType: number;
	readonly proxyPort: number;
	readonly i2pPort: number;
	readonly urlseedMaxRequestBytes: number;
	readonly webSeedNameLookupRetry: number;
	readonly closeFileInterval: number;
	readonly utpCwndReduceTimer: number;
	readonly maxWebSeedConnections: number;
	readonly resolverCacheTimeout: number;
	readonly sendNotSentLowWatermark: number;
	readonly rateChokerInitialThreshold: number;
	readonly upnpLeaseDuration: number;
	readonly maxConcurrentHttpAnnounces: number;
	readonly dhtMaxPeersReply: number;
	readonly dhtSearchBranching: number;
	readonly dhtMaxFailCount: number;
	readonly dhtMaxTorrents: number;
	readonly dhtMaxDhtItems: number;
	readonly dhtMaxPeers: number;
	readonly dhtMaxTorrentSearchReply: number;
	readonly dhtBlockTimeout: number;
	readonly dhtBlockRatelimit: number;
	readonly dhtItemLifetime: number;
	readonly dhtSampleInfohashesInterval: number;
	readonly dhtMaxInfohashesSampleCount: number;
	readonly maxPieceCount: number;
	readonly metadataTokenLimit: number;
	readonly diskWriteMode: number;
	readonly mmapFileSizeCutoff: number;
	readonly i2pInboundQuantity: number;
	readonly i2pOutboundQuantity: number;
	readonly i2pInboundLength: number;
	readonly i2pOutboundLength: number;
	readonly stringTypeBase: number;
	readonly intTypeBase: number;
	readonly boolTypeBase: number;
	readonly typeMask: number;
	readonly indexMask: number;
	readonly alwaysPwrite: number;
	readonly alwaysMmapWrite: number;
	readonly autoMmapWrite: number;
	readonly noPieceSuggestions: number;
	readonly suggestReadCache: number;
	readonly fixedSlotsChoker: number;
	readonly rateBasedChoker: number;
	readonly roundRobin: number;
	readonly fastestUpload: number;
	readonly antiLeech: number;
	readonly enableOsCache: number;
	readonly disableOsCache: number;
	readonly writeThrough: number;
	readonly preferTcp: number;
	readonly peerProportional: number;
	readonly peForced: number;
	readonly peEnabled: number;
	readonly peDisabled: number;
	readonly pePlaintext: number;
	readonly peRc4: number;
	readonly peBoth: number;
	readonly none: number;
	readonly socks4: number;
	readonly socks5: number;
	readonly socks5Pw: number;
	readonly http: number;
	readonly httpPw: number;
	// eslint-disable-next-line @typescript-eslint/naming-convention
	readonly connectSeedEveryNDownload: number;
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
	constructor(sessionParameters?: SessionParameters | SettingsPack);
}
declare class IovecT {
	iovecT: never;
	constructor(iovecT?: IovecT);
	data(): Buffer;
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
	constructor(address: Address, port: number);
	port(port: number): void;
	port(): number;
	address(address: Address): void;
	address(): Address;
}
declare class DhtState {
	dhtState: never;
	nodes: Endpoint[];
	nodes6: Endpoint[];
	constructor(dhtState?: DhtState);
}
declare class Address {
	address: never;
	constructor(address?: Address);
}
declare class DhtSampleInfohashesAlert {
	dhtSampleInfohashesAlert: never;
	constructor();
	numSamples(): number;
	samples(): Sha1Hash[];
}
declare class MetadataReceivedAlert {
	metadataReceivedAlert: never;
	handle: TorrentHandle;
	constructor();
}
declare class Sha1Hash {
	sha1Hash: never;
	constructor(sha1Hash?: Sha1Hash | Buffer);
	assign(hex: Buffer): void;
}
declare class Sha256Hash {
	sha256Hash: never;
	constructor(sha256Hash?: Sha256Hash | Buffer);
	assign(hex: Buffer): void;
}
declare class AddTorrentParameters {
	addTorrentParams: never;
	flags: TorrentFlagsT;
	infoHashes: InfoHashT;
	constructor(addTorrentParameters?: AddTorrentParameters);
}
declare class InfoHashT {
	infoHashT: never;
	v1: Sha1Hash;
	v2: Sha256Hash;
	constructor(infoHashT?: InfoHashT | Sha1Hash | Sha256Hash);
}
declare class TorrentHandle {
	torrentHandle: never;
	constructor(torrentHandle?: TorrentHandle);
	torrentFile(): TorrentInfo;
}
declare class CreateTorrent {
	createTorrent: never;
	constructor(createTorrent?: CreateTorrent);
}
declare class TorrentFlagsT {
	torrentFlagsT: never;
	constructor(torrentFlagsT?: TorrentFlagsT);
	// eslint-disable-next-line @typescript-eslint/naming-convention
	'operator|='(torrentFlagsT: TorrentFlagsT): TorrentFlagsT;
}
declare class TorrentInfo {
	torrentInfo: never;
	constructor(torrentInfo?: TorrentInfo);
	infoSection(): IovecT;
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
type TorrentFlags = {
	all: TorrentFlagsT;
	defaultDontDownload: TorrentFlagsT;
	defaultFlags: TorrentFlagsT;
	autoManaged: TorrentFlagsT;
};
type Libtorrent = {
	SettingsPack: typeof SettingsPack;
	SessionParams: typeof SessionParameters;
	Session: typeof Session;
	Sha1Hash: typeof Sha1Hash;
	Sha256Hash: typeof Sha256Hash;
	TorrentHandle: typeof TorrentHandle;
	CreateTorrent: typeof CreateTorrent;
	TorrentInfo: typeof TorrentInfo;
	Alert: typeof Alert;
	DhtSampleInfohashesAlert: typeof DhtSampleInfohashesAlert;
	MetadataReceivedAlert: typeof MetadataReceivedAlert;
	Address: typeof Address;
	InfoHashT: typeof InfoHashT;
	AddTorrentParams: typeof AddTorrentParameters;
	TorrentFlagsT: typeof TorrentFlagsT;
	IovecT: typeof IovecT;
	udp: Udp;
	dht: Dht;
	torrentFlags: TorrentFlags;
	version(): string;
	makeAddress(address: string): Address;
};
const require = createRequire(import.meta.url);
const libtorrent = require('../build/Release/libtorrent.node') as Libtorrent;

export default libtorrent;
