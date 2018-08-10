//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "PlayFabSettings.h"
#include "PlayFabCommon.h"

namespace PlayFab
{
	const FString PlayFabSettings::sdkVersion = IPlayFabCommonModuleInterface::Get().GetSdkVersion();
	const FString PlayFabSettings::buildIdentifier = IPlayFabCommonModuleInterface::Get().GetBuildIdentifier();
	const FString PlayFabSettings::versionString = IPlayFabCommonModuleInterface::Get().GetVersionString();

	const FString PlayFabSettings::AD_TYPE_IDFA = IPlayFabCommonModuleInterface::Get().GetAD_TYPE_IDFA();
	const FString PlayFabSettings::AD_TYPE_ANDROID_ID = IPlayFabCommonModuleInterface::Get().GetAD_TYPE_ANDROID_ID();

	// Getters
	bool PlayFabSettings::GetUseDevelopmentEnvironment()
	{
		return IPlayFabCommonModuleInterface::Get().GetUseDevelopmentEnvironment();
	}
	FString PlayFabSettings::GetServerURL()
	{
		return IPlayFabCommonModuleInterface::Get().GetServerURL();
	}
	FString PlayFabSettings::GetDevelopmentEnvironmentURL()
	{
		return IPlayFabCommonModuleInterface::Get().GetDevelopmentEnvironmentURL();
	}
	FString PlayFabSettings::GetProductionEnvironmentURL()
	{
		return IPlayFabCommonModuleInterface::Get().GetProductionEnvironmentURL();
	}
	FString PlayFabSettings::GetTitleId()
	{
		return IPlayFabCommonModuleInterface::Get().GetTitleId();
	}
	FString PlayFabSettings::GetClientSessionTicket()
	{
		return IPlayFabCommonModuleInterface::Get().GetClientSessionTicket();
	}
	FString PlayFabSettings::GetDeveloperSecretKey()
	{
		return IPlayFabCommonModuleInterface::Get().GetDeveloperSecretKey();
	}
	FString PlayFabSettings::GetEntityToken()
	{
		return IPlayFabCommonModuleInterface::Get().GetEntityToken();
	}
	FString PlayFabSettings::GetAdvertisingIdType()
	{
		return IPlayFabCommonModuleInterface::Get().GetAdvertisingIdType();
	}
	FString PlayFabSettings::GetAdvertisingIdValue()
	{
		return IPlayFabCommonModuleInterface::Get().GetAdvertisingIdValue();
	}
	bool PlayFabSettings::GetDisableAdvertising()
	{
		return IPlayFabCommonModuleInterface::Get().GetDisableAdvertising();
	}

	// Setters
	void PlayFabSettings::SetUseDevelopmentEnvironment(bool useDevelopmentEnvironment)
	{
		IPlayFabCommonModuleInterface::Get().SetUseDevelopmentEnvironment(useDevelopmentEnvironment);
	}
	void PlayFabSettings::SetServerURL(const FString&  serverURL)
	{
		IPlayFabCommonModuleInterface::Get().SetServerURL(serverURL);
	}
	void PlayFabSettings::SetDevelopmentEnvironmentURL(const FString&  developmentEnvironmentURL)
	{
		IPlayFabCommonModuleInterface::Get().SetDevelopmentEnvironmentURL(developmentEnvironmentURL);
	}
	void PlayFabSettings::SetProductionEnvironmentURL(const FString&  productionEnvironmentURL)
	{
		IPlayFabCommonModuleInterface::Get().SetProductionEnvironmentURL(productionEnvironmentURL);
	}
	void PlayFabSettings::SetTitleId(const FString&  titleId)
	{
		IPlayFabCommonModuleInterface::Get().SetTitleId(titleId);
	}
	void PlayFabSettings::SetClientSessionTicket(const FString&  clientSessionTicket)
	{
		IPlayFabCommonModuleInterface::Get().SetClientSessionTicket(clientSessionTicket);
	}
	void PlayFabSettings::SetDeveloperSecretKey(const FString&  developerSecretKey)
	{
		IPlayFabCommonModuleInterface::Get().SetDeveloperSecretKey(developerSecretKey);
	}
	void PlayFabSettings::SetEntityToken(const FString&  entityToken)
	{
		IPlayFabCommonModuleInterface::Get().SetEntityToken(entityToken);
	}
	void PlayFabSettings::SetAdvertisingIdType(const FString&  advertisingIdType)
	{
		IPlayFabCommonModuleInterface::Get().SetAdvertisingIdType(advertisingIdType);
	}
	void PlayFabSettings::SetAdvertisingIdValue(const FString&  advertisingIdValue)
	{
		IPlayFabCommonModuleInterface::Get().SetAdvertisingIdValue(advertisingIdValue);
	}
	void PlayFabSettings::SetDisableAdvertising(bool disableAdvertising)
	{
		IPlayFabCommonModuleInterface::Get().SetDisableAdvertising(disableAdvertising);
	}
}
