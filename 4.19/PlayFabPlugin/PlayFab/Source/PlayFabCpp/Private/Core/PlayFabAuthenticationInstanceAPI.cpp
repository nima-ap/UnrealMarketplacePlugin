//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "Core/PlayFabAuthenticationInstanceAPI.h"
#include "Core/PlayFabSettings.h"
#include "Core/PlayFabResultHandler.h"
#include "PlayFab.h"

using namespace PlayFab;
using namespace PlayFab::AuthenticationModels;

UPlayFabAuthenticationInstanceAPI::UPlayFabAuthenticationInstanceAPI()
{
}

UPlayFabAuthenticationInstanceAPI::UPlayFabAuthenticationInstanceAPI(TSharedPtr<UPlayFabAPISettings> apiSettings)
{
    this->settings = MoveTemp(apiSettings);
}

UPlayFabAuthenticationInstanceAPI::UPlayFabAuthenticationInstanceAPI(TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->authContext = MoveTemp(authenticationContext);
}

UPlayFabAuthenticationInstanceAPI::UPlayFabAuthenticationInstanceAPI(TSharedPtr<UPlayFabAPISettings> apiSettings, TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->settings = MoveTemp(apiSettings);
    this->authContext = MoveTemp(authenticationContext);
}

UPlayFabAuthenticationInstanceAPI::~UPlayFabAuthenticationInstanceAPI()
{
}

TSharedPtr<UPlayFabAPISettings> UPlayFabAuthenticationInstanceAPI::GetSettings() const
{
    return this->settings;
}

int UPlayFabAuthenticationInstanceAPI::GetPendingCalls() const
{
    return PlayFabRequestHandler::GetPendingCalls();
}

void UPlayFabAuthenticationInstanceAPI::SetSettings(TSharedPtr<UPlayFabAPISettings> apiSettings)
{
    this->settings = MoveTemp(apiSettings);
}

TSharedPtr<UPlayFabAuthenticationContext> UPlayFabAuthenticationInstanceAPI::GetAuthenticationContext() const
{
    return this->authContext;
}

void UPlayFabAuthenticationInstanceAPI::SetAuthenticationContext(TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->authContext = MoveTemp(authenticationContext);
}

void UPlayFabAuthenticationInstanceAPI::ForgetAllCredentials()
{
    if (!this->authContext.IsValid())
        return;

    this->authContext->ForgetAllCredentials();
}

TSharedPtr<UPlayFabAuthenticationContext> UPlayFabAuthenticationInstanceAPI::GetOrCreateAuthenticationContext()
{
    if (!this->authContext.IsValid())
        this->authContext = TSharedPtr<UPlayFabAuthenticationContext>(NewObject<UPlayFabAuthenticationContext>((UObject*)GetTransientPackage(), NAME_None, RF_Standalone));

    return this->authContext;
}

bool UPlayFabAuthenticationInstanceAPI::GetEntityToken(
    AuthenticationModels::FGetEntityTokenRequest& request,
    const FGetEntityTokenDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    FString authKey; FString authValue;
    if (request.AuthenticationContext.IsValid()) {
        if (request.AuthenticationContext->GetEntityToken().Len() > 0) {
            authKey = TEXT("X-EntityToken"); authValue = request.AuthenticationContext->GetEntityToken();
        } else if (request.AuthenticationContext->GetClientSessionTicket().Len() > 0) {
            authKey = TEXT("X-Authorization"); authValue = request.AuthenticationContext->GetClientSessionTicket();
        } else if (request.AuthenticationContext->GetDeveloperSecretKey().Len() > 0) {
            authKey = TEXT("X-SecretKey"); authValue = request.AuthenticationContext->GetDeveloperSecretKey();
        }
    }
    else {
        this->GetOrCreateAuthenticationContext();
        if (this->authContext->GetEntityToken().Len() > 0) {
            authKey = TEXT("X-EntityToken"); authValue = this->authContext->GetEntityToken();
        } else if (this->authContext->GetClientSessionTicket().Len() > 0) {
            authKey = TEXT("X-Authorization"); authValue = this->authContext->GetClientSessionTicket();
        } else if (this->authContext->GetDeveloperSecretKey().Len() > 0) {
            authKey = TEXT("X-SecretKey"); authValue = this->authContext->GetDeveloperSecretKey();
        }
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/Authentication/GetEntityToken")) : this->settings->GetUrl(TEXT("/Authentication/GetEntityToken")), request.toJSONString(), authKey, authValue);
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabAuthenticationInstanceAPI::OnGetEntityTokenResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabAuthenticationInstanceAPI::OnGetEntityTokenResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetEntityTokenDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    AuthenticationModels::FGetEntityTokenResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        if (outResult.EntityToken.Len() > 0)
            this->GetOrCreateAuthenticationContext()->SetEntityToken(outResult.EntityToken);
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}
