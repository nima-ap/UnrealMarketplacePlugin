//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "PlayFabCommonSettings.h"

namespace PlayFabCommon
{
    const FString PlayFabCommonSettings::sdkVersion = "1.0.180809";
    const FString PlayFabCommonSettings::buildIdentifier = "default_manual_build";
    const FString PlayFabCommonSettings::versionString = "UE4MKPL-1.0.180809";

	FString PlayFabCommonSettings::serverURL;
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
