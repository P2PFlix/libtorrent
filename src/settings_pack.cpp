#include "main.hpp"
Libtorrent::SettingsPack::SettingsPack(const Napi::CallbackInfo &info) : Napi::ObjectWrap<SettingsPack>(info)
{
    if (info.Length() < 1)
    {
        this->settings_pack = new libtorrent::settings_pack();
    }
    else
    {
        Napi::Object settings_pack_arg = info[0].As<Napi::Object>();
        libtorrent::settings_pack *settings_pack = settings_pack_arg.Get("settingsPack").As<Napi::External<libtorrent::settings_pack>>().Data();
        this->settings_pack = new libtorrent::settings_pack(*settings_pack);
    }
}
Napi::Function Libtorrent::SettingsPack::Init(Napi::Env env)
{
    return DefineClass(env, "SettingsPack", {
                                                InstanceAccessor<&SettingsPack::GetSettingsPack, &SettingsPack::SetSettingsPack>("settingsPack"),
                                                InstanceAccessor<&SettingsPack::GetUserAgent>("userAgent"),
                                                InstanceAccessor<&SettingsPack::GetAnnounceIp>("announceIp"),
                                                InstanceAccessor<&SettingsPack::GetHandshakeClientVersion>("handshakeClientVersion"),
                                                InstanceAccessor<&SettingsPack::GetOutgoingInterfaces>("outgoingInterfaces"),
                                                InstanceAccessor<&SettingsPack::GetListenInterfaces>("listenInterfaces"),
                                                InstanceAccessor<&SettingsPack::GetProxyHostname>("proxyHostname"),
                                                InstanceAccessor<&SettingsPack::GetProxyUsername>("proxyUsername"),
                                                InstanceAccessor<&SettingsPack::GetProxyPassword>("proxyPassword"),
                                                InstanceAccessor<&SettingsPack::GetI2pHostname>("i2pHostname"),
                                                InstanceAccessor<&SettingsPack::GetPeerFingerprint>("peerFingerprint"),
                                                InstanceAccessor<&SettingsPack::GetDhtBootstrapNodes>("dhtBootstrapNodes"),
                                                InstanceAccessor<&SettingsPack::GetAllowMultipleConnectionsPerIp>("allowMultipleConnectionsPerIp"),
                                                InstanceAccessor<&SettingsPack::GetSendRedundantHave>("sendRedundantHave"),
                                                InstanceAccessor<&SettingsPack::GetUseDhtAsFallback>("useDhtAsFallback"),
                                                InstanceAccessor<&SettingsPack::GetUpnpIgnoreNonrouters>("upnpIgnoreNonrouters"),
                                                InstanceAccessor<&SettingsPack::GetUseParoleMode>("useParoleMode"),
                                                InstanceAccessor<&SettingsPack::GetAutoManagePreferSeeds>("autoManagePreferSeeds"),
                                                InstanceAccessor<&SettingsPack::GetDontCountSlowTorrents>("dontCountSlowTorrents"),
                                                InstanceAccessor<&SettingsPack::GetCloseRedundantConnections>("closeRedundantConnections"),
                                                InstanceAccessor<&SettingsPack::GetPrioritizePartialPieces>("prioritizePartialPieces"),
                                                InstanceAccessor<&SettingsPack::GetRateLimitIpOverhead>("rateLimitIpOverhead"),
                                                InstanceAccessor<&SettingsPack::GetAnnounceToAllTiers>("announceToAllTiers"),
                                                InstanceAccessor<&SettingsPack::GetAnnounceToAllTrackers>("announceToAllTrackers"),
                                                InstanceAccessor<&SettingsPack::GetPreferUdpTrackers>("preferUdpTrackers"),
                                                InstanceAccessor<&SettingsPack::GetDisableHashChecks>("disableHashChecks"),
                                                InstanceAccessor<&SettingsPack::GetAllowI2pMixed>("allowI2pMixed"),
                                                InstanceAccessor<&SettingsPack::GetNoAtimeStorage>("noAtimeStorage"),
                                                InstanceAccessor<&SettingsPack::GetIncomingStartsQueuedTorrents>("incomingStartsQueuedTorrents"),
                                                InstanceAccessor<&SettingsPack::GetReportTrueDownloaded>("reportTrueDownloaded"),
                                                InstanceAccessor<&SettingsPack::GetStrictEndGameMode>("strictEndGameMode"),
                                                InstanceAccessor<&SettingsPack::GetEnableOutgoingUtp>("enableOutgoingUtp"),
                                                InstanceAccessor<&SettingsPack::GetEnableIncomingUtp>("enableIncomingUtp"),
                                                InstanceAccessor<&SettingsPack::GetEnableOutgoingTcp>("enableOutgoingTcp"),
                                                InstanceAccessor<&SettingsPack::GetEnableIncomingTcp>("enableIncomingTcp"),
                                                InstanceAccessor<&SettingsPack::GetNoRecheckIncompleteResume>("noRecheckIncompleteResume"),
                                                InstanceAccessor<&SettingsPack::GetAnonymousMode>("anonymousMode"),
                                                InstanceAccessor<&SettingsPack::GetReportWebSeedDownloads>("reportWebSeedDownloads"),
                                                InstanceAccessor<&SettingsPack::GetSeedingOutgoingConnections>("seedingOutgoingConnections"),
                                                InstanceAccessor<&SettingsPack::GetNoConnectPrivilegedPorts>("noConnectPrivilegedPorts"),
                                                InstanceAccessor<&SettingsPack::GetSmoothConnects>("smoothConnects"),
                                                InstanceAccessor<&SettingsPack::GetAlwaysSendUserAgent>("alwaysSendUserAgent"),
                                                InstanceAccessor<&SettingsPack::GetApplyIpFilterToTrackers>("applyIpFilterToTrackers"),
                                                InstanceAccessor<&SettingsPack::GetBanWebSeeds>("banWebSeeds"),
                                                InstanceAccessor<&SettingsPack::GetSupportShareMode>("supportShareMode"),
                                                InstanceAccessor<&SettingsPack::GetReportRedundantBytes>("reportRedundantBytes"),
                                                InstanceAccessor<&SettingsPack::GetListenSystemPortFallback>("listenSystemPortFallback"),
                                                InstanceAccessor<&SettingsPack::GetAnnounceCryptoSupport>("announceCryptoSupport"),
                                                InstanceAccessor<&SettingsPack::GetEnableUpnp>("enableUpnp"),
                                                InstanceAccessor<&SettingsPack::GetEnableNatpmp>("enableNatpmp"),
                                                InstanceAccessor<&SettingsPack::GetEnableLsd>("enableLsd"),
                                                InstanceAccessor<&SettingsPack::GetEnableDht>("enableDht"),
                                                InstanceAccessor<&SettingsPack::GetPreferRc4>("preferRc4"),
                                                InstanceAccessor<&SettingsPack::GetProxyHostnames>("proxyHostnames"),
                                                InstanceAccessor<&SettingsPack::GetProxyPeerConnections>("proxyPeerConnections"),
                                                InstanceAccessor<&SettingsPack::GetAutoSequential>("autoSequential"),
                                                InstanceAccessor<&SettingsPack::GetProxyTrackerConnections>("proxyTrackerConnections"),
                                                InstanceAccessor<&SettingsPack::GetEnableIpNotifier>("enableIpNotifier"),
                                                InstanceAccessor<&SettingsPack::GetDhtPreferVerifiedNodeIds>("dhtPreferVerifiedNodeIds"),
                                                InstanceAccessor<&SettingsPack::GetDhtRestrictRoutingIps>("dhtRestrictRoutingIps"),
                                                InstanceAccessor<&SettingsPack::GetDhtRestrictSearchIps>("dhtRestrictSearchIps"),
                                                InstanceAccessor<&SettingsPack::GetDhtExtendedRoutingTable>("dhtExtendedRoutingTable"),
                                                InstanceAccessor<&SettingsPack::GetDhtAggressiveLookups>("dhtAggressiveLookups"),
                                                InstanceAccessor<&SettingsPack::GetDhtPrivacyLookups>("dhtPrivacyLookups"),
                                                InstanceAccessor<&SettingsPack::GetDhtEnforceNodeId>("dhtEnforceNodeId"),
                                                InstanceAccessor<&SettingsPack::GetDhtIgnoreDarkInternet>("dhtIgnoreDarkInternet"),
                                                InstanceAccessor<&SettingsPack::GetDhtReadOnly>("dhtReadOnly"),
                                                InstanceAccessor<&SettingsPack::GetPieceExtentAffinity>("pieceExtentAffinity"),
                                                InstanceAccessor<&SettingsPack::GetValidateHttpsTrackers>("validateHttpsTrackers"),
                                                InstanceAccessor<&SettingsPack::GetSsrfMitigation>("ssrfMitigation"),
                                                InstanceAccessor<&SettingsPack::GetAllowIdna>("allowIdna"),
                                                InstanceAccessor<&SettingsPack::GetEnableSetFileValidData>("enableSetFileValidData"),
                                                InstanceAccessor<&SettingsPack::GetSocks5UdpSendLocalEp>("socks5UdpSendLocalEp"),
                                                InstanceAccessor<&SettingsPack::GetTrackerCompletionTimeout>("trackerCompletionTimeout"),
                                                InstanceAccessor<&SettingsPack::GetTrackerReceiveTimeout>("trackerReceiveTimeout"),
                                                InstanceAccessor<&SettingsPack::GetStopTrackerTimeout>("stopTrackerTimeout"),
                                                InstanceAccessor<&SettingsPack::GetTrackerMaximumResponseLength>("trackerMaximumResponseLength"),
                                                InstanceAccessor<&SettingsPack::GetPieceTimeout>("pieceTimeout"),
                                                InstanceAccessor<&SettingsPack::GetRequestTimeout>("requestTimeout"),
                                                InstanceAccessor<&SettingsPack::GetRequestQueueTime>("requestQueueTime"),
                                                InstanceAccessor<&SettingsPack::GetMaxAllowedInRequestQueue>("maxAllowedInRequestQueue"),
                                                InstanceAccessor<&SettingsPack::GetMaxOutRequestQueue>("maxOutRequestQueue"),
                                                InstanceAccessor<&SettingsPack::GetWholePiecesThreshold>("wholePiecesThreshold"),
                                                InstanceAccessor<&SettingsPack::GetPeerTimeout>("peerTimeout"),
                                                InstanceAccessor<&SettingsPack::GetUrlseedTimeout>("urlseedTimeout"),
                                                InstanceAccessor<&SettingsPack::GetUrlseedPipelineSize>("urlseedPipelineSize"),
                                                InstanceAccessor<&SettingsPack::GetUrlseedWaitRetry>("urlseedWaitRetry"),
                                                InstanceAccessor<&SettingsPack::GetFilePoolSize>("filePoolSize"),
                                                InstanceAccessor<&SettingsPack::GetMaxFailcount>("maxFailcount"),
                                                InstanceAccessor<&SettingsPack::GetMinReconnectTime>("minReconnectTime"),
                                                InstanceAccessor<&SettingsPack::GetPeerConnectTimeout>("peerConnectTimeout"),
                                                InstanceAccessor<&SettingsPack::GetConnectionSpeed>("connectionSpeed"),
                                                InstanceAccessor<&SettingsPack::GetInactivityTimeout>("inactivityTimeout"),
                                                InstanceAccessor<&SettingsPack::GetUnchokeInterval>("unchokeInterval"),
                                                InstanceAccessor<&SettingsPack::GetOptimisticUnchokeInterval>("optimisticUnchokeInterval"),
                                                InstanceAccessor<&SettingsPack::GetNumWant>("numWant"),
                                                InstanceAccessor<&SettingsPack::GetInitialPickerThreshold>("initialPickerThreshold"),
                                                InstanceAccessor<&SettingsPack::GetAllowedFastSetSize>("allowedFastSetSize"),
                                                InstanceAccessor<&SettingsPack::GetSuggestMode>("suggestMode"),
                                                InstanceAccessor<&SettingsPack::GetMaxQueuedDiskBytes>("maxQueuedDiskBytes"),
                                                InstanceAccessor<&SettingsPack::GetHandshakeTimeout>("handshakeTimeout"),
                                                InstanceAccessor<&SettingsPack::GetSendBufferLowWatermark>("sendBufferLowWatermark"),
                                                InstanceAccessor<&SettingsPack::GetSendBufferWatermark>("sendBufferWatermark"),
                                                InstanceAccessor<&SettingsPack::GetSendBufferWatermarkFactor>("sendBufferWatermarkFactor"),
                                                InstanceAccessor<&SettingsPack::GetChokingAlgorithm>("chokingAlgorithm"),
                                                InstanceAccessor<&SettingsPack::GetSeedChokingAlgorithm>("seedChokingAlgorithm"),
                                                InstanceAccessor<&SettingsPack::GetDiskIoWriteMode>("diskIoWriteMode"),
                                                InstanceAccessor<&SettingsPack::GetDiskIoReadMode>("diskIoReadMode"),
                                                InstanceAccessor<&SettingsPack::GetOutgoingPort>("outgoingPort"),
                                                InstanceAccessor<&SettingsPack::GetNumOutgoingPorts>("numOutgoingPorts"),
                                                InstanceAccessor<&SettingsPack::GetPeerDscp>("peerDscp"),
                                                InstanceAccessor<&SettingsPack::GetActiveDownloads>("activeDownloads"),
                                                InstanceAccessor<&SettingsPack::GetActiveSeeds>("activeSeeds"),
                                                InstanceAccessor<&SettingsPack::GetActiveChecking>("activeChecking"),
                                                InstanceAccessor<&SettingsPack::GetActiveDhtLimit>("activeDhtLimit"),
                                                InstanceAccessor<&SettingsPack::GetActiveTrackerLimit>("activeTrackerLimit"),
                                                InstanceAccessor<&SettingsPack::GetActiveLsdLimit>("activeLsdLimit"),
                                                InstanceAccessor<&SettingsPack::GetActiveLimit>("activeLimit"),
                                                InstanceAccessor<&SettingsPack::GetAutoManageInterval>("autoManageInterval"),
                                                InstanceAccessor<&SettingsPack::GetSeedTimeLimit>("seedTimeLimit"),
                                                InstanceAccessor<&SettingsPack::GetAutoScrapeInterval>("autoScrapeInterval"),
                                                InstanceAccessor<&SettingsPack::GetAutoScrapeMinInterval>("autoScrapeMinInterval"),
                                                InstanceAccessor<&SettingsPack::GetMaxPeerlistSize>("maxPeerlistSize"),
                                                InstanceAccessor<&SettingsPack::GetMaxPausedPeerlistSize>("maxPausedPeerlistSize"),
                                                InstanceAccessor<&SettingsPack::GetMinAnnounceInterval>("minAnnounceInterval"),
                                                InstanceAccessor<&SettingsPack::GetAutoManageStartup>("autoManageStartup"),
                                                InstanceAccessor<&SettingsPack::GetSeedingPieceQuota>("seedingPieceQuota"),
                                                InstanceAccessor<&SettingsPack::GetMaxRejects>("maxRejects"),
                                                InstanceAccessor<&SettingsPack::GetRecvSocketBufferSize>("recvSocketBufferSize"),
                                                InstanceAccessor<&SettingsPack::GetSendSocketBufferSize>("sendSocketBufferSize"),
                                                InstanceAccessor<&SettingsPack::GetMaxPeerRecvBufferSize>("maxPeerRecvBufferSize"),
                                                InstanceAccessor<&SettingsPack::GetOptimisticDiskRetry>("optimisticDiskRetry"),
                                                InstanceAccessor<&SettingsPack::GetMaxSuggestPieces>("maxSuggestPieces"),
                                                InstanceAccessor<&SettingsPack::GetLocalServiceAnnounceInterval>("localServiceAnnounceInterval"),
                                                InstanceAccessor<&SettingsPack::GetDhtAnnounceInterval>("dhtAnnounceInterval"),
                                                InstanceAccessor<&SettingsPack::GetUdpTrackerTokenExpiry>("udpTrackerTokenExpiry"),
                                                InstanceAccessor<&SettingsPack::GetNumOptimisticUnchokeSlots>("numOptimisticUnchokeSlots"),
                                                InstanceAccessor<&SettingsPack::GetMaxPexPeers>("maxPexPeers"),
                                                InstanceAccessor<&SettingsPack::GetTickInterval>("tickInterval"),
                                                InstanceAccessor<&SettingsPack::GetShareModeTarget>("shareModeTarget"),
                                                InstanceAccessor<&SettingsPack::GetUploadRateLimit>("uploadRateLimit"),
                                                InstanceAccessor<&SettingsPack::GetDownloadRateLimit>("downloadRateLimit"),
                                                InstanceAccessor<&SettingsPack::GetDhtUploadRateLimit>("dhtUploadRateLimit"),
                                                InstanceAccessor<&SettingsPack::GetUnchokeSlotsLimit>("unchokeSlotsLimit"),
                                                InstanceAccessor<&SettingsPack::GetConnectionsLimit>("connectionsLimit"),
                                                InstanceAccessor<&SettingsPack::GetConnectionsSlack>("connectionsSlack"),
                                                InstanceAccessor<&SettingsPack::GetUtpTargetDelay>("utpTargetDelay"),
                                                InstanceAccessor<&SettingsPack::GetUtpGainFactor>("utpGainFactor"),
                                                InstanceAccessor<&SettingsPack::GetUtpMinTimeout>("utpMinTimeout"),
                                                InstanceAccessor<&SettingsPack::GetUtpSynResends>("utpSynResends"),
                                                InstanceAccessor<&SettingsPack::GetUtpFinResends>("utpFinResends"),
                                                InstanceAccessor<&SettingsPack::GetUtpNumResends>("utpNumResends"),
                                                InstanceAccessor<&SettingsPack::GetUtpConnectTimeout>("utpConnectTimeout"),
                                                InstanceAccessor<&SettingsPack::GetUtpLossMultiplier>("utpLossMultiplier"),
                                                InstanceAccessor<&SettingsPack::GetMixedModeAlgorithm>("mixedModeAlgorithm"),
                                                InstanceAccessor<&SettingsPack::GetListenQueueSize>("listenQueueSize"),
                                                InstanceAccessor<&SettingsPack::GetTorrentConnectBoost>("torrentConnectBoost"),
                                                InstanceAccessor<&SettingsPack::GetAlertQueueSize>("alertQueueSize"),
                                                InstanceAccessor<&SettingsPack::GetMaxMetadataSize>("maxMetadataSize"),
                                                InstanceAccessor<&SettingsPack::GetHashingThreads>("hashingThreads"),
                                                InstanceAccessor<&SettingsPack::GetCheckingMemUsage>("checkingMemUsage"),
                                                InstanceAccessor<&SettingsPack::GetPredictivePieceAnnounce>("predictivePieceAnnounce"),
                                                InstanceAccessor<&SettingsPack::GetAioThreads>("aioThreads"),
                                                InstanceAccessor<&SettingsPack::GetTrackerBackoff>("trackerBackoff"),
                                                InstanceAccessor<&SettingsPack::GetShareRatioLimit>("shareRatioLimit"),
                                                InstanceAccessor<&SettingsPack::GetSeedTimeRatioLimit>("seedTimeRatioLimit"),
                                                InstanceAccessor<&SettingsPack::GetPeerTurnover>("peerTurnover"),
                                                InstanceAccessor<&SettingsPack::GetPeerTurnoverCutoff>("peerTurnoverCutoff"),
                                                InstanceAccessor<&SettingsPack::GetPeerTurnoverInterval>("peerTurnoverInterval"),
                                                InstanceAccessor<&SettingsPack::GetMaxHttpRecvBufferSize>("maxHttpRecvBufferSize"),
                                                InstanceAccessor<&SettingsPack::GetMaxRetryPortBind>("maxRetryPortBind"),
                                                InstanceAccessor<&SettingsPack::GetAlertMask>("alertMask"),
                                                InstanceAccessor<&SettingsPack::GetOutEncPolicy>("outEncPolicy"),
                                                InstanceAccessor<&SettingsPack::GetInEncPolicy>("inEncPolicy"),
                                                InstanceAccessor<&SettingsPack::GetAllowedEncLevel>("allowedEncLevel"),
                                                InstanceAccessor<&SettingsPack::GetInactiveDownRate>("inactiveDownRate"),
                                                InstanceAccessor<&SettingsPack::GetInactiveUpRate>("inactiveUpRate"),
                                                InstanceAccessor<&SettingsPack::GetProxyType>("proxyType"),
                                                InstanceAccessor<&SettingsPack::GetProxyPort>("proxyPort"),
                                                InstanceAccessor<&SettingsPack::GetI2pPort>("i2pPort"),
                                                InstanceAccessor<&SettingsPack::GetUrlseedMaxRequestBytes>("urlseedMaxRequestBytes"),
                                                InstanceAccessor<&SettingsPack::GetWebSeedNameLookupRetry>("webSeedNameLookupRetry"),
                                                InstanceAccessor<&SettingsPack::GetCloseFileInterval>("closeFileInterval"),
                                                InstanceAccessor<&SettingsPack::GetUtpCwndReduceTimer>("utpCwndReduceTimer"),
                                                InstanceAccessor<&SettingsPack::GetMaxWebSeedConnections>("maxWebSeedConnections"),
                                                InstanceAccessor<&SettingsPack::GetResolverCacheTimeout>("resolverCacheTimeout"),
                                                InstanceAccessor<&SettingsPack::GetSendNotSentLowWatermark>("sendNotSentLowWatermark"),
                                                InstanceAccessor<&SettingsPack::GetRateChokerInitialThreshold>("rateChokerInitialThreshold"),
                                                InstanceAccessor<&SettingsPack::GetUpnpLeaseDuration>("upnpLeaseDuration"),
                                                InstanceAccessor<&SettingsPack::GetMaxConcurrentHttpAnnounces>("maxConcurrentHttpAnnounces"),
                                                InstanceAccessor<&SettingsPack::GetDhtMaxPeersReply>("dhtMaxPeersReply"),
                                                InstanceAccessor<&SettingsPack::GetDhtSearchBranching>("dhtSearchBranching"),
                                                InstanceAccessor<&SettingsPack::GetDhtMaxFailCount>("dhtMaxFailCount"),
                                                InstanceAccessor<&SettingsPack::GetDhtMaxTorrents>("dhtMaxTorrents"),
                                                InstanceAccessor<&SettingsPack::GetDhtMaxDhtItems>("dhtMaxDhtItems"),
                                                InstanceAccessor<&SettingsPack::GetDhtMaxPeers>("dhtMaxPeers"),
                                                InstanceAccessor<&SettingsPack::GetDhtMaxTorrentSearchReply>("dhtMaxTorrentSearchReply"),
                                                InstanceAccessor<&SettingsPack::GetDhtBlockTimeout>("dhtBlockTimeout"),
                                                InstanceAccessor<&SettingsPack::GetDhtBlockRatelimit>("dhtBlockRatelimit"),
                                                InstanceAccessor<&SettingsPack::GetDhtItemLifetime>("dhtItemLifetime"),
                                                InstanceAccessor<&SettingsPack::GetDhtSampleInfohashesInterval>("dhtSampleInfohashesInterval"),
                                                InstanceAccessor<&SettingsPack::GetDhtMaxInfohashesSampleCount>("dhtMaxInfohashesSampleCount"),
                                                InstanceAccessor<&SettingsPack::GetMaxPieceCount>("maxPieceCount"),
                                                InstanceAccessor<&SettingsPack::GetMetadataTokenLimit>("metadataTokenLimit"),
                                                InstanceAccessor<&SettingsPack::GetDiskWriteMode>("diskWriteMode"),
                                                InstanceAccessor<&SettingsPack::GetMmapFileSizeCutoff>("mmapFileSizeCutoff"),
                                                InstanceAccessor<&SettingsPack::GetI2pInboundQuantity>("i2pInboundQuantity"),
                                                InstanceAccessor<&SettingsPack::GetI2pOutboundQuantity>("i2pOutboundQuantity"),
                                                InstanceAccessor<&SettingsPack::GetI2pInboundLength>("i2pInboundLength"),
                                                InstanceAccessor<&SettingsPack::GetI2pOutboundLength>("i2pOutboundLength"),
                                                InstanceAccessor<&SettingsPack::GetStringTypeBase>("stringTypeBase"),
                                                InstanceAccessor<&SettingsPack::GetIntTypeBase>("intTypeBase"),
                                                InstanceAccessor<&SettingsPack::GetBoolTypeBase>("boolTypeBase"),
                                                InstanceAccessor<&SettingsPack::GetTypeMask>("typeMask"),
                                                InstanceAccessor<&SettingsPack::GetIndexMask>("indexMask"),
                                                InstanceAccessor<&SettingsPack::GetAlwaysPwrite>("alwaysPwrite"),
                                                InstanceAccessor<&SettingsPack::GetAlwaysMmapWrite>("alwaysMmapWrite"),
                                                InstanceAccessor<&SettingsPack::GetAutoMmapWrite>("autoMmapWrite"),
                                                InstanceAccessor<&SettingsPack::GetNoPieceSuggestions>("noPieceSuggestions"),
                                                InstanceAccessor<&SettingsPack::GetSuggestReadCache>("suggestReadCache"),
                                                InstanceAccessor<&SettingsPack::GetFixedSlotsChoker>("fixedSlotsChoker"),
                                                InstanceAccessor<&SettingsPack::GetRateBasedChoker>("rateBasedChoker"),
                                                InstanceAccessor<&SettingsPack::GetRoundRobin>("roundRobin"),
                                                InstanceAccessor<&SettingsPack::GetFastestUpload>("fastestUpload"),
                                                InstanceAccessor<&SettingsPack::GetAntiLeech>("antiLeech"),
                                                InstanceAccessor<&SettingsPack::GetEnableOsCache>("enableOsCache"),
                                                InstanceAccessor<&SettingsPack::GetDisableOsCache>("disableOsCache"),
                                                InstanceAccessor<&SettingsPack::GetWriteThrough>("writeThrough"),
                                                InstanceAccessor<&SettingsPack::GetPreferTcp>("preferTcp"),
                                                InstanceAccessor<&SettingsPack::GetPeerProportional>("peerProportional"),
                                                InstanceAccessor<&SettingsPack::GetPeForced>("peForced"),
                                                InstanceAccessor<&SettingsPack::GetPeEnabled>("peEnabled"),
                                                InstanceAccessor<&SettingsPack::GetPeDisabled>("peDisabled"),
                                                InstanceAccessor<&SettingsPack::GetPePlaintext>("pePlaintext"),
                                                InstanceAccessor<&SettingsPack::GetPeRc4>("peRc4"),
                                                InstanceAccessor<&SettingsPack::GetPeBoth>("peBoth"),
                                                InstanceAccessor<&SettingsPack::GetNone>("none"),
                                                InstanceAccessor<&SettingsPack::GetSocks4>("socks4"),
                                                InstanceAccessor<&SettingsPack::GetSocks5>("socks5"),
                                                InstanceAccessor<&SettingsPack::GetSocks5Pw>("socks5Pw"),
                                                InstanceAccessor<&SettingsPack::GetHttp>("http"),
                                                InstanceAccessor<&SettingsPack::GetHttpPw>("httpPw"),
                                                InstanceAccessor<&SettingsPack::GetConnectSeedEveryNDownload>("connectSeedEveryNDownload"),
                                                InstanceMethod<&SettingsPack::SetStr>("setStr"),
                                                InstanceMethod<&SettingsPack::SetInt>("setInt"),
                                                InstanceMethod<&SettingsPack::SetBool>("setBool"),
                                                InstanceMethod<&SettingsPack::GetStr>("getStr"),
                                                InstanceMethod<&SettingsPack::GetInt>("getInt"),
                                                InstanceMethod<&SettingsPack::GetBool>("getBool"),
                                                InstanceMethod<&SettingsPack::HasVal>("hasVal"),
                                                InstanceMethod<&SettingsPack::Clear>("clear"),
                                            });
}
Napi::Value Libtorrent::SettingsPack::GetSettingsPack(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::External<libtorrent::settings_pack>::New(env, this->settings_pack);
}
void Libtorrent::SettingsPack::SetSettingsPack(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    libtorrent::settings_pack *settings_pack = value.As<Napi::External<libtorrent::settings_pack>>().Data();
    this->settings_pack = settings_pack;
}
Napi::Value Libtorrent::SettingsPack::GetUserAgent(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->user_agent);
}
Napi::Value Libtorrent::SettingsPack::GetAnnounceIp(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->announce_ip);
}
Napi::Value Libtorrent::SettingsPack::GetHandshakeClientVersion(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->handshake_client_version);
}
Napi::Value Libtorrent::SettingsPack::GetOutgoingInterfaces(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->outgoing_interfaces);
}
Napi::Value Libtorrent::SettingsPack::GetListenInterfaces(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->listen_interfaces);
}
Napi::Value Libtorrent::SettingsPack::GetProxyHostname(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->proxy_hostname);
}
Napi::Value Libtorrent::SettingsPack::GetProxyUsername(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->proxy_username);
}
Napi::Value Libtorrent::SettingsPack::GetProxyPassword(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->proxy_password);
}
Napi::Value Libtorrent::SettingsPack::GetI2pHostname(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->i2p_hostname);
}
Napi::Value Libtorrent::SettingsPack::GetPeerFingerprint(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->peer_fingerprint);
}
Napi::Value Libtorrent::SettingsPack::GetDhtBootstrapNodes(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_bootstrap_nodes);
}
Napi::Value Libtorrent::SettingsPack::GetAllowMultipleConnectionsPerIp(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->allow_multiple_connections_per_ip);
}
Napi::Value Libtorrent::SettingsPack::GetSendRedundantHave(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->send_redundant_have);
}
Napi::Value Libtorrent::SettingsPack::GetUseDhtAsFallback(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->use_dht_as_fallback);
}
Napi::Value Libtorrent::SettingsPack::GetUpnpIgnoreNonrouters(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->upnp_ignore_nonrouters);
}
Napi::Value Libtorrent::SettingsPack::GetUseParoleMode(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->use_parole_mode);
}
Napi::Value Libtorrent::SettingsPack::GetAutoManagePreferSeeds(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->auto_manage_prefer_seeds);
}
Napi::Value Libtorrent::SettingsPack::GetDontCountSlowTorrents(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dont_count_slow_torrents);
}
Napi::Value Libtorrent::SettingsPack::GetCloseRedundantConnections(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->close_redundant_connections);
}
Napi::Value Libtorrent::SettingsPack::GetPrioritizePartialPieces(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->prioritize_partial_pieces);
}
Napi::Value Libtorrent::SettingsPack::GetRateLimitIpOverhead(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->rate_limit_ip_overhead);
}
Napi::Value Libtorrent::SettingsPack::GetAnnounceToAllTiers(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->announce_to_all_tiers);
}
Napi::Value Libtorrent::SettingsPack::GetAnnounceToAllTrackers(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->announce_to_all_trackers);
}
Napi::Value Libtorrent::SettingsPack::GetPreferUdpTrackers(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->prefer_udp_trackers);
}
Napi::Value Libtorrent::SettingsPack::GetDisableHashChecks(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->disable_hash_checks);
}
Napi::Value Libtorrent::SettingsPack::GetAllowI2pMixed(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->allow_i2p_mixed);
}
Napi::Value Libtorrent::SettingsPack::GetNoAtimeStorage(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->no_atime_storage);
}
Napi::Value Libtorrent::SettingsPack::GetIncomingStartsQueuedTorrents(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->incoming_starts_queued_torrents);
}
Napi::Value Libtorrent::SettingsPack::GetReportTrueDownloaded(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->report_true_downloaded);
}
Napi::Value Libtorrent::SettingsPack::GetStrictEndGameMode(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->strict_end_game_mode);
}
Napi::Value Libtorrent::SettingsPack::GetEnableOutgoingUtp(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->enable_outgoing_utp);
}
Napi::Value Libtorrent::SettingsPack::GetEnableIncomingUtp(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->enable_incoming_utp);
}
Napi::Value Libtorrent::SettingsPack::GetEnableOutgoingTcp(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->enable_outgoing_tcp);
}
Napi::Value Libtorrent::SettingsPack::GetEnableIncomingTcp(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->enable_incoming_tcp);
}
Napi::Value Libtorrent::SettingsPack::GetNoRecheckIncompleteResume(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->no_recheck_incomplete_resume);
}
Napi::Value Libtorrent::SettingsPack::GetAnonymousMode(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->anonymous_mode);
}
Napi::Value Libtorrent::SettingsPack::GetReportWebSeedDownloads(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->report_web_seed_downloads);
}
Napi::Value Libtorrent::SettingsPack::GetSeedingOutgoingConnections(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->seeding_outgoing_connections);
}
Napi::Value Libtorrent::SettingsPack::GetNoConnectPrivilegedPorts(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->no_connect_privileged_ports);
}
Napi::Value Libtorrent::SettingsPack::GetSmoothConnects(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->smooth_connects);
}
Napi::Value Libtorrent::SettingsPack::GetAlwaysSendUserAgent(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->always_send_user_agent);
}
Napi::Value Libtorrent::SettingsPack::GetApplyIpFilterToTrackers(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->apply_ip_filter_to_trackers);
}
Napi::Value Libtorrent::SettingsPack::GetBanWebSeeds(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->ban_web_seeds);
}
Napi::Value Libtorrent::SettingsPack::GetSupportShareMode(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->support_share_mode);
}
Napi::Value Libtorrent::SettingsPack::GetReportRedundantBytes(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->report_redundant_bytes);
}
Napi::Value Libtorrent::SettingsPack::GetListenSystemPortFallback(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->listen_system_port_fallback);
}
Napi::Value Libtorrent::SettingsPack::GetAnnounceCryptoSupport(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->announce_crypto_support);
}
Napi::Value Libtorrent::SettingsPack::GetEnableUpnp(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->enable_upnp);
}
Napi::Value Libtorrent::SettingsPack::GetEnableNatpmp(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->enable_natpmp);
}
Napi::Value Libtorrent::SettingsPack::GetEnableLsd(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->enable_lsd);
}
Napi::Value Libtorrent::SettingsPack::GetEnableDht(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->enable_dht);
}
Napi::Value Libtorrent::SettingsPack::GetPreferRc4(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->prefer_rc4);
}
Napi::Value Libtorrent::SettingsPack::GetProxyHostnames(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->proxy_hostnames);
}
Napi::Value Libtorrent::SettingsPack::GetProxyPeerConnections(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->proxy_peer_connections);
}
Napi::Value Libtorrent::SettingsPack::GetAutoSequential(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->auto_sequential);
}
Napi::Value Libtorrent::SettingsPack::GetProxyTrackerConnections(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->proxy_tracker_connections);
}
Napi::Value Libtorrent::SettingsPack::GetEnableIpNotifier(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->enable_ip_notifier);
}
Napi::Value Libtorrent::SettingsPack::GetDhtPreferVerifiedNodeIds(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_prefer_verified_node_ids);
}
Napi::Value Libtorrent::SettingsPack::GetDhtRestrictRoutingIps(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_restrict_routing_ips);
}
Napi::Value Libtorrent::SettingsPack::GetDhtRestrictSearchIps(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_restrict_search_ips);
}
Napi::Value Libtorrent::SettingsPack::GetDhtExtendedRoutingTable(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_extended_routing_table);
}
Napi::Value Libtorrent::SettingsPack::GetDhtAggressiveLookups(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_aggressive_lookups);
}
Napi::Value Libtorrent::SettingsPack::GetDhtPrivacyLookups(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_privacy_lookups);
}
Napi::Value Libtorrent::SettingsPack::GetDhtEnforceNodeId(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_enforce_node_id);
}
Napi::Value Libtorrent::SettingsPack::GetDhtIgnoreDarkInternet(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_ignore_dark_internet);
}
Napi::Value Libtorrent::SettingsPack::GetDhtReadOnly(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_read_only);
}
Napi::Value Libtorrent::SettingsPack::GetPieceExtentAffinity(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->piece_extent_affinity);
}
Napi::Value Libtorrent::SettingsPack::GetValidateHttpsTrackers(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->validate_https_trackers);
}
Napi::Value Libtorrent::SettingsPack::GetSsrfMitigation(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->ssrf_mitigation);
}
Napi::Value Libtorrent::SettingsPack::GetAllowIdna(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->allow_idna);
}
Napi::Value Libtorrent::SettingsPack::GetEnableSetFileValidData(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->enable_set_file_valid_data);
}
Napi::Value Libtorrent::SettingsPack::GetSocks5UdpSendLocalEp(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->socks5_udp_send_local_ep);
}
Napi::Value Libtorrent::SettingsPack::GetTrackerCompletionTimeout(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->tracker_completion_timeout);
}
Napi::Value Libtorrent::SettingsPack::GetTrackerReceiveTimeout(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->tracker_receive_timeout);
}
Napi::Value Libtorrent::SettingsPack::GetStopTrackerTimeout(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->stop_tracker_timeout);
}
Napi::Value Libtorrent::SettingsPack::GetTrackerMaximumResponseLength(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->tracker_maximum_response_length);
}
Napi::Value Libtorrent::SettingsPack::GetPieceTimeout(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->piece_timeout);
}
Napi::Value Libtorrent::SettingsPack::GetRequestTimeout(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->request_timeout);
}
Napi::Value Libtorrent::SettingsPack::GetRequestQueueTime(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->request_queue_time);
}
Napi::Value Libtorrent::SettingsPack::GetMaxAllowedInRequestQueue(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->max_allowed_in_request_queue);
}
Napi::Value Libtorrent::SettingsPack::GetMaxOutRequestQueue(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->max_out_request_queue);
}
Napi::Value Libtorrent::SettingsPack::GetWholePiecesThreshold(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->whole_pieces_threshold);
}
Napi::Value Libtorrent::SettingsPack::GetPeerTimeout(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->peer_timeout);
}
Napi::Value Libtorrent::SettingsPack::GetUrlseedTimeout(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->urlseed_timeout);
}
Napi::Value Libtorrent::SettingsPack::GetUrlseedPipelineSize(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->urlseed_pipeline_size);
}
Napi::Value Libtorrent::SettingsPack::GetUrlseedWaitRetry(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->urlseed_wait_retry);
}
Napi::Value Libtorrent::SettingsPack::GetFilePoolSize(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->file_pool_size);
}
Napi::Value Libtorrent::SettingsPack::GetMaxFailcount(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->max_failcount);
}
Napi::Value Libtorrent::SettingsPack::GetMinReconnectTime(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->min_reconnect_time);
}
Napi::Value Libtorrent::SettingsPack::GetPeerConnectTimeout(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->peer_connect_timeout);
}
Napi::Value Libtorrent::SettingsPack::GetConnectionSpeed(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->connection_speed);
}
Napi::Value Libtorrent::SettingsPack::GetInactivityTimeout(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->inactivity_timeout);
}
Napi::Value Libtorrent::SettingsPack::GetUnchokeInterval(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->unchoke_interval);
}
Napi::Value Libtorrent::SettingsPack::GetOptimisticUnchokeInterval(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->optimistic_unchoke_interval);
}
Napi::Value Libtorrent::SettingsPack::GetNumWant(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->num_want);
}
Napi::Value Libtorrent::SettingsPack::GetInitialPickerThreshold(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->initial_picker_threshold);
}
Napi::Value Libtorrent::SettingsPack::GetAllowedFastSetSize(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->allowed_fast_set_size);
}
Napi::Value Libtorrent::SettingsPack::GetSuggestMode(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->suggest_mode);
}
Napi::Value Libtorrent::SettingsPack::GetMaxQueuedDiskBytes(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->max_queued_disk_bytes);
}
Napi::Value Libtorrent::SettingsPack::GetHandshakeTimeout(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->handshake_timeout);
}
Napi::Value Libtorrent::SettingsPack::GetSendBufferLowWatermark(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->send_buffer_low_watermark);
}
Napi::Value Libtorrent::SettingsPack::GetSendBufferWatermark(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->send_buffer_watermark);
}
Napi::Value Libtorrent::SettingsPack::GetSendBufferWatermarkFactor(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->send_buffer_watermark_factor);
}
Napi::Value Libtorrent::SettingsPack::GetChokingAlgorithm(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->choking_algorithm);
}
Napi::Value Libtorrent::SettingsPack::GetSeedChokingAlgorithm(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->seed_choking_algorithm);
}
Napi::Value Libtorrent::SettingsPack::GetDiskIoWriteMode(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->disk_io_write_mode);
}
Napi::Value Libtorrent::SettingsPack::GetDiskIoReadMode(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->disk_io_read_mode);
}
Napi::Value Libtorrent::SettingsPack::GetOutgoingPort(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->outgoing_port);
}
Napi::Value Libtorrent::SettingsPack::GetNumOutgoingPorts(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->num_outgoing_ports);
}
Napi::Value Libtorrent::SettingsPack::GetPeerDscp(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->peer_dscp);
}
Napi::Value Libtorrent::SettingsPack::GetActiveDownloads(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->active_downloads);
}
Napi::Value Libtorrent::SettingsPack::GetActiveSeeds(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->active_seeds);
}
Napi::Value Libtorrent::SettingsPack::GetActiveChecking(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->active_checking);
}
Napi::Value Libtorrent::SettingsPack::GetActiveDhtLimit(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->active_dht_limit);
}
Napi::Value Libtorrent::SettingsPack::GetActiveTrackerLimit(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->active_tracker_limit);
}
Napi::Value Libtorrent::SettingsPack::GetActiveLsdLimit(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->active_lsd_limit);
}
Napi::Value Libtorrent::SettingsPack::GetActiveLimit(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->active_limit);
}
Napi::Value Libtorrent::SettingsPack::GetAutoManageInterval(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->auto_manage_interval);
}
Napi::Value Libtorrent::SettingsPack::GetSeedTimeLimit(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->seed_time_limit);
}
Napi::Value Libtorrent::SettingsPack::GetAutoScrapeInterval(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->auto_scrape_interval);
}
Napi::Value Libtorrent::SettingsPack::GetAutoScrapeMinInterval(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->auto_scrape_min_interval);
}
Napi::Value Libtorrent::SettingsPack::GetMaxPeerlistSize(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->max_peerlist_size);
}
Napi::Value Libtorrent::SettingsPack::GetMaxPausedPeerlistSize(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->max_paused_peerlist_size);
}
Napi::Value Libtorrent::SettingsPack::GetMinAnnounceInterval(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->min_announce_interval);
}
Napi::Value Libtorrent::SettingsPack::GetAutoManageStartup(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->auto_manage_startup);
}
Napi::Value Libtorrent::SettingsPack::GetSeedingPieceQuota(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->seeding_piece_quota);
}
Napi::Value Libtorrent::SettingsPack::GetMaxRejects(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->max_rejects);
}
Napi::Value Libtorrent::SettingsPack::GetRecvSocketBufferSize(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->recv_socket_buffer_size);
}
Napi::Value Libtorrent::SettingsPack::GetSendSocketBufferSize(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->send_socket_buffer_size);
}
Napi::Value Libtorrent::SettingsPack::GetMaxPeerRecvBufferSize(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->max_peer_recv_buffer_size);
}
Napi::Value Libtorrent::SettingsPack::GetOptimisticDiskRetry(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->optimistic_disk_retry);
}
Napi::Value Libtorrent::SettingsPack::GetMaxSuggestPieces(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->max_suggest_pieces);
}
Napi::Value Libtorrent::SettingsPack::GetLocalServiceAnnounceInterval(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->local_service_announce_interval);
}
Napi::Value Libtorrent::SettingsPack::GetDhtAnnounceInterval(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_announce_interval);
}
Napi::Value Libtorrent::SettingsPack::GetUdpTrackerTokenExpiry(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->udp_tracker_token_expiry);
}
Napi::Value Libtorrent::SettingsPack::GetNumOptimisticUnchokeSlots(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->num_optimistic_unchoke_slots);
}
Napi::Value Libtorrent::SettingsPack::GetMaxPexPeers(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->max_pex_peers);
}
Napi::Value Libtorrent::SettingsPack::GetTickInterval(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->tick_interval);
}
Napi::Value Libtorrent::SettingsPack::GetShareModeTarget(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->share_mode_target);
}
Napi::Value Libtorrent::SettingsPack::GetUploadRateLimit(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->upload_rate_limit);
}
Napi::Value Libtorrent::SettingsPack::GetDownloadRateLimit(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->download_rate_limit);
}
Napi::Value Libtorrent::SettingsPack::GetDhtUploadRateLimit(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_upload_rate_limit);
}
Napi::Value Libtorrent::SettingsPack::GetUnchokeSlotsLimit(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->unchoke_slots_limit);
}
Napi::Value Libtorrent::SettingsPack::GetConnectionsLimit(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->connections_limit);
}
Napi::Value Libtorrent::SettingsPack::GetConnectionsSlack(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->connections_slack);
}
Napi::Value Libtorrent::SettingsPack::GetUtpTargetDelay(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->utp_target_delay);
}
Napi::Value Libtorrent::SettingsPack::GetUtpGainFactor(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->utp_gain_factor);
}
Napi::Value Libtorrent::SettingsPack::GetUtpMinTimeout(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->utp_min_timeout);
}
Napi::Value Libtorrent::SettingsPack::GetUtpSynResends(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->utp_syn_resends);
}
Napi::Value Libtorrent::SettingsPack::GetUtpFinResends(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->utp_fin_resends);
}
Napi::Value Libtorrent::SettingsPack::GetUtpNumResends(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->utp_num_resends);
}
Napi::Value Libtorrent::SettingsPack::GetUtpConnectTimeout(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->utp_connect_timeout);
}
Napi::Value Libtorrent::SettingsPack::GetUtpLossMultiplier(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->utp_loss_multiplier);
}
Napi::Value Libtorrent::SettingsPack::GetMixedModeAlgorithm(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->mixed_mode_algorithm);
}
Napi::Value Libtorrent::SettingsPack::GetListenQueueSize(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->listen_queue_size);
}
Napi::Value Libtorrent::SettingsPack::GetTorrentConnectBoost(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->torrent_connect_boost);
}
Napi::Value Libtorrent::SettingsPack::GetAlertQueueSize(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->alert_queue_size);
}
Napi::Value Libtorrent::SettingsPack::GetMaxMetadataSize(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->max_metadata_size);
}
Napi::Value Libtorrent::SettingsPack::GetHashingThreads(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->hashing_threads);
}
Napi::Value Libtorrent::SettingsPack::GetCheckingMemUsage(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->checking_mem_usage);
}
Napi::Value Libtorrent::SettingsPack::GetPredictivePieceAnnounce(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->predictive_piece_announce);
}
Napi::Value Libtorrent::SettingsPack::GetAioThreads(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->aio_threads);
}
Napi::Value Libtorrent::SettingsPack::GetTrackerBackoff(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->tracker_backoff);
}
Napi::Value Libtorrent::SettingsPack::GetShareRatioLimit(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->share_ratio_limit);
}
Napi::Value Libtorrent::SettingsPack::GetSeedTimeRatioLimit(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->seed_time_ratio_limit);
}
Napi::Value Libtorrent::SettingsPack::GetPeerTurnover(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->peer_turnover);
}
Napi::Value Libtorrent::SettingsPack::GetPeerTurnoverCutoff(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->peer_turnover_cutoff);
}
Napi::Value Libtorrent::SettingsPack::GetPeerTurnoverInterval(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->peer_turnover_interval);
}
Napi::Value Libtorrent::SettingsPack::GetMaxHttpRecvBufferSize(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->max_http_recv_buffer_size);
}
Napi::Value Libtorrent::SettingsPack::GetMaxRetryPortBind(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->max_retry_port_bind);
}
Napi::Value Libtorrent::SettingsPack::GetAlertMask(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->alert_mask);
}
Napi::Value Libtorrent::SettingsPack::GetOutEncPolicy(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->out_enc_policy);
}
Napi::Value Libtorrent::SettingsPack::GetInEncPolicy(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->in_enc_policy);
}
Napi::Value Libtorrent::SettingsPack::GetAllowedEncLevel(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->allowed_enc_level);
}
Napi::Value Libtorrent::SettingsPack::GetInactiveDownRate(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->inactive_down_rate);
}
Napi::Value Libtorrent::SettingsPack::GetInactiveUpRate(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->inactive_up_rate);
}
Napi::Value Libtorrent::SettingsPack::GetProxyType(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->proxy_type);
}
Napi::Value Libtorrent::SettingsPack::GetProxyPort(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->proxy_port);
}
Napi::Value Libtorrent::SettingsPack::GetI2pPort(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->i2p_port);
}
Napi::Value Libtorrent::SettingsPack::GetUrlseedMaxRequestBytes(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->urlseed_max_request_bytes);
}
Napi::Value Libtorrent::SettingsPack::GetWebSeedNameLookupRetry(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->web_seed_name_lookup_retry);
}
Napi::Value Libtorrent::SettingsPack::GetCloseFileInterval(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->close_file_interval);
}
Napi::Value Libtorrent::SettingsPack::GetUtpCwndReduceTimer(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->utp_cwnd_reduce_timer);
}
Napi::Value Libtorrent::SettingsPack::GetMaxWebSeedConnections(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->max_web_seed_connections);
}
Napi::Value Libtorrent::SettingsPack::GetResolverCacheTimeout(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->resolver_cache_timeout);
}
Napi::Value Libtorrent::SettingsPack::GetSendNotSentLowWatermark(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->send_not_sent_low_watermark);
}
Napi::Value Libtorrent::SettingsPack::GetRateChokerInitialThreshold(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->rate_choker_initial_threshold);
}
Napi::Value Libtorrent::SettingsPack::GetUpnpLeaseDuration(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->upnp_lease_duration);
}
Napi::Value Libtorrent::SettingsPack::GetMaxConcurrentHttpAnnounces(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->max_concurrent_http_announces);
}
Napi::Value Libtorrent::SettingsPack::GetDhtMaxPeersReply(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_max_peers_reply);
}
Napi::Value Libtorrent::SettingsPack::GetDhtSearchBranching(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_search_branching);
}
Napi::Value Libtorrent::SettingsPack::GetDhtMaxFailCount(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_max_fail_count);
}
Napi::Value Libtorrent::SettingsPack::GetDhtMaxTorrents(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_max_torrents);
}
Napi::Value Libtorrent::SettingsPack::GetDhtMaxDhtItems(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_max_dht_items);
}
Napi::Value Libtorrent::SettingsPack::GetDhtMaxPeers(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_max_peers);
}
Napi::Value Libtorrent::SettingsPack::GetDhtMaxTorrentSearchReply(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_max_torrent_search_reply);
}
Napi::Value Libtorrent::SettingsPack::GetDhtBlockTimeout(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_block_timeout);
}
Napi::Value Libtorrent::SettingsPack::GetDhtBlockRatelimit(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_block_ratelimit);
}
Napi::Value Libtorrent::SettingsPack::GetDhtItemLifetime(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_item_lifetime);
}
Napi::Value Libtorrent::SettingsPack::GetDhtSampleInfohashesInterval(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_sample_infohashes_interval);
}
Napi::Value Libtorrent::SettingsPack::GetDhtMaxInfohashesSampleCount(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->dht_max_infohashes_sample_count);
}
Napi::Value Libtorrent::SettingsPack::GetMaxPieceCount(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->max_piece_count);
}
Napi::Value Libtorrent::SettingsPack::GetMetadataTokenLimit(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->metadata_token_limit);
}
Napi::Value Libtorrent::SettingsPack::GetDiskWriteMode(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->disk_write_mode);
}
Napi::Value Libtorrent::SettingsPack::GetMmapFileSizeCutoff(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->mmap_file_size_cutoff);
}
Napi::Value Libtorrent::SettingsPack::GetI2pInboundQuantity(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->i2p_inbound_quantity);
}
Napi::Value Libtorrent::SettingsPack::GetI2pOutboundQuantity(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->i2p_outbound_quantity);
}
Napi::Value Libtorrent::SettingsPack::GetI2pInboundLength(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->i2p_inbound_length);
}
Napi::Value Libtorrent::SettingsPack::GetI2pOutboundLength(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->i2p_outbound_length);
}
Napi::Value Libtorrent::SettingsPack::GetStringTypeBase(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->string_type_base);
}
Napi::Value Libtorrent::SettingsPack::GetIntTypeBase(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->int_type_base);
}
Napi::Value Libtorrent::SettingsPack::GetBoolTypeBase(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->bool_type_base);
}
Napi::Value Libtorrent::SettingsPack::GetTypeMask(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->type_mask);
}
Napi::Value Libtorrent::SettingsPack::GetIndexMask(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->index_mask);
}
Napi::Value Libtorrent::SettingsPack::GetAlwaysPwrite(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->always_pwrite);
}
Napi::Value Libtorrent::SettingsPack::GetAlwaysMmapWrite(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->always_mmap_write);
}
Napi::Value Libtorrent::SettingsPack::GetAutoMmapWrite(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->auto_mmap_write);
}
Napi::Value Libtorrent::SettingsPack::GetNoPieceSuggestions(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->no_piece_suggestions);
}
Napi::Value Libtorrent::SettingsPack::GetSuggestReadCache(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->suggest_read_cache);
}
Napi::Value Libtorrent::SettingsPack::GetFixedSlotsChoker(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->fixed_slots_choker);
}
Napi::Value Libtorrent::SettingsPack::GetRateBasedChoker(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->rate_based_choker);
}
Napi::Value Libtorrent::SettingsPack::GetRoundRobin(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->round_robin);
}
Napi::Value Libtorrent::SettingsPack::GetFastestUpload(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->fastest_upload);
}
Napi::Value Libtorrent::SettingsPack::GetAntiLeech(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->anti_leech);
}
Napi::Value Libtorrent::SettingsPack::GetEnableOsCache(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->enable_os_cache);
}
Napi::Value Libtorrent::SettingsPack::GetDisableOsCache(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->disable_os_cache);
}
Napi::Value Libtorrent::SettingsPack::GetWriteThrough(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->write_through);
}
Napi::Value Libtorrent::SettingsPack::GetPreferTcp(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->prefer_tcp);
}
Napi::Value Libtorrent::SettingsPack::GetPeerProportional(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->peer_proportional);
}
Napi::Value Libtorrent::SettingsPack::GetPeForced(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->pe_forced);
}
Napi::Value Libtorrent::SettingsPack::GetPeEnabled(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->pe_enabled);
}
Napi::Value Libtorrent::SettingsPack::GetPeDisabled(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->pe_disabled);
}
Napi::Value Libtorrent::SettingsPack::GetPePlaintext(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->pe_plaintext);
}
Napi::Value Libtorrent::SettingsPack::GetPeRc4(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->pe_rc4);
}
Napi::Value Libtorrent::SettingsPack::GetPeBoth(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->pe_both);
}
Napi::Value Libtorrent::SettingsPack::GetNone(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->none);
}
Napi::Value Libtorrent::SettingsPack::GetSocks4(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->socks4);
}
Napi::Value Libtorrent::SettingsPack::GetSocks5(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->socks5);
}
Napi::Value Libtorrent::SettingsPack::GetSocks5Pw(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->socks5_pw);
}
Napi::Value Libtorrent::SettingsPack::GetHttp(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->http);
}
Napi::Value Libtorrent::SettingsPack::GetHttpPw(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->http_pw);
}
Napi::Value Libtorrent::SettingsPack::GetConnectSeedEveryNDownload(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    return Napi::Number::New(env, this->settings_pack->connect_seed_every_n_download);
}
Napi::Value Libtorrent::SettingsPack::SetStr(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    int name = info[0].As<Napi::Number>().Int64Value();
    std::string val = info[1].As<Napi::String>().Utf8Value();
    this->settings_pack->set_str(name, val);
    return env.Null();
}
Napi::Value Libtorrent::SettingsPack::SetInt(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    int name = info[0].As<Napi::Number>().Int64Value();
    int val = info[1].As<Napi::Number>().Int64Value();
    this->settings_pack->set_int(name, val);
    return env.Null();
}
Napi::Value Libtorrent::SettingsPack::SetBool(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    int name = info[0].As<Napi::Number>().Int64Value();
    bool val = info[1].As<Napi::Boolean>().Value();
    this->settings_pack->set_bool(name, val);
    return env.Null();
}
Napi::Value Libtorrent::SettingsPack::GetStr(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    int name = info[0].As<Napi::Number>().Int64Value();
    return Napi::String::New(env, this->settings_pack->get_str(name));
}
Napi::Value Libtorrent::SettingsPack::GetInt(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    int name = info[0].As<Napi::Number>().Int64Value();
    return Napi::Number::New(env, this->settings_pack->get_int(name));
}
Napi::Value Libtorrent::SettingsPack::GetBool(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    int name = info[0].As<Napi::Number>().Int64Value();
    return Napi::Boolean::New(env, this->settings_pack->get_bool(name));
}
Napi::Value Libtorrent::SettingsPack::HasVal(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    int name = info[0].As<Napi::Number>().Int64Value();
    return Napi::Boolean::New(env, this->settings_pack->has_val(name));
}
Napi::Value Libtorrent::SettingsPack::Clear(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 1)
    {
        this->settings_pack->clear();
    }
    else
    {
        int name = info[0].As<Napi::Number>().Int64Value();
        this->settings_pack->clear(name);
    }
    return env.Null();
}
