// Copyright 2018 bitHeads, Inc. All Rights Reserved.

#pragma once
class BCCLIENTPLUGIN_API ReasonCodes
{
public:
	static const int32 NO_REASON_CODE = 0;

	static const int32 INVALID_NOTIFICATION = 20200;

	static const int32 INVALID_REQUEST = 40001;

	//402..
	static const int32 SWITCHING_FACEBOOK_MEMORY = 40201;
	static const int32 MERGING_MEMORY = 40202;
	static const int32 RESETING_MEMORY = 40203;
	static const int32 RECREATING_ANONYMOUS_MEMORY = 40203;
	static const int32 MOVING_ANONYMOUS_MEMORY = 40204;
	static const int32 LOGIN_SECURITY_ERROR = 40205;
	static const int32 MISSING_IDENTITY_ERROR = 40206;
	static const int32 SWITCHING_PROFILES = 40207;
	static const int32 MISSING_PROFILE_ERROR = 40208;
	static const int32 SECURITY_ERROR = 40209;
	static const int32 DOWNGRADING_TO_ANONYMOUS_ERROR = 40210;
	static const int32 DUPLICATE_IDENTITY_TYPE = 40211;
	static const int32 MERGE_PROFILES = 40212;
	static const int32 INVALID_PROPERTY_NAME = 40213;
	static const int32 EMAIL_NOT_VALIDATED = 40214;
	static const int32 DATABASE_ERROR = 40215;
	static const int32 PROPERTY_NOT_OVERRIDEABLE = 40216;
	static const int32 UNKNOWN_AUTH_ERROR = 40217;
	static const int32 DATABASE_INPUT_TOO_LARGE_ERROR = 40218;
	static const int32 MISSING_APP_EMAIL_ACCOUNT = 40219;
	static const int32 DATABASE_DUP_KEY_ERROR = 40220;
	static const int32 EMAIL_NOT_VALID = 40221;

	//Forbidden 403...
	static const int32 UNABLE_TO_GET_FRIENDS_FROM_FACEBOOK = 40300;
	static const int32 BAD_SIGNATURE = 40301;
	static const int32 UNABLE_TO_VALIDATE_PLAYER = 40302;
	static const int32 PLAYER_SESSION_EXPIRED = 40303;
	static const int32 NO_SESSION = 40304;
	static const int32 PLAYER_SESSION_MISMATCH = 40305;
	static const int32 OPERATION_REQUIRES_A_SESSION = 40306;
	static const int32 TOKEN_DOES_NOT_MATCH_USER = 40307;
	static const int32 MANUAL_REDIRECT = 40308;
	static const int32 EVENT_CAN_ONLY_SEND_TO_FRIEND_OR_SELF = 40309;
	static const int32 NOT_FRIENDS = 40310;
	static const int32 VC_BALANCE_CANNOT_BE_SPECIFIED = 40311;
	static const int32 VC_LIMIT_EXCEEDED = 40312;
	static const int32 UNABLE_TO_GET_MY_DATA_FROM_FACEBOOK = 40313;
	static const int32 TLS_VERSION_INVALID = 40314;
	static const int32 INVALID_AUTHENTICATION_TYPE = 40315;
	static const int32 INVALID_GAME_ID = 40316;
	static const int32 APPLE_TRANS_ID_ALREADY_CLAIMED = 40317;
	static const int32 CLIENT_VERSION_NOT_SUPPORTED = 40318;
	static const int32 BRAINCLOUD_VERSION_NOT_SUPPORTED = 40319;
	static const int32 PLATFORM_NOT_SUPPORTED = 40320;
	static const int32 INVALID_PLAYER_STATISTICS_EVENT_NAME = 40321;
	static const int32 GAME_VERSION_NOT_SUPPORTED = 40322;
	static const int32 BAD_REFERENCE_DATA = 40324;
	static const int32 MISSING_OAUTH_TOKEN = 40325;
	static const int32 MISSING_OAUTH_VERIFIER = 40326;
	static const int32 MISSING_OAUTH_TOKEN_SECRET = 40327;
	static const int32 MISSING_TWEET = 40328;
	static const int32 FACEBOOK_PAYMENT_ID_ALREADY_PROCESSED = 40329;
	static const int32 DISABLED_GAME = 40330;
	static const int32 MATCH_MAKING_DISABLED = 40331;
	static const int32 UPDATE_FAILED = 40332;
	static const int32 INVALID_OPERATION = 40333;
	static const int32 MATCH_RANGE_ERROR = 40334;
	static const int32 PLAYER_IN_MATCH = 40335;
	static const int32 MATCH_PLAYER_SHIELDED = 40336;
	static const int32 MATCH_PLAYER_MISSING = 40337;
	static const int32 MATCH_PLAYER_LOGGED_IN = 40338;
	static const int32 INVALID_ITEM_ID = 40339;
	static const int32 MISSING_PRICE = 40340;
	static const int32 MISSING_USER_INFO = 40341;
	static const int32 MISSING_STEAM_RESPONSE = 40342;
	static const int32 MISSING_STEAM_TRANSACTION = 40343;
	static const int32 ENTITY_VERSION_MISMATCH = 40344;
	static const int32 MISSING_RECORD = 40345;
	static const int32 INSUFFICIENT_PERMISSIONS = 40346;
	static const int32 MISSING_IN_QUERY = 40347;
	static const int32 INVALID_DATABASE_FIELD_NAME = 40347;
	static const int32 RECORD_EXPIRED = 40348;
	static const int32 INVALID_WHERE = 40349;
	static const int32 S3_ERROR = 40350;
	static const int32 INVALID_ATTRIBUTES = 40351;
	static const int32 IMPORT_MISSING_GAME_DATA = 40352;
	static const int32 IMPORT_SCHEMA_VERSION_TOO_OLD = 40353;
	static const int32 IMPORT_MISSING_DIVISION_SETS = 40354;
	static const int32 IMPORT_SCHEMA_VERSION_INVALID = 40355;
	static const int32 PLAYER_SESSION_LOGGED_OUT = 40356;
	static const int32 API_HOOK_SCRIPT_ERROR = 40357;
	static const int32 MISSING_REQUIRED_PARAMETER = 40358;
	static const int32 INVALID_PARAMETER_TYPE = 40359;
	static const int32 INVALID_IDENTITY_TYPE = 40360;
	static const int32 EMAIL_SEND_ERROR = 40361;
	static const int32 CHILD_ENTITY_PARTIAL_UPDATE_INVALID_DATA = 40362;
	static const int32 MISSING_SCRIPT = 40363;
	static const int32 SCRIPT_SECURITY_ERROR = 40364;
	static const int32 SERVER_SESSION_EXPIRED = 40365;
	static const int32 STREAM_DOES_NOT_EXIT = 40366;
	static const int32 STREAM_ACCESS_ERROR = 40367;
	static const int32 STREAM_COMPLETE = 40368;
	static const int32 INVALID_STATISTIC_NAME = 40369;
	static const int32 INVALID_HTTP_REQUEST = 40370;
	static const int32 GAME_LIMIT_REACHED = 40371;
	static const int32 GAME_RUNSTATE_DISABLED = 40372;
	static const int32 INVALID_COMPANY_ID = 40373;
	static const int32 INVALID_PLAYER_ID = 40374;
	static const int32 INVALID_TEMPLATE_ID = 40375;
	static const int32 MINIMUM_SEARCH_INPUT = 40376;
	static const int32 MISSING_GAME_PARENT = 40377;
	static const int32 GAME_PARENT_MISMATCH = 40378;
	static const int32 CHILD_PLAYER_MISSING = 40379;
	static const int32 MISSING_PLAYER_PARENT = 40380;
	static const int32 PLAYER_PARENT_MISMATCH = 40381;
	static const int32 MISSING_PLAYER_ID = 40382;
	static const int32 DECODE_CONTEXT = 40383;
	static const int32 INVALID_QUERY_CONTEXT = 40384;
	static const int32 INVALID_AMOUNT = 40385;
	static const int32 GROUP_MEMBER_NOT_FOUND = 40385;
	static const int32 INVALID_SORT = 40386;
	static const int32 GAME_NOT_FOUND = 40387;
	static const int32 GAMES_NOT_IN_SAME_COMPANY = 40388;
	static const int32 IMPORT_NO_PARENT_ASSIGNED = 40389;
	static const int32 IMPORT_PARENT_CURRENCIES_MISMATCH = 40390;
	static const int32 INVALID_SUBSTITUION_ENTRY = 40391;
	static const int32 INVALID_TEMPLATE_STRING = 40392;
	static const int32 TEMPLATE_SUBSTITUTION_ERROR = 40393;
	static const int32 INVALID_OPPONENTS = 40394;
	static const int32 REDEMPTION_CODE_NOT_FOUND = 40395;
	static const int32 REDEMPTION_CODE_VERSION_MISMATCH = 40396;
	static const int32 REDEMPTION_CODE_ACTIVE = 40397;
	static const int32 REDEMPTION_CODE_NOT_ACTIVE = 40398;
	static const int32 REDEMPTION_CODE_TYPE_NOT_FOUND = 40399;
	static const int32 REDEMPTION_CODE_INVALID = 40400;
	static const int32 REDEMPTION_CODE_REDEEMED = 40401;
	static const int32 REDEMPTION_CODE_REDEEMED_BY_SELF = 40402;
	static const int32 REDEMPTION_CODE_REDEEMED_BY_OTHER = 40403;
	static const int32 SCRIPT_EMPTY = 40404;
	static const int32 ITUNES_COMMUNICATION_ERROR = 40405;
	static const int32 ITUNES_NO_RESPONSE = 40406;
	static const int32 ITUNES_RESPONSE_NOT_OK = 40407;
	static const int32 JSON_PARSING_ERROR = 40408;
	static const int32 ITUNES_NULL_RESPONSE = 40409;
	static const int32 ITUNES_RESPONSE_WITH_NULL_STATUS = 40410;
	static const int32 ITUNES_STATUS_BAD_JSON_RECEIPT = 40411;
	static const int32 ITUNES_STATUS_BAD_RECEIPT = 40412;
	static const int32 ITUNES_STATUS_RECEIPT_NOT_AUTHENTICATED = 40413;
	static const int32 ITUNES_STATUS_BAD_SHARED_SECRET = 40414;
	static const int32 ITUNES_STATUS_RECEIPT_SERVER_UNAVAILABLE = 40415;
	static const int32 ITUNES_RECEIPT_MISSING_ITUNES_PRODUCT_ID = 40416;
	static const int32 PRODUCT_NOT_FOUND_FOR_ITUNES_PRODUCT_ID = 40417;
	static const int32 DATA_STREAM_EVENTS_NOT_ENABLED = 40418;
	static const int32 INVALID_DEVICE_TOKEN = 40419;
	static const int32 ERROR_DELETING_DEVICE_TOKEN = 40420;
	static const int32 WEBPURIFY_NOT_CONFIGURED = 40421;
	static const int32 WEBPURIFY_EXCEPTION = 40422;
	static const int32 WEBPURIFY_FAILURE = 40423;
	static const int32 WEBPURIFY_NOT_ENABLED = 40424;
	static const int32 NAME_CONTAINS_PROFANITY = 40425;
	static const int32 NULL_SESSION = 40426;
	static const int32 PURCHASE_ALREADY_VERIFIED = 40427;
	static const int32 GOOGLE_IAP_NOT_CONFIGURED = 40428;
	static const int32 UPLOAD_FILE_TOO_LARGE = 40429;
	static const int32 FILE_ALREADY_EXISTS = 40430;
	static const int32 CLOUD_STORAGE_SERVICE_ERROR = 40431;
	static const int32 FILE_DOES_NOT_EXIST = 40432;
	static const int32 UPLOAD_ID_MISSING = 40433;
	static const int32 UPLOAD_JOB_MISSING = 40434;
	static const int32 UPLOAD_JOB_EXPIRED = 40435;
	static const int32 UPLOADER_EXCEPTION = 40436;
	static const int32 UPLOADER_FILESIZE_MISMATCH = 40437;
	static const int32 PUSH_NOTIFICATIONS_NOT_CONFIGURED = 40438;
	static const int32 MATCHMAKING_FILTER_SCRIPT_FAILURE = 40439;
	static const int32 ACCOUNT_ALREADY_EXISTS = 40440;
	static const int32 PROFILE_ALREADY_EXISTS = 40441;
	static const int32 MISSING_NOTIFICATION_BODY = 40442;
	static const int32 INVALID_SERVICE_CODE = 40443;
	static const int32 IP_ADDRESS_BLOCKED = 40444;
	static const int32 UNAPPROVED_SERVICE_CODE = 40445;
	static const int32 PROFILE_NOT_FOUND = 40446;
	static const int32 ENTITY_NOT_SHARED = 40447;
	static const int32 SELF_FRIEND = 40448;
	static const int32 PARSE_NOT_CONFIGURED = 40449;
	static const int32 PARSE_NOT_ENABLED = 40450;
	static const int32 PARSE_REQUEST_ERROR = 40451;
	static const int32 GROUP_CANNOT_ADD_OWNER = 40452;
	static const int32 NOT_GROUP_MEMBER = 40453;
	static const int32 INVALID_GROUP_ROLE = 40454;
	static const int32 GROUP_OWNER_DELETE = 40455;
	static const int32 NOT_INVITED_GROUP_MEMBER = 40456;
	static const int32 GROUP_IS_FULL = 40457;
	static const int32 GROUP_OWNER_CANNOT_LEAVE = 40458;
	static const int32 INVALID_INCREMENT_VALUE = 40459;
	static const int32 GROUP_VERSION_MISMATCH = 40460;
	static const int32 GROUP_ENTITY_VERSION_MISMATCH = 40461;
	static const int32 INVALID_GROUP_ID = 40462;
	static const int32 INVALID_FIELD_NAME = 40463;
	static const int32 UNSUPPORTED_AUTH_TYPE = 40464;
	static const int32 CLOUDCODE_JOB_NOT_FOUND = 40465;
	static const int32 CLOUDCODE_JOB_NOT_SCHEDULED = 40466;
	static const int32 GROUP_TYPE_NOT_FOUND = 40467;
	static const int32 MATCHING_GROUPS_NOT_FOUND = 40468;
	static const int32 GENERATE_CDN_URL_ERROR = 40469;
	static const int32 INVALID_PROFILE_IDS = 40470;
	static const int32 MAX_PROFILE_IDS_EXCEEDED = 40471;
	static const int32 PROFILE_ID_MISMATCH = 40472;
	static const int32 LEADERBOARD_DOESNOT_EXIST = 40473;
	static const int32 APP_LICENSING_EXCEEDED = 40474;
	static const int32 SENDGRID_NOT_INSTALLED = 40475;
	static const int32 SENDGRID_EMAIL_SEND_ERROR = 40476;
	static const int32 SENDGRID_NOT_ENABLED_FOR_APP = 40477;
	static const int32 SENDGRID_GET_TEMPLATES_ERROR = 40478;
	static const int32 SENDGRID_INVALID_API_KEY = 40479;
	static const int32 EMAIL_SERVICE_NOT_CONFIGURED = 40480;
	static const int32 INVALID_EMAIL_TEMPLATE_TYPE = 40481;
	static const int32 SENDGRID_KEY_EMPTY_OR_NULL = 40482;
	static const int32 BODY_TEMPLATE_CANNOT_COEXIST = 40483;
	static const int32 SUBSTITUTION_BODY_CANNOT_COEXIST = 40484;
	static const int32 INVALID_FROM_ADDRESS = 40485;
	static const int32 INVALID_FROM_NAME = 40486;
	static const int32 INVALID_REPLY_TO_ADDRESS = 40487;
	static const int32 INVALID_REPLY_TO_NAME = 40488;
	static const int32 FROM_NAME_WITHOUT_FROM_ADDRESS = 40489;
	static const int32 REPLY_TO_NAME_WITHOUT_REPLY_TO_ADDRESS = 40490;
	static const int32 CURRENCY_SECURITY_ERROR = 40491;
	static const int32 INVALID_PEER_CODE = 40492;
	static const int32 PEER_NO_LONGER_EXISTS = 40493;
	static const int32 CANNOT_MODIFY_TOURNAMENT_WITH_LEADERBOARD_SERVICE = 40494;
	static const int32 NO_TOURNAMENT_ASSOCIATED_WITH_LEADERBOARD = 40495;
	static const int32 TOURNAMENT_NOT_ASSOCIATED_WITH_LEADERBOARD = 40496;
	static const int32 PLAYER_ALREADY_TOURNAMENT_FOR_LEADERBOARD = 40497;
	static const int32 PLAYER_EARLY_FOR_JOINING_TOURNAMENT = 40498;
	static const int32 NO_LEADERBOARD_FOUND = 40499;
	static const int32 PLAYER_NOT_IN_TIME_RANGE_FOR_POSTSCORE_TOURNAMENT = 40500;
	static const int32 LEADERBOARD_ID_BAD = 40501;
	static const int32 SCORE_INPUT_BAD = 40502;
	static const int32 ROUND_STARTED_EPOCH_INPUT_BAD = 40503;
	static const int32 TOURNAMENT_CODE_INPUT_BAD = 40504;
	static const int32 PLAYER_NOT_ENROLLED_IN_TOURNAMENT = 40505;
	static const int32 LEADERBOARD_VERSION_ID_INVALID = 40506;
	static const int32 NOT_ENOUGH_BALANCE_TO_JOIN_TOURNAMENT = 40507;
	static const int32 PARENT_ALREADY_ATTACHED = 40508;
	static const int32 PEER_ALREADY_ATTACHED = 40509;
	static const int32 IDENTITY_NOT_ATTACHED_WITH_PARENT = 40510;
	static const int32 IDENTITY_NOT_ATTACHED_WITH_PEER = 40511;
	static const int32 LEADERBOARD_SCORE_UPDATE_ERROR = 40512;
	static const int32 ERROR_CLAIMING_REWARD = 40513;
	static const int32 NOT_ENOUGH_PARENT_BALANCE_TO_JOIN_TOURNAMENT = 40514;
	static const int32 NOT_ENOUGH_PEER_BALANCE_TO_JOIN_TOURNAMENT = 40515;
	static const int32 PLAYER_LATE_FOR_JOINING_TOURNAMENT = 40516;
	static const int32 VIEWING_REWARD_FOR_NON_PROCESSED_TOURNAMENTS = 40517;
	static const int32 NO_REWARD_ASSOCIATED_WITH_LEADERBOARD = 40518;
	static const int32 PROFILE_PEER_NOT_FOUND = 40519;
	static const int32 LEADERBOARD_IN_ACTIVE_STATE = 40520;
	static const int32 LEADERBOARD_IN_CALCULATING_STATE = 40521;
	static const int32 TOURNAMENT_RESULT_PROCESSING_FAILED = 40522;
	static const int32 TOURNAMENT_REWARDS_ALREADY_CLAIMED = 40523;
	static const int32 NO_TOURNAMENT_FOUND = 40524;
	static const int32 UNEXPECTED_ERROR_RANK_ZERO_AFTER_PROCESSING = 40525;
	static const int32 UNEXPECTED_ERROR_DELETING_TOURNAMENT_LEADERBOARD_SCORE = 40526;
	static const int32 INVALID_RUN_STATE = 40527;
	static const int32 LEADERBOARD_SCORE_DOESNOT_EXIST = 40528;
	static const int32 INITIAL_SCORE_NULL = 40529;
	static const int32 TOURNAMENT_NOTIFICATIONS_PROCESSING_FAILED = 40530;
	static const int32 ACL_NOT_READABLE = 40531;
	static const int32 INVALID_OWNER_ID = 40532;
	static const int32 IMPORT_MISSING_PEERS_DATA = 40533;
	static const int32 INVALID_CREDENTIAL = 40534;
	static const int32 GLOBAL_ENTITY_SECURITY_ERROR = 40535;
	static const int32 LEADERBOARD_SECURITY_ERROR = 40536;
	static const int32 NOT_A_SYSTEM_ENTITY = 40537;
	static const int32 CONTROLLER_ERROR = 40538;
	static const int32 EVENT_MISSING = 40539;
	static const int32 INVALID_XP_LEVEL = 40540;
	static const int32 INVALID_ITUNES_ID = 40541;
	static const int32 IMPORT_ERROR = 40542;
	static const int32 INVALID_ENTITY_TYPE = 40543;
	static const int32 FORM_ERROR = 40544;
	static const int32 INVALID_PARENT = 40545;
	static const int32 INVALID_CURRENCY = 40546;
	static const int32 INVALID_THRESHHOLD = 40547;
	static const int32 MATCH_ALREADY_EXISTS = 40548;
	static const int32 FRIEND_NOT_FOUND = 40549;
	static const int32 MATCH_NOT_FOUND = 40550;
	static const int32 MATCH_COMPLETE = 40551;
	static const int32 MATCH_NOT_STARTED = 40552;
	static const int32 MATCH_EXPIRED = 40553;
	static const int32 PLAYER_NOT_IN_MATCH = 40554;
	static const int32 INVALID_MATCH_VERSION = 40555;
	static const int32 INVALID_TURN_VERSION = 40556;
	static const int32 INVALID_DEVICE_TYPE = 40557;
	static const int32 DUPLICATE_ENTITY = 40558;
	static const int32 DUPLICATE_EVENT = 40559;
	static const int32 INVALID_LEADERBOARD_COUNT = 40560;
	static const int32 DUPLICATE_LEADERBOARD = 40561;
	static const int32 MICROSOFT_ERROR = 40562;
	static const int32 DUPLICATE_TOURNAMENT = 40563;
	static const int32 CREATE_SYSTEM_ENTITY_FAILED = 40564;
	static const int32 INVALID_MAX_NUM_STREAMS = 40565;
	static const int32 INVALID_PACKET_ID = 40566;
	static const int32 HOOK_ERROR = 40567;
	static const int32 INVALID_STREAM_ID = 40568;
	static const int32 INVALID_SCAN_CODE = 40569;
	static const int32 NO_CUSTOM_ENTITY_CONFIG_FOUND = 40570;
	static const int32 NO_CUSTOM_ENTITY_FOUND = 40571;
	static const int32 CLOUD_STORAGE_ERROR = 40572;
	static const int32 NO_CUSTOM_FIELD_CONFIG_FOUND = 40573;
	static const int32 MISSING_CUSTOM_ENTITY_QUERY = 40574;
	static const int32 INVALID_CUSTOM_ENTITY_JSON_WHERE = 40575;
	static const int32 INVALID_CUSTOM_ENTITY_JSON_FIELDS = 40576;
	static const int32 ENTITY_ID_NOT_CONFIGURED = 40577;
	static const int32 UNCONFIGURED_CUSTOM_FIELD_ERROR = 40578;
	static const int32 CUSTOM_ENTITY_SECURITY_ERROR = 40579;
	static const int32 CUSTOM_ENTITY_PARTIAL_UPDATE_INVALID_DATA = 40580;
	static const int32 TOURNAMENT_PLAY_HAS_NOT_STARTED = 40581;
	static const int32 TOURNAMENT_PLAY_HAS_ENDED = 40582;
	static const int32 NEW_CREDENTIAL_IN_USE = 40583;
	static const int32 OLD_CREDENTIAL_NOT_OWNED = 40584;
	static const int32 CLOUD_CODE_SECURITY_ERROR = 40585;
	static const int32 RTT_SERVER_NOT_FOUND = 40586;
	static const int32 RTT_CLIENT_NOT_FOUND = 40587;
	static const int32 NO_RTT_SERVERS_AVAILABLE = 40588;
	static const int32 PROFILE_SESSION_MISMATCH = 40589;
	static const int32 WAITING_FOR_ON_DEMAND_TOURNAMENT_TO_START = 40590;
	static const int32 CDN_URLS_NOT_SUPPORTED = 40591;
	static const int32 CLOUD_CONTAINER_ERROR = 40592;
	static const int32 MESSAGING_FEATURE_NOT_CONFIGURED = 40593;
	static const int32 CHAT_FEATURE_NOT_CONFIGURED = 40594;
	static const int32 MESSAGE_NOT_FOUND = 40595;
	static const int32 COLLECTION_CREATE_DISABLED = 40596;
	static const int32 LEADERBAORD_COLLECTION_CREATE_DISABLED = 40597;
	static const int32 MESSAGE_VERSION_MISMATCH = 40598;
	static const int32 MESSAGEBOX_VERSION_MISMATCH = 40599;
	static const int32 MESSAGE_TOO_LARGE = 40600;
	static const int32 FEATURE_NOT_ENABLED = 40601;
	static const int32 CHANNEL_NOT_FOUND = 40603;
	static const int32 MALFORMED_FORM_DATA = 40604;
	static const int32 MISSING_LAST_PACKET_RESPONSE = 40605;
	static const int32 PACKET_IN_PROGRESS = 40606;
	static const int32 LOBBY_MEMBER_NOT_FOUND = 40607;
	static const int32 LOBBY_TEAM_NOT_FOUND = 40608;
	static const int32 LOBBY_ENTRY_QUEUE_MEMBER_NOT_FOUND = 40609;
	static const int32 INVALID_HEADER_APP_ID = 40610;
	static const int32 LOBBY_TYPE_NOT_FOUND = 40611;
	static const int32 LOBBY_TEAM_FULL = 40612;
	static const int32 LOBBY_NOT_FOUND = 40613;
	static const int32 MESSAGE_CONTENT_INVALID_JSON = 40614;
	static const int32 RTT_FEATURE_NOT_CONFIGURED = 40615;
	static const int32 CLOUD_CODE_ONLY_METHOD = 40616;
	static const int32 MESSAGE_FROM_JSON_ID_MUST_BE_NULL = 40617;
	static const int32 MESSAGE_FROM_JSON_NAME_MANDATORY = 40618;
	static const int32 INVALID_LOBBY_STEP_ALIGNMENT = 40619;
	static const int32 INVALID_LOBBY_STEP_STRATEGY = 40620;
	static const int32 MESSAGING_MAX_RECIPIENTS_EXCEEDED = 40621;
	static const int32 LOBBY_FEATURE_NOT_CONFIGURED = 40622;
	static const int32 TOO_MANY_USERS_FOR_TEAM = 40623;
	static const int32 TOO_MANY_USERS_FOR_LOBBY_TYPE = 40624;
	static const int32 DIVISION_SET_DOESNOT_EXIST = 40625;
	static const int32 LOBBY_CONFIG_NOT_FOUND = 40626;
	static const int32 PRESENCE_NOT_INITIALIZED = 40627;
	static const int32 PRESENCE_FEATURE_NOT_CONFIGURED = 40628;
	static const int32 PLAYER_ALREADY_IN_ACTIVE_DIVISION_SET = 40629;
	static const int32 TOURNAMENT_CODE_MISSING = 40630;
	static const int32 ERROR_ASSIGNING_DIVISION_SET_INSTANCE = 40631;
	static const int32 LEADERBOARD_NOT_DIVISION_SET_INSTANCE = 40632;
	static const int32 DIVISION_SET_SCHEDULING_TYPE_DOES_NOT_EXIST = 40633;
	static const int32 PRESENCE_ACTIVITY_NOT_ENABLED = 40634;
	static const int32 PRESENCE_REALTIME_NOT_ENABLED = 40635;
	static const int32 DIVISION_SET_MAX_SIZE_REACHED = 40636;
	static const int32 DIVISION_SET_INFO_ERROR = 40637;
	static const int32 DIVISION_SET_API_MUST_BE_USED = 40638;
	static const int32 API_CALL_REJECTED = 40639;
	static const int32 LEADERBOARD_TOURNAMENT_TEMPLATE_ONLY = 40640;
	static const int32 INVALID_TOURNAMENT_JOB_ID = 40641;
	static const int32 LEADERBOARD_ROTATION_ERROR = 40642;
	static const int32 CLOUD_COMPUTING_ERROR = 40643;
	static const int32 DOCKER_ERROR = 40644;
	static const int32 ROOM_SERVER_HOST_NOT_FOUND = 40645;
	static const int32 INVALID_ATTACHMENT_DATA = 40646;
	static const int32 SCRIPT_PARSING_ERROR = 40647;
	static const int32 INVALID_LOBBY_STEP_RANGES = 40648;
	static const int32 LOG_IN_LOG_ERROR = 40649;
	static const int32 CACHE_OBJECT_TOO_LARGE = 40650;
	static const int32 IDENTIFY_DORMANT_USERS_FEATURE_NOT_CONFIGURED = 40651;
	static const int32 USER_PURGE_NOTICE_NOT_CONFIGURED = 40652;
	static const int32 INVALID_CX_ID = 40653;
	static const int32 TOO_MANY_CACHE_OBJECTS = 40654;
	static const int32 HOSTING_NOT_ENABLED = 40655;
	static const int32 UNSUPPORTED_GROUP_LEADERBOARD_OPERATION = 40656;
	static const int32 INVALID_PLAYER = 40657;
	static const int32 TOO_MANY_LISTENERS = 40658;
	static const int32 CREATE_FAILED = 40659;
	static const int32 CANNOT_GIVE_ITEM_TO_SELF = 40660;
	static const int32 INVALID_PARAMETER_VALUE = 40660;
	static const int32 ITEM_VERSION_MISMATCH = 40661;
	static const int32 ITEM_PUBLISH_ERROR = 40662;
	static const int32 ITEM_NOT_FOUND = 40663;
	static const int32 ITEM_NO_USES = 40664;
	static const int32 ITEM_CREATE_ERROR = 40665;
	static const int32 ITEM_COOL_DOWN = 40666;
	static const int32 TASK_STATE_NOT_FOUND = 40667;
	static const int32 ITEM_UPDATE_ERROR = 40668;
	static const int32 ITEM_DELETE_ERROR = 40669;
	static const int32 ITEM_INVALID_VALUE = 40670;
	static const int32 ITEM_SELL_OR_PURCHASE_REVERSAL_ERROR = 40671;
	static const int32 ITEM_GIFTED = 40672;
	static const int32 MISSING_APP_CONTEXT = 40673;
	static const int32 PUBLIC_KEY_IN_USE = 40674;
	static const int32 CUSTOM_ENTITY_NOT_FOUND = 40675;
	static const int32 ITEM_GIFTING_ERROR = 40676;
	static const int32 ITEM_NOT_AVAILABLE_ON_BLOCKCHAIN = 40677;
	static const int32 MISSING_BLOCKCHAIN_int32EGRATION = 40678;
	static const int32 MISSING_BLOCKCHAIN_USER_IDENTITY = 40679;
	static const int32 STACKABLE_ITEMS_NOT_PERMITTED_ON_BLOCKCHAIN = 40680;
	static const int32 BLOCKCHAIN_PUBLISH_IN_PROGRESS = 40681;
	static const int32 JWT_VERIFY_ERROR = 40682;
	static const int32 USER_ALREADY_EXISTS = 40683;
	static const int32 INVALID_EXT_AUTH_TYPE = 40684;
	static const int32 CUSTOM_ENTITY_INDEX_ERROR = 40685;
	static const int32 CUSTOM_ENTITY_UPDATE_FIELDS_ERROR = 40686;
	static const int32 INVALID_LOBBY_STEP_ALGOS = 40687;
	static const int32 INVALID_COMPOUND_RANGES = 40688;
	static const int32 MISSING_COMPOUND_RANGES = 40689;
	static const int32 MISSING_PING_DATA = 40690;
	static const int32 INVALID_PING_STEP_ALGO = 40691;
	static const int32 GROUP_NOT_FOUND = 40692;
	static const int32 SCRIPT_UPDATE_FAILED = 40693;
	static const int32 CUSTOM_ENTITY_REPLACE_ERROR = 40694;
	static const int32 CUSTOM_ENTITY_TYPE_IMPORT_ERROR = 40695;
	static const int32 CUSTOM_ENTITY_IMPORT_WARNING = 40696;
	static const int32 IDENTIFY_DORMANT_USERS_FOR_EXPORT_NOT_CONFIGURED = 40697;
	static const int32 IDENTIFY_DORMANT_USERS_FOR_EXPORT_ERROR = 40698;
	static const int32 UPDATE_SINGLETON_FAILED = 40699;
	static const int32 INVALID_STORE_ID = 40700;
	static const int32 METHOD_DEPRECATED = 40701;
	static const int32 INVALID_BILLING_PROVIDER_ID = 40702;
	static const int32 INVALID_STORE_DATA = 40703;
	static const int32 USER_FILE_MISSING = 40704;
	static const int32 GLOBAL_FILE_EXISTS = 40705;
	static const int32 INVALID_FILE_NAME = 40706;
	static const int32 FILE_TREE_VERSION_MISMATCH = 40707;
	static const int32 FILE_TREE_FOLDER_MISSING = 40708;
	static const int32 FOLDER_ALREADY_EXISTS = 40709;
	static const int32 INVALID_TREE_ID = 40710;
	static const int32 FILE_VERSION_MISMATCH = 40711;
	static const int32 INVALID_FOLDER_PATH = 40712;
	static const int32 FILENAME_MISMATCH = 40713;
	static const int32 FOLDERPATH_MISMATCH = 40714;
	static const int32 INVALID_CHARS_IN_STRING = 40715;
	static const int32 FOLDER_NOT_EMPTY = 40716;
	static const int32 INVALID_IMAGE_URL = 40717;
	static const int32 UNABLE_TO_UPDATE_PRICE = 40718;
	static const int32 UNABLE_TO_DELETE_PRICE = 40718;
	static const int32 WRONG_JOB_TYPE = 40719;
	static const int32 CLOUDCODE_JOB_NOT_RUNNING = 40720;
	static const int32 SCRIPT_HAS_DEPENDENCIES = 40721;
	static const int32 PEER_SERVICE_NOT_PUBLISHED = 40722;
	static const int32 MISSING_FOLDER_NAME = 40723;
	static const int32 UPLOLAD_IN_PROGRESS = 40724;
	static const int32 REFRESH_IN_PROGRESS = 40725;
	static const int32 REFRESH_INTERRUPTED = 40726;
	static const int32 GAMELIFT_ERROR = 40727;
	static const int32 GAMELIFT_LAUNCH_ERROR = 40728;
	static const int32 MAX_HOSTED_SERVERS_REACHED = 40729;
	static const int32 DUPLICATE_PACKET_ID = 40730;
	static const int32 FEATURE_NOT_SUPPORTED_BY_BILLING_PLAN = 40731;
	static const int32 FEATURE_CONFIGURATION_FAILURE = 40732;
	static const int32 IMPORT_MISSING_ENTRY = 40733;
	static const int32 PENDING_MEMBER_REQUEST_NOT_FOUND = 40734;
	static const int32 EVENT_TO_PROFILE_IDS_SIZE_EXCEEDS_MAXIMUM = 40735;
	static const int32 INVALID_CC_AND_BCC_EMAIL_ADDRESS = 40736;
	static const int32 NO_FRIENDS_FOUND = 40740;
	static const int32 PRODUCT_TRANSACTION_NOT_FOUND = 40741;
	static const int32 ITEM_DEF_NOT_FOUND = 40742;
	static const int32 ITEM_DEF_HAS_DEPENDENCIES = 40743;
	static const int32 TRANSFER_JOB_IDLE_TIMEOUT = 40744;
	static const int32 GROUP_MEMBER_ACL_MORE_RESTRICTIVE_THAN_OTHER = 40745;
	static const int32 GROUP_MEMBER_ACL_MUST_BE_READ_WRITE_FOR_UNOWNED_ENTITY = 40746;
	static const int32 GROUP_MEMBER_ACL_REQUIRED = 40747;
	static const int32 GROUP_TYPE_MAX_MEMBERS_EXCEEDED = 40748;
	static const int32 GROUP_ADD_MEMBER_EXISTS_DIFF_ROLE_ATTRIBS = 40749;
	static const int32 REDEMPTION_IN_PROGRESS = 40750;
	static const int32 REDEMPTION_FAILED = 40751;
	static const int32 REDEMPTION_FAILED_MAX_RETRIES = 40752;
	static const int32 REDEMPTION_CODE_TYPE_DISABLED = 40753;
	static const int32 INVALID_SCAN_CODE_FOR_TYPE = 40754;
	static const int32 REDEMPTION_CODE_TYPE_MISMATCH = 40755;
	static const int32 REDEMPTION_CODE_SCRIPT_FAILURE = 40756;
	static const int32 REDEMPTION_OF_CUSTOM_CODE_FAILED = 40757;
	static const int32 REDEMPTION_CODE_NOT_IN_PROGRESS = 40758;
	static const int32 REDEMPTION_CODE_ATTEMPT_ERROR = 40759;
	static const int32 REDEMPTION_CODE_ATTEMPT_MISMATCH = 40760;
	static const int32 REDEMPTION_CODE_ASYNC_BAD_RESPONSE = 40761;
	static const int32 REDEMPTION_CODE_BY_ID_NOT_FOUND = 40762;
	static const int32 REDEMPTION_CODE_ATTEMPTED_BY_REDEEMED_BY_MISMATCH = 40763;
	static const int32 REDEMPTION_CODE_ATTEMPT_DATA_INVALID = 40764;
	static const int32 REDEMPTION_CODE_MAX_FAILED_EXCEEDED_FOR_USER = 40765;
	static const int32 REDEMPTION_CODE_BLOCKCHAIN_PROXY_ERROR = 40766;
	static const int32 REDEMPTION_CODE_TYPE_NOT_ASYNC = 40767;
	static const int32 REDEMPTION_CODE_ASYNC_PROCESSING_TIMEOUT = 40768;
	static const int32 DUPLICATE_DIVISION_SET_CONFIG = 40770;
	static const int32 DIVISION_SET_INSTANCE_LEADERBOARDS_STILL_EXIST = 40771;
	static const int32 SINGLETON_ALREADY_EXISTS_FOR_USER = 40772;
	static const int32 CUSTOM_ENTITY_INCREMENT_SINGLETON_DATA_ERROR = 40773;
	static const int32 CUSTOM_ENTITY_COLLECTIONS_MAX_EXCEEDED = 40774;
	static const int32 IMPORT_PRECONDITION_ERROR = 40780;
	static const int32 REQUEST_FAILED = 40801;
	static const int32 RESET_QUESTS_FAILED = 40802;
	static const int32 RESET_ALL_QUESTS_AND_MILESTONES_FAILED = 40803;
	static const int32 MILESTONE_NOT_FOUND = 40804;
	static const int32 MILESTONE_CREATE_ERROR = 40805;
	static const int32 MILESTONE_UPDATE_ERROR = 40806;
	static const int32 MILESTONE_DELETE_ERROR = 40807;
	static const int32 MILESTONE_VERSION_ERROR = 40808;
	static const int32 QUEST_NOT_FOUND = 40809;
	static const int32 QUEST_CREATE_ERROR = 40810;
	static const int32 QUEST_UPDATE_ERROR = 40811;
	static const int32 QUEST_DELETE_ERROR = 40812;
	static const int32 QUEST_VERSION_ERROR = 40813;
	static const int32 QUEST_ADD_MILESTONE_ERROR = 40814;
	static const int32 QUEST_DELETE_MILESTONE_ERROR = 40815;
	static const int32 QUEST_REORDER_MILESTONES_ERROR = 40816;
	static const int32 PROMOTION_NOT_FOUND = 40820;
	static const int32 VERSION_MISMATCH = 40821;
	static const int32 UNSUPPORTED_CRITERIA_FOR_SHARDED_COLLECTIONS = 40822;
	static const int32 STEAM_ERROR = 40830;
	static const int32 INVALID_LEADERBOARD_TOURNAMENT_SETTING = 40840;
	static const int32 LEADERBOARD_EDIT_TOURNAMENT_SETTINGS_ERROR = 40841;
	static const int32 LEADERBOARD_SCORES_EXIST = 40842;
	static const int32 TOURNAMENT_SCORES_EXIST = 40843;
	static const int32 LEADERBOARD_DBVERSION_MISMATCH = 40844;
	static const int32 LEADERBOARD_API_DOES_NOT_APPLY = 40845;
	static const int32 LEADERBOARD_EXPIRED = 40846;
	static const int32 MISSING_CONFIG = 40900;
	static const int32 INVALID_SAML_RESP = 40901;
	static const int32 MISSING_PAGE_NAME = 40902;
	static const int32 INVALID_PAGE_NAME = 40903;
	static const int32 MALFORMED_RELAY_STATE = 40904;
	static const int32 INVALID_RESPONSE_ID = 40905;
	static const int32 LOGOUT_ERROR = 40906;
	static const int32 SCRIPT_EXISTS = 40907;
	static const int32 SCRIPT_DUPLICATE_EXISTS = 40908;
	static const int32 INVALID_UPLOAD_EXTENSION = 40909;
	static const int32 SCRIPT_TIMEOUT_ERROR = 40910;
	static const int32 SCRIPT_RHINO_ERROR = 40911;
	static const int32 SCRIPT_JAVA_ERROR = 40912;
	static const int32 GROUP_FILE_EXISTS = 40950;
	static const int32 OTHER_USER_ACL_REQUIRED = 40951;
	static const int32 GROUP_MEMBER_ACCESS_INVALID = 40952;
	static const int32 REUSED_PACKET_ID = 40953;

	
	static const int32 NO_TWITTER_CONSUMER_KEY = 500001;
	static const int32 NO_TWITTER_CONSUMER_SECRET = 500002;
	static const int32 INVALID_CONFIGURATION = 500003;
	static const int32 ERROR_GETTING_REQUEST_TOKEN = 500004;
	static const int32 ERROR_GETTING_ACCESS_TOKEN = 500005;

	
	static const int32 TWITTER_AUTH_ERROR = 500006;
	static const int32 TWITTER_ERROR = 500007;
	static const int32 FACEBOOK_ERROR = 500010;
	static const int32 FACEBOOK_SECRET_MISMATCH = 500011;
	static const int32 FACEBOOK_AUTHENTICATION_ERROR = 500012;
	static const int32 FACEBOOK_APPLICATION_TOKEN_REQUEST_ERROR = 500013;
	static const int32 FACEBOOK_BAD_APPLICATION_TOKEN_SIGNATURE = 500014;

	
	static const int32 UNSUPPORTED_SOCIAL_PLATFORM_CODE = 500020;
	static const int32 MEMCACHED_TIMEOUT = 503000;
	static const int32 NOT_TEAM_ADMIN = 550000;
	static const int32 NO_TEAM_ACCESS = 550001;
	static const int32 MISSING_COMPANY_RECORD = 550002;
	static const int32 TEAM_MEMBER_NOT_FOUND = 550003;
	static const int32 TEAM_MEMBER_NOT_ENABLED = 550004;
	static const int32 TEAM_MEMBER_NOT_ACTIVE = 550005;
	static const int32 TEAM_MEMBER_LOCKED = 550006;
	static const int32 INVALID_PASSWORD = 550007;
	static const int32 TOKEN_INVALID = 550008;
	static const int32 TOKEN_EXPIRED = 550009;
	static const int32 APP_NOT_FOUND = 550010;
	static const int32 TEMPLATE_GAME_NOT_FOUND = 550011;
	static const int32 INVALID_TEMPLATE_GAME_TEAM = 550012;
	static const int32 BASIC_AUTH_FAILURE = 550013;
	static const int32 EMAIL_MISMATCH = 550014;
	static const int32 EMAIL_ID_NOT_FOUND = 550015;
	static const int32 INVALID_AUTH_TYPE = 550016;
	static const int32 APIKEY_EXPIRED = 550017;
	static const int32 APIKEY_NOT_TEAM_SCOPE = 550018;
	static const int32 INVALID_API_KEY = 550019;
	static const int32 TEAM_ADMIN_API_DISABLED = 550020;
	static const int32 TEAM_ADMIN_AUTH_FAILURE = 550021;
	static const int32 INVALID_PASSWORD_CONTENT = 550022;
	static const int32 INVALID_APP_ACCESS = 550023;
	static const int32 INVALID_TEAM_ID = 550024;
	static const int32 MONGO_DB_EXCEPTION = 600001;
	static const int32 CONCURRENT_LOCK_ERROR = 600002;
	static const int32 USER_EXPORT_ERROR = 600003;
	static const int32 POST_SCORE_ON_BEHALF_OF_ERROR = 600004;
	static const int32 INVALID_USER_STATUS = 600005;
	static const int32 SLACK_WEBHOOK_SEND_ERROR = 600006;
	static const int32 SLACK_NOT_ENABLED_FOR_APP = 600007;
	static const int32 ERROR_AQUIRING_LOBBY_LOCK = 600008;
	static const int32 ERROR_SETTING_NEW_LOBBY_OWNER = 600009;
	static const int32 ERROR_SWITCHING_TEAMS = 600010;
	static const int32 DEPLOY_FAILED = 600011;
	static const int32 IMPORT_EXPORT_TASK_IN_PROGRESS = 600012;
	static const int32 BACKUP_REFERENCE_DATA_FAILED = 600013;
	static const int32 BUILDER_API_KEY_NOT_FOUND = 60100;
	static const int32 BUILDER_API_INVALID_KEY_SCOPE = 60101;
	static const int32 BUILDER_API_UPDATED_AT_MISMATCH = 60102;
	static const int32 BUILDER_API_TEAM_NAME_MISMATCH = 60103;
	static const int32 BUILDER_API_TEAM_HAS_APPS = 60104;
	static const int32 BUILDER_API_UNEXPECTED_EXCEPTION = 60105;
	static const int32 BUILDER_API_PARTIAL_TEAM_DELETION = 60106;
	static const int32 BUILDER_API_APP_DELETED = 60107;
	static const int32 BUILDER_API_APP_DISABLED = 60108;
	static const int32 BUILDER_API_APP_IS_LIVE = 60109;
	static const int32 BUILDER_API_APP_SUSPENDED = 60110;
	static const int32 BUILDER_API_CREATED_AT_MISMATCH = 60111;
	static const int32 PLAYSTATION_NETWORK_ERROR = 60200;
	static const int32 EMAIL_CC_MAX_SIZE_EXCEEDED = 60201;
	static const int32 EMAIL_BCC_MAX_SIZE_EXCEEDED = 60202;

	//RTT
	static const int32 RTT_LEFT_BY_CHOICE = 80000;
	static const int32 RTT_EVICTED = 80001;
	static const int32 RTT_LOST_CONNECTION = 80002;
	static const int32 RTT_TIMEOUT = 80100;
	static const int32 RTT_ROOM_READY = 80101;
	static const int32 RTT_ROOM_CANCELLED = 80102;
	static const int32 RTT_ERROR_ASSIGNING_ROOM = 80103;
	static const int32 RTT_ERROR_LAUNCHING_ROOM = 80104;
	static const int32 RTT_BY_REQUEST = 80105;
	static const int32 RTT_NO_LOBBIES_FOUND = 80200;
	static const int32 RTT_FIND_REQUEST_CANCELLED = 80201;
	static const int32 RTT_CLIENT_ERROR = 80300;

	//Relay Service
	static const int32 RS_CLIENT_ERROR = 90300;
	static const int32 CLIENT_NETWORK_ERROR_TIMEOUT = 90001;
	static const int32 CLIENT_UPLOAD_FILE_CANCELLED = 90100;
	static const int32 CLIENT_UPLOAD_FILE_TIMED_OUT = 90101;
	static const int32 CLIENT_UPLOAD_FILE_UNKNOWN = 90102;
	static const int32 CLIENT_DISABLED = 90200;
	static const int32 ITUNES_PURCHASE_ALREADY_CLAIMED = APPLE_TRANS_ID_ALREADY_CLAIMED;
	static const int32 CHILD_USER_MISSING = CHILD_PLAYER_MISSING;
	static const int32 DISABLED_APP = DISABLED_GAME;
	static const int32 APPS_NOT_IN_SAME_COMPANY = GAMES_NOT_IN_SAME_COMPANY;
	static const int32 APP_LIMIT_REACHED = GAME_LIMIT_REACHED;
	static const int32 APP_PARENT_MISMATCH = GAME_PARENT_MISMATCH;
	static const int32 APP_RUNSTATE_DISABLED = GAME_RUNSTATE_DISABLED;
	static const int32 APP_VERSION_NOT_SUPPORTED = GAME_VERSION_NOT_SUPPORTED;
	static const int32 APP_VERSION_NO_LONGER_SUPPORTED = GAME_VERSION_NOT_SUPPORTED;
	static const int32 IMPORT_MISSING_APP_DATA = IMPORT_MISSING_GAME_DATA;
	static const int32 INVALID_APP_ID = INVALID_GAME_ID;
	static const int32 INVALID_USER_ID = INVALID_PLAYER_ID;
	static const int32 INVALID_USER_STATISTICS_EVENT_NAME = INVALID_PLAYER_STATISTICS_EVENT_NAME;
	static const int32 MISSING_APP_PARENT = MISSING_GAME_PARENT;
	static const int32 MISSING_USER_ID = MISSING_PLAYER_ID;
	static const int32 MISSING_USER_PARENT = MISSING_PLAYER_PARENT;
	static const int32 USER_PARENT_MISMATCH = PLAYER_PARENT_MISMATCH;
	static const int32 USER_SESSION_EXPIRED = PLAYER_SESSION_EXPIRED;
	static const int32 USER_SESSION_LOGGED_OUT = PLAYER_SESSION_LOGGED_OUT;
	static const int32 USER_SESSION_MISMATCH = PLAYER_SESSION_MISMATCH;
	static const int32 UNABLE_TO_VALIDATE_USER = UNABLE_TO_VALIDATE_PLAYER;
};
using ReasonCode = ReasonCodes;