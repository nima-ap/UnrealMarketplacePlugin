//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


 #include "PlayFabRuntimeSettings.h"

//////////////////////////////////////////////////////////////////////////
// UPlayFabRuntimeSettings

UPlayFabRuntimeSettings::UPlayFabRuntimeSettings()
    : bUseDevelopmentEnvironment(false)
    , DevelopmentEnvironmentURL(TEXT(".playfabsandbox.com"))
    , ProductionEnvironmentURL(TEXT(".playfabapi.com"))
    , TitleId()
    , DeveloperSecretKey()
{
}
