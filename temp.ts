const snakeToPascal = (string_: string) =>
	string_
		.split('_')
		.map(s => s.charAt(0).toUpperCase() + s.slice(1))
		.join('');
const snakeToCamel = (string_: string) =>
	string_
		.split('_')
		.map((s, i) => (i === 0 ? s : s.charAt(0).toUpperCase() + s.slice(1)))
		.join('');
const classes = [
	{
		name: 'dht_state',
		namespaces: ['libtorrent', 'dht'],
		constructors: [
			[],
			[
				{
					type: 'dht_state',
					name: 'dht_state',
				},
			],
		],
		nullptr: false,
		properties: [
			{
				type: 'endpoint[]',
				name: 'nodes',
				writable: true,
			},
			{
				type: 'endpoint[]',
				name: 'nodes6',
				writable: true,
			},
		],
		methods: [],
	},
	{
		name: 'endpoint',
		namespaces: ['libtorrent', 'udp'],
		constructors: [
			[],
			[
				{
					type: 'endpoint',
					name: 'other',
				},
			],
			[
				{
					type: 'address',
					name: 'addr',
				},
				{
					type: 'number',
					name: 'port_num',
				},
			],
		],
		nullptr: false,
		properties: [],
		methods: [
			{
				name: 'port',
				overloads: [
					{
						params: [
							{
								type: 'number',
								name: 'port_num',
							},
						],
						returns: 'void',
					},
					{
						params: [],
						returns: 'number',
					},
				],
			},
			{
				name: 'address',
				overloads: [
					{
						params: [
							{
								type: 'address',
								name: 'addr',
							},
						],
						returns: 'void',
					},
					{
						params: [],
						returns: 'address',
					},
				],
			},
		],
	},
	{
		name: 'add_torrent_params',
		namespaces: ['libtorrent'],
		constructors: [
			[],
			[
				{
					type: 'add_torrent_params',
					name: 'add_torrent_params',
				},
			],
		],
		nullptr: false,
		properties: [
			{
				type: 'torrent_flags_t',
				name: 'flags',
				writable: true,
			},
			{
				type: 'info_hash_t',
				name: 'info_hashes',
				writable: true,
			},
		],
		methods: [],
	},
	{
		name: 'address',
		namespaces: ['libtorrent'],
		constructors: [
			[],
			[
				{
					type: 'address',
					name: 'other',
				},
			],
		],
		nullptr: false,
		properties: [],
		methods: [],
	},
	{
		name: 'alert',
		namespaces: ['libtorrent'],
		constructors: [
			[],
		],
		nullptr: true,
		properties: [],
		methods: [
			{
				name: 'type',
				overloads: [
					{
						params: [],
						returns: 'number',
					},
				],
			},
			{
				name: 'what',
				overloads: [
					{
						params: [],
						returns: 'string',
					},
				],
			},
			{
				name: 'message',
				overloads: [
					{
						params: [],
						returns: 'string',
					},
				],
			},
		],
	},
	{
		name: 'create_torrent',
		namespaces: ['libtorrent'],
		constructors: [
			[],
			[
				{
					type: 'create_torrent',
					name: 'create_torrent',
				},
			],
		],
		nullptr: true,
		properties: [],
		methods: [],
	},
	{
		name: 'dht_sample_infohashes_alert',
		namespaces: ['libtorrent'],
		constructors: [
			[],
		],
		nullptr: true,
		properties: [],
		methods: [
			{
				name: 'num_samples',
				overloads: [
					{
						params: [],
						returns: 'number',
					},
				],
			},
			{
				name: 'samples',
				overloads: [
					{
						params: [],
						returns: 'sha1_hash[]',
					},
				],
			},
		],
	},
	{
		name: 'info_hash_t',
		namespaces: ['libtorrent'],
		constructors: [
			[],
			[
				{
					type: 'info_hash_t',
					name: 'info_hash_t',
				},
			],
			[
				{
					type: 'sha1_hash',
					name: 'h1',
				},
			],
			[
				{
					type: 'sha256_hash',
					name: 'h2',
				},
			],
		],
		nullptr: false,
		properties: [
			{
				type: 'sha1_hash',
				name: 'v1',
				writable: true,
			},
			{
				type: 'sha256_hash',
				name: 'v2',
				writable: true,
			},
		],
		methods: [],
	},
	{
		name: 'iovec_t',
		namespaces: ['libtorrent'],
		constructors: [
			[],
			[
				{
					type: 'iovec_t',
					name: 'c',
				},
			],
		],
		nullptr: false,
		properties: [],
		methods: [
			{
				name: 'data',
				overloads: [
					{
						params: [],
						returns: 'Buffer',
					},
				],
			},
		],
	},
	{
		name: 'metadata_received_alert',
		namespaces: ['libtorrent'],
		constructors: [
			[],
		],
		nullptr: true,
		properties: [
			{
				name: 'handle',
				writable: true,
				type: 'torrent_handle',
			},
		],
		methods: [],
	},
	{
		name: 'session_params',
		namespaces: ['libtorrent'],
		constructors: [
			[],
			[
				{
					type: 'session_params',
					name: 'session_params',
				},
			],
			[
				{
					type: 'settings_pack',
					name: 'sp',
				},
			],
		],
		nullptr: false,
		properties: [
			{
				name: 'dht_state',
				writable: true,
				type: 'dht_state',
			},
		],
		methods: [],
	},
	{
		name: 'session',
		namespaces: ['libtorrent'],
		constructors: [
			[],
			[
				{
					type: 'session_params',
					name: 'params',
				},
			],
			[
				{
					type: 'settings_pack',
					name: 'pack',
				},
			],
		],
		nullptr: false,
		properties: [],
		methods: [
			{
				name: 'pop_alerts',
				overloads: [
					{
						params: [
							{
								type: 'alert[]',
								name: 'alerts',
							},
						],
						returns: 'void',
					},
				],
			},
			{
				name: 'session_state',
				overloads: [
					{
						params: [],
						returns: 'session_params',
					},
				],
			},
			{
				name: 'is_valid',
				overloads: [
					{
						params: [],
						returns: 'boolean',
					},
				],
			},
			{
				name: 'post_dht_stats',
				overloads: [
					{
						params: [],
						returns: 'void',
					},
				],
			},
			{
				name: 'post_session_stats',
				overloads: [
					{
						params: [],
						returns: 'void',
					},
				],
			},
			{
				name: 'post_torrent_updates',
				overloads: [
					{
						params: [],
						returns: 'void',
					},
				],
			},
			{
				name: 'dht_sample_infohashes',
				overloads: [
					{
						params: [
							{type: 'endpoint', name: 'ep'},
							{type: 'sha1_hash', name: 'target'},
						],
						returns: 'void',
					},
				],
			},
			{
				name: 'add_torrent',
				overloads: [
					{
						params: [{type: 'add_torrent_params', name: 'params'}],
						returns: 'torrent_handle',
					},
				],
			},
			{
				name: 'async_add_torrent',
				overloads: [
					{
						params: [{type: 'add_torrent_params', name: 'params'}],
						returns: 'void',
					},
				],
			},
		],
	},
	{
		name: 'settings_pack',
		namespaces: ['libtorrent'],
		constructors: [
			[],
			[
				{
					type: 'settings_pack',
					name: 'settings_pack',
				},
			],
		],
		nullptr: false,
		properties: [
			{
				type: 'number',
				name: 'user_agent',
				writable: false,
			},
			{
				type: 'number',
				name: 'announce_ip',
				writable: false,
			},
			{
				type: 'number',
				name: 'handshake_client_version',
				writable: false,
			},
			{
				type: 'number',
				name: 'outgoing_interfaces',
				writable: false,
			},
			{
				type: 'number',
				name: 'listen_interfaces',
				writable: false,
			},
			{
				type: 'number',
				name: 'proxy_hostname',
				writable: false,
			},
			{
				type: 'number',
				name: 'proxy_username',
				writable: false,
			},
			{
				type: 'number',
				name: 'proxy_password',
				writable: false,
			},
			{
				type: 'number',
				name: 'i2p_hostname',
				writable: false,
			},
			{
				type: 'number',
				name: 'peer_fingerprint',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_bootstrap_nodes',
				writable: false,
			},
			{
				type: 'number',
				name: 'allow_multiple_connections_per_ip',
				writable: false,
			},
			{
				type: 'number',
				name: 'send_redundant_have',
				writable: false,
			},
			{
				type: 'number',
				name: 'use_dht_as_fallback',
				writable: false,
			},
			{
				type: 'number',
				name: 'upnp_ignore_nonrouters',
				writable: false,
			},
			{
				type: 'number',
				name: 'use_parole_mode',
				writable: false,
			},
			{
				type: 'number',
				name: 'auto_manage_prefer_seeds',
				writable: false,
			},
			{
				type: 'number',
				name: 'dont_count_slow_torrents',
				writable: false,
			},
			{
				type: 'number',
				name: 'close_redundant_connections',
				writable: false,
			},
			{
				type: 'number',
				name: 'prioritize_partial_pieces',
				writable: false,
			},
			{
				type: 'number',
				name: 'rate_limit_ip_overhead',
				writable: false,
			},
			{
				type: 'number',
				name: 'announce_to_all_tiers',
				writable: false,
			},
			{
				type: 'number',
				name: 'announce_to_all_trackers',
				writable: false,
			},
			{
				type: 'number',
				name: 'prefer_udp_trackers',
				writable: false,
			},
			{
				type: 'number',
				name: 'disable_hash_checks',
				writable: false,
			},
			{
				type: 'number',
				name: 'allow_i2p_mixed',
				writable: false,
			},
			{
				type: 'number',
				name: 'no_atime_storage',
				writable: false,
			},
			{
				type: 'number',
				name: 'incoming_starts_queued_torrents',
				writable: false,
			},
			{
				type: 'number',
				name: 'report_true_downloaded',
				writable: false,
			},
			{
				type: 'number',
				name: 'strict_end_game_mode',
				writable: false,
			},
			{
				type: 'number',
				name: 'enable_outgoing_utp',
				writable: false,
			},
			{
				type: 'number',
				name: 'enable_incoming_utp',
				writable: false,
			},
			{
				type: 'number',
				name: 'enable_outgoing_tcp',
				writable: false,
			},
			{
				type: 'number',
				name: 'enable_incoming_tcp',
				writable: false,
			},
			{
				type: 'number',
				name: 'no_recheck_incomplete_resume',
				writable: false,
			},
			{
				type: 'number',
				name: 'anonymous_mode',
				writable: false,
			},
			{
				type: 'number',
				name: 'report_web_seed_downloads',
				writable: false,
			},
			{
				type: 'number',
				name: 'seeding_outgoing_connections',
				writable: false,
			},
			{
				type: 'number',
				name: 'no_connect_privileged_ports',
				writable: false,
			},
			{
				type: 'number',
				name: 'smooth_connects',
				writable: false,
			},
			{
				type: 'number',
				name: 'always_send_user_agent',
				writable: false,
			},
			{
				type: 'number',
				name: 'apply_ip_filter_to_trackers',
				writable: false,
			},
			{
				type: 'number',
				name: 'ban_web_seeds',
				writable: false,
			},
			{
				type: 'number',
				name: 'support_share_mode',
				writable: false,
			},
			{
				type: 'number',
				name: 'report_redundant_bytes',
				writable: false,
			},
			{
				type: 'number',
				name: 'listen_system_port_fallback',
				writable: false,
			},
			{
				type: 'number',
				name: 'announce_crypto_support',
				writable: false,
			},
			{
				type: 'number',
				name: 'enable_upnp',
				writable: false,
			},
			{
				type: 'number',
				name: 'enable_natpmp',
				writable: false,
			},
			{
				type: 'number',
				name: 'enable_lsd',
				writable: false,
			},
			{
				type: 'number',
				name: 'enable_dht',
				writable: false,
			},
			{
				type: 'number',
				name: 'prefer_rc4',
				writable: false,
			},
			{
				type: 'number',
				name: 'proxy_hostnames',
				writable: false,
			},
			{
				type: 'number',
				name: 'proxy_peer_connections',
				writable: false,
			},
			{
				type: 'number',
				name: 'auto_sequential',
				writable: false,
			},
			{
				type: 'number',
				name: 'proxy_tracker_connections',
				writable: false,
			},
			{
				type: 'number',
				name: 'enable_ip_notifier',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_prefer_verified_node_ids',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_restrict_routing_ips',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_restrict_search_ips',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_extended_routing_table',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_aggressive_lookups',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_privacy_lookups',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_enforce_node_id',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_ignore_dark_internet',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_read_only',
				writable: false,
			},
			{
				type: 'number',
				name: 'piece_extent_affinity',
				writable: false,
			},
			{
				type: 'number',
				name: 'validate_https_trackers',
				writable: false,
			},
			{
				type: 'number',
				name: 'ssrf_mitigation',
				writable: false,
			},
			{
				type: 'number',
				name: 'allow_idna',
				writable: false,
			},
			{
				type: 'number',
				name: 'enable_set_file_valid_data',
				writable: false,
			},
			{
				type: 'number',
				name: 'socks5_udp_send_local_ep',
				writable: false,
			},
			{
				type: 'number',
				name: 'tracker_completion_timeout',
				writable: false,
			},
			{
				type: 'number',
				name: 'tracker_receive_timeout',
				writable: false,
			},
			{
				type: 'number',
				name: 'stop_tracker_timeout',
				writable: false,
			},
			{
				type: 'number',
				name: 'tracker_maximum_response_length',
				writable: false,
			},
			{
				type: 'number',
				name: 'piece_timeout',
				writable: false,
			},
			{
				type: 'number',
				name: 'request_timeout',
				writable: false,
			},
			{
				type: 'number',
				name: 'request_queue_time',
				writable: false,
			},
			{
				type: 'number',
				name: 'max_allowed_in_request_queue',
				writable: false,
			},
			{
				type: 'number',
				name: 'max_out_request_queue',
				writable: false,
			},
			{
				type: 'number',
				name: 'whole_pieces_threshold',
				writable: false,
			},
			{
				type: 'number',
				name: 'peer_timeout',
				writable: false,
			},
			{
				type: 'number',
				name: 'urlseed_timeout',
				writable: false,
			},
			{
				type: 'number',
				name: 'urlseed_pipeline_size',
				writable: false,
			},
			{
				type: 'number',
				name: 'urlseed_wait_retry',
				writable: false,
			},
			{
				type: 'number',
				name: 'file_pool_size',
				writable: false,
			},
			{
				type: 'number',
				name: 'max_failcount',
				writable: false,
			},
			{
				type: 'number',
				name: 'min_reconnect_time',
				writable: false,
			},
			{
				type: 'number',
				name: 'peer_connect_timeout',
				writable: false,
			},
			{
				type: 'number',
				name: 'connection_speed',
				writable: false,
			},
			{
				type: 'number',
				name: 'inactivity_timeout',
				writable: false,
			},
			{
				type: 'number',
				name: 'unchoke_interval',
				writable: false,
			},
			{
				type: 'number',
				name: 'optimistic_unchoke_interval',
				writable: false,
			},
			{
				type: 'number',
				name: 'num_want',
				writable: false,
			},
			{
				type: 'number',
				name: 'initial_picker_threshold',
				writable: false,
			},
			{
				type: 'number',
				name: 'allowed_fast_set_size',
				writable: false,
			},
			{
				type: 'number',
				name: 'suggest_mode',
				writable: false,
			},
			{
				type: 'number',
				name: 'max_queued_disk_bytes',
				writable: false,
			},
			{
				type: 'number',
				name: 'handshake_timeout',
				writable: false,
			},
			{
				type: 'number',
				name: 'send_buffer_low_watermark',
				writable: false,
			},
			{
				type: 'number',
				name: 'send_buffer_watermark',
				writable: false,
			},
			{
				type: 'number',
				name: 'send_buffer_watermark_factor',
				writable: false,
			},
			{
				type: 'number',
				name: 'choking_algorithm',
				writable: false,
			},
			{
				type: 'number',
				name: 'seed_choking_algorithm',
				writable: false,
			},
			{
				type: 'number',
				name: 'disk_io_write_mode',
				writable: false,
			},
			{
				type: 'number',
				name: 'disk_io_read_mode',
				writable: false,
			},
			{
				type: 'number',
				name: 'outgoing_port',
				writable: false,
			},
			{
				type: 'number',
				name: 'num_outgoing_ports',
				writable: false,
			},
			{
				type: 'number',
				name: 'peer_dscp',
				writable: false,
			},
			{
				type: 'number',
				name: 'active_downloads',
				writable: false,
			},
			{
				type: 'number',
				name: 'active_seeds',
				writable: false,
			},
			{
				type: 'number',
				name: 'active_checking',
				writable: false,
			},
			{
				type: 'number',
				name: 'active_dht_limit',
				writable: false,
			},
			{
				type: 'number',
				name: 'active_tracker_limit',
				writable: false,
			},
			{
				type: 'number',
				name: 'active_lsd_limit',
				writable: false,
			},
			{
				type: 'number',
				name: 'active_limit',
				writable: false,
			},
			{
				type: 'number',
				name: 'auto_manage_interval',
				writable: false,
			},
			{
				type: 'number',
				name: 'seed_time_limit',
				writable: false,
			},
			{
				type: 'number',
				name: 'auto_scrape_interval',
				writable: false,
			},
			{
				type: 'number',
				name: 'auto_scrape_min_interval',
				writable: false,
			},
			{
				type: 'number',
				name: 'max_peerlist_size',
				writable: false,
			},
			{
				type: 'number',
				name: 'max_paused_peerlist_size',
				writable: false,
			},
			{
				type: 'number',
				name: 'min_announce_interval',
				writable: false,
			},
			{
				type: 'number',
				name: 'auto_manage_startup',
				writable: false,
			},
			{
				type: 'number',
				name: 'seeding_piece_quota',
				writable: false,
			},
			{
				type: 'number',
				name: 'max_rejects',
				writable: false,
			},
			{
				type: 'number',
				name: 'recv_socket_buffer_size',
				writable: false,
			},
			{
				type: 'number',
				name: 'send_socket_buffer_size',
				writable: false,
			},
			{
				type: 'number',
				name: 'max_peer_recv_buffer_size',
				writable: false,
			},
			{
				type: 'number',
				name: 'optimistic_disk_retry',
				writable: false,
			},
			{
				type: 'number',
				name: 'max_suggest_pieces',
				writable: false,
			},
			{
				type: 'number',
				name: 'local_service_announce_interval',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_announce_interval',
				writable: false,
			},
			{
				type: 'number',
				name: 'udp_tracker_token_expiry',
				writable: false,
			},
			{
				type: 'number',
				name: 'num_optimistic_unchoke_slots',
				writable: false,
			},
			{
				type: 'number',
				name: 'max_pex_peers',
				writable: false,
			},
			{
				type: 'number',
				name: 'tick_interval',
				writable: false,
			},
			{
				type: 'number',
				name: 'share_mode_target',
				writable: false,
			},
			{
				type: 'number',
				name: 'upload_rate_limit',
				writable: false,
			},
			{
				type: 'number',
				name: 'download_rate_limit',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_upload_rate_limit',
				writable: false,
			},
			{
				type: 'number',
				name: 'unchoke_slots_limit',
				writable: false,
			},
			{
				type: 'number',
				name: 'connections_limit',
				writable: false,
			},
			{
				type: 'number',
				name: 'connections_slack',
				writable: false,
			},
			{
				type: 'number',
				name: 'utp_target_delay',
				writable: false,
			},
			{
				type: 'number',
				name: 'utp_gain_factor',
				writable: false,
			},
			{
				type: 'number',
				name: 'utp_min_timeout',
				writable: false,
			},
			{
				type: 'number',
				name: 'utp_syn_resends',
				writable: false,
			},
			{
				type: 'number',
				name: 'utp_fin_resends',
				writable: false,
			},
			{
				type: 'number',
				name: 'utp_num_resends',
				writable: false,
			},
			{
				type: 'number',
				name: 'utp_connect_timeout',
				writable: false,
			},
			{
				type: 'number',
				name: 'utp_loss_multiplier',
				writable: false,
			},
			{
				type: 'number',
				name: 'mixed_mode_algorithm',
				writable: false,
			},
			{
				type: 'number',
				name: 'listen_queue_size',
				writable: false,
			},
			{
				type: 'number',
				name: 'torrent_connect_boost',
				writable: false,
			},
			{
				type: 'number',
				name: 'alert_queue_size',
				writable: false,
			},
			{
				type: 'number',
				name: 'max_metadata_size',
				writable: false,
			},
			{
				type: 'number',
				name: 'hashing_threads',
				writable: false,
			},
			{
				type: 'number',
				name: 'checking_mem_usage',
				writable: false,
			},
			{
				type: 'number',
				name: 'predictive_piece_announce',
				writable: false,
			},
			{
				type: 'number',
				name: 'aio_threads',
				writable: false,
			},
			{
				type: 'number',
				name: 'tracker_backoff',
				writable: false,
			},
			{
				type: 'number',
				name: 'share_ratio_limit',
				writable: false,
			},
			{
				type: 'number',
				name: 'seed_time_ratio_limit',
				writable: false,
			},
			{
				type: 'number',
				name: 'peer_turnover',
				writable: false,
			},
			{
				type: 'number',
				name: 'peer_turnover_cutoff',
				writable: false,
			},
			{
				type: 'number',
				name: 'peer_turnover_interval',
				writable: false,
			},
			{
				type: 'number',
				name: 'max_http_recv_buffer_size',
				writable: false,
			},
			{
				type: 'number',
				name: 'max_retry_port_bind',
				writable: false,
			},
			{
				type: 'number',
				name: 'alert_mask',
				writable: false,
			},
			{
				type: 'number',
				name: 'out_enc_policy',
				writable: false,
			},
			{
				type: 'number',
				name: 'in_enc_policy',
				writable: false,
			},
			{
				type: 'number',
				name: 'allowed_enc_level',
				writable: false,
			},
			{
				type: 'number',
				name: 'inactive_down_rate',
				writable: false,
			},
			{
				type: 'number',
				name: 'inactive_up_rate',
				writable: false,
			},
			{
				type: 'number',
				name: 'proxy_type',
				writable: false,
			},
			{
				type: 'number',
				name: 'proxy_port',
				writable: false,
			},
			{
				type: 'number',
				name: 'i2p_port',
				writable: false,
			},
			{
				type: 'number',
				name: 'urlseed_max_request_bytes',
				writable: false,
			},
			{
				type: 'number',
				name: 'web_seed_name_lookup_retry',
				writable: false,
			},
			{
				type: 'number',
				name: 'close_file_interval',
				writable: false,
			},
			{
				type: 'number',
				name: 'utp_cwnd_reduce_timer',
				writable: false,
			},
			{
				type: 'number',
				name: 'max_web_seed_connections',
				writable: false,
			},
			{
				type: 'number',
				name: 'resolver_cache_timeout',
				writable: false,
			},
			{
				type: 'number',
				name: 'send_not_sent_low_watermark',
				writable: false,
			},
			{
				type: 'number',
				name: 'rate_choker_initial_threshold',
				writable: false,
			},
			{
				type: 'number',
				name: 'upnp_lease_duration',
				writable: false,
			},
			{
				type: 'number',
				name: 'max_concurrent_http_announces',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_max_peers_reply',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_search_branching',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_max_fail_count',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_max_torrents',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_max_dht_items',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_max_peers',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_max_torrent_search_reply',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_block_timeout',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_block_ratelimit',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_item_lifetime',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_sample_infohashes_interval',
				writable: false,
			},
			{
				type: 'number',
				name: 'dht_max_infohashes_sample_count',
				writable: false,
			},
			{
				type: 'number',
				name: 'max_piece_count',
				writable: false,
			},
			{
				type: 'number',
				name: 'metadata_token_limit',
				writable: false,
			},
			{
				type: 'number',
				name: 'disk_write_mode',
				writable: false,
			},
			{
				type: 'number',
				name: 'mmap_file_size_cutoff',
				writable: false,
			},
			{
				type: 'number',
				name: 'i2p_inbound_quantity',
				writable: false,
			},
			{
				type: 'number',
				name: 'i2p_outbound_quantity',
				writable: false,
			},
			{
				type: 'number',
				name: 'i2p_inbound_length',
				writable: false,
			},
			{
				type: 'number',
				name: 'i2p_outbound_length',
				writable: false,
			},
			{
				type: 'number',
				name: 'string_type_base',
				writable: false,
			},
			{
				type: 'number',
				name: 'int_type_base',
				writable: false,
			},
			{
				type: 'number',
				name: 'bool_type_base',
				writable: false,
			},
			{
				type: 'number',
				name: 'type_mask',
				writable: false,
			},
			{
				type: 'number',
				name: 'index_mask',
				writable: false,
			},
			{
				type: 'number',
				name: 'always_pwrite',
				writable: false,
			},
			{
				type: 'number',
				name: 'always_mmap_write',
				writable: false,
			},
			{
				type: 'number',
				name: 'auto_mmap_write',
				writable: false,
			},
			{
				type: 'number',
				name: 'no_piece_suggestions',
				writable: false,
			},
			{
				type: 'number',
				name: 'suggest_read_cache',
				writable: false,
			},
			{
				type: 'number',
				name: 'fixed_slots_choker',
				writable: false,
			},
			{
				type: 'number',
				name: 'rate_based_choker',
				writable: false,
			},
			{
				type: 'number',
				name: 'round_robin',
				writable: false,
			},
			{
				type: 'number',
				name: 'fastest_upload',
				writable: false,
			},
			{
				type: 'number',
				name: 'anti_leech',
				writable: false,
			},
			{
				type: 'number',
				name: 'enable_os_cache',
				writable: false,
			},
			{
				type: 'number',
				name: 'disable_os_cache',
				writable: false,
			},
			{
				type: 'number',
				name: 'write_through',
				writable: false,
			},
			{
				type: 'number',
				name: 'prefer_tcp',
				writable: false,
			},
			{
				type: 'number',
				name: 'peer_proportional',
				writable: false,
			},
			{
				type: 'number',
				name: 'pe_forced',
				writable: false,
			},
			{
				type: 'number',
				name: 'pe_enabled',
				writable: false,
			},
			{
				type: 'number',
				name: 'pe_disabled',
				writable: false,
			},
			{
				type: 'number',
				name: 'pe_plaintext',
				writable: false,
			},
			{
				type: 'number',
				name: 'pe_rc4',
				writable: false,
			},
			{
				type: 'number',
				name: 'pe_both',
				writable: false,
			},
			{
				type: 'number',
				name: 'none',
				writable: false,
			},
			{
				type: 'number',
				name: 'socks4',
				writable: false,
			},
			{
				type: 'number',
				name: 'socks5',
				writable: false,
			},
			{
				type: 'number',
				name: 'socks5_pw',
				writable: false,
			},
			{
				type: 'number',
				name: 'http',
				writable: false,
			},
			{
				type: 'number',
				name: 'http_pw',
				writable: false,
			},
			{
				type: 'number',
				name: 'connect_seed_every_n_download',
				writable: false,
			},
		],
		methods: [
			{
				name: 'set_str',
				overloads: [
					{
						params: [
							{
								type: 'number',
								name: 'name',
							},
							{
								type: 'string',
								name: 'val',
							},
						],
						returns: 'void',
					},
				],
			},
			{
				name: 'set_int',
				overloads: [
					{
						params: [
							{
								type: 'number',
								name: 'name',
							},
							{
								type: 'number',
								name: 'val',
							},
						],
						returns: 'void',
					},
				],
			},
			{
				name: 'set_bool',
				overloads: [
					{
						params: [
							{
								type: 'number',
								name: 'name',
							},
							{
								type: 'boolean',
								name: 'val',
							},
						],
						returns: 'void',
					},
				],
			},
			{
				name: 'get_str',
				overloads: [
					{
						params: [
							{
								type: 'number',
								name: 'name',
							},
						],
						returns: 'string',
					},
				],
			},
			{
				name: 'get_int',
				overloads: [
					{
						params: [
							{
								type: 'number',
								name: 'name',
							},
						],
						returns: 'number',
					},
				],
			},
			{
				name: 'get_bool',
				overloads: [
					{
						params: [
							{
								type: 'number',
								name: 'name',
							},
						],
						returns: 'boolean',
					},
				],
			},
			{
				name: 'has_val',
				overloads: [
					{
						params: [
							{
								type: 'number',
								name: 'name',
							},
						],
						returns: 'boolean',
					},
				],
			},
			{
				name: 'clear',
				overloads: [
					{
						params: [
							{
								type: 'number',
								name: 'name',
							},
						],
						returns: 'void',
					},
				],
			},
			{
				name: 'clear',
				overloads: [
					{
						params: [],
						returns: 'void',
					},
				],
			},
		],
	},
	{
		name: 'sha1_hash',
		namespaces: ['libtorrent'],
		constructors: [
			[],
			[
				{
					type: 'sha1_hash',
					name: 'sha1_hash',
				},
			],
			[
				{
					type: 'Buffer',
					name: 's',
				},
			],
		],
		nullptr: false,
		properties: [],
		methods: [
			{
				name: 'assign',
				overloads: [
					{
						params: [
							{
								type: 'Buffer',
								name: 'str',
							},
						],
						returns: 'void',
					},
				],
			},
		],
	},
	{
		name: 'sha256_hash',
		namespaces: ['libtorrent'],
		constructors: [
			[],
			[
				{
					type: 'sha256_hash',
					name: 'sha256_hash',
				},
			],
			[
				{
					type: 'Buffer',
					name: 's',
				},
			],
		],
		nullptr: false,
		properties: [],
		methods: [
			{
				name: 'assign',
				overloads: [
					{
						params: [
							{
								type: 'Buffer',
								name: 'str',
							},
						],
						returns: 'void',
					},
				],
			},
		],
	},
	{
		name: 'torrent_flags_t',
		namespaces: ['libtorrent'],
		constructors: [
			[],
			[
				{
					type: 'torrent_flags_t',
					name: 'rhs',
				},
			],
		],
		nullptr: false,
		properties: [],
		methods: [
			{
				name: 'operator|=',
				overloads: [
					{
						params: [
							{
								type: 'torrent_flags_t',
								name: 'f',
							},
						],
						returns: 'torrent_flags_t',
					},
				],
			},
		],
	},
	{
		name: 'torrent_handle',
		namespaces: ['libtorrent'],
		constructors: [
			[],
			[
				{
					type: 'torrent_handle',
					name: 't',
				},
			],
		],
		nullptr: false,
		properties: [],
		methods: [
			{
				name: 'torrent_file',
				overloads: [
					{
						params: [],
						returns: 'torrent_info',
					},
				],
			},
		],
	},
	{
		name: 'torrent_info',
		namespaces: ['libtorrent'],
		constructors: [
			[],
			[
				{
					type: 'torrent_info',
					name: 't',
				},
			],
		],
		nullptr: true,
		properties: [],
		methods: [
			{
				name: 'info_section',
				overloads: [
					{
						params: [],
						returns: 'iovec_t',
					},
				],
			},
		],
	},
];
const functions = [
	{
		name: 'version',
		namespaces: ['libtorrent'],
		overloads: [
			{
				params: [],
				returns: 'string',
			},
		],
	},
	{
		name: 'make_address',
		namespaces: ['libtorrent'],
		overloads: [
			{
				params: [
					{
						type: 'string',
						name: 'str',
					},
				],
				returns: 'address',
			},
		],
	},
];
const properties = [
	{
		name: 'all',
		namespaces: ['libtorrent', 'torrent_flags'],
		type: 'torrent_flags_t',
	},
	{
		name: 'auto_managed',
		namespaces: ['libtorrent', 'torrent_flags'],
		type: 'torrent_flags_t',
	},
	{
		name: 'default_dont_download',
		namespaces: ['libtorrent', 'torrent_flags'],
		type: 'torrent_flags_t',
	},
	{
		name: 'default_flags',
		namespaces: ['libtorrent', 'torrent_flags'],
		type: 'torrent_flags_t',
	},
];
