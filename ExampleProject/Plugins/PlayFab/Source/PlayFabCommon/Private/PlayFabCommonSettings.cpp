//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "PlayFabCommonSettings.h"

namespace PlayFabCommon
{
    const FString PlayFabCommonSettings::sdkVersion = "0.0.180709";
    const FString PlayFabCommonSettings::buildIdentifier = "unrealcppsdk_manual";
    const FString PlayFabCommonSettings::versionString = "UE4SDK-0.0.180709";

    bool PlayFabCommonSettings::useDevelopmentEnvironment = false;

	FString PlayFabCommonSettings::serverURL;
    FString PlayFabCommonSettings::developmentEnvironmentURL = ".playfabsandbox.com";
    FString PlayFabCommonSettings::productionEnvironmentURL = ".playfabapi.com";
    
	FString PlayFabCommonSettings::titleId;
	
    FString PlayFabCommonSettings::clientSessionTicket;
    FString PlayFabCommonSettings::developerSecretKey;
    FString PlayFabCommonSettings::entityToken;
    FString PlayFabCommonSettings::advertisingIdType;
    FString PlayFabCommonSettings::advertisingIdValue;

    bool PlayFabCommonSettings::disableAdvertising = false;
    const FString PlayFabCommonSettings::AD_TYPE_IDFA = "Idfa";
    const FString PlayFabCommonSettings::AD_TYPE_ANDROID_ID = "Adid";
	
	FString PlayFabCommonSettings::playFabApiSecretKey;
	FString PlayFabCommonSettings::photonRealtimeAppId;
	FString PlayFabCommonSettings::photonTurnbasedAppId;
	FString PlayFabCommonSettings::photonChatAppId;
}
