//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "Core/PlayFabMatchmakerAPI.h"
#include "Core/PlayFabSettings.h"
#include "Core/PlayFabResultHandler.h"
#include "PlayFab.h"

using namespace PlayFab;
using namespace PlayFab::MatchmakerModels;

UPlayFabMatchmakerAPI::UPlayFabMatchmakerAPI() {}

UPlayFabMatchmakerAPI::~UPlayFabMatchmakerAPI() {}

int UPlayFabMatchmakerAPI::GetPendingCalls() const
{
    return PlayFabRequestHandler::GetPendingCalls();
}

FString UPlayFabMatchmakerAPI::GetBuildIdentifier() const
{
    return PlayFabSettings::buildIdentifier;
}

void UPlayFabMatchmakerAPI::SetTitleId(const FString& titleId)
{
	PlayFabSettings::SetTitleId(titleId);
}

void UPlayFabMatchmakerAPI::SetDevSecretKey(const FString& developerSecretKey)
{
    PlayFabSettings::SetDeveloperSecretKey(developerSecretKey);
}

bool UPlayFabMatchmakerAPI::AuthUser(
    MatchmakerModels::FAuthUserRequest& request,
    const FAuthUserDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetDeveloperSecretKey().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must first set your PlayFab developerSecretKey to use this function (Unreal Settings Menu, or in C++ code)"));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Matchmaker/AuthUser")), request.toJSONString(), TEXT("X-SecretKey"), PlayFabSettings::GetDeveloperSecretKey());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabMatchmakerAPI::OnAuthUserResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabMatchmakerAPI::OnAuthUserResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FAuthUserDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    MatchmakerModels::FAuthUserResponse outResult;
    FPlayFabError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabMatchmakerAPI::PlayerJoined(
    MatchmakerModels::FPlayerJoinedRequest& request,
    const FPlayerJoinedDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetDeveloperSecretKey().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must first set your PlayFab developerSecretKey to use this function (Unreal Settings Menu, or in C++ code)"));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Matchmaker/PlayerJoined")), request.toJSONString(), TEXT("X-SecretKey"), PlayFabSettings::GetDeveloperSecretKey());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabMatchmakerAPI::OnPlayerJoinedResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabMatchmakerAPI::OnPlayerJoinedResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FPlayerJoinedDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    MatchmakerModels::FPlayerJoinedResponse outResult;
    FPlayFabError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabMatchmakerAPI::PlayerLeft(
    MatchmakerModels::FPlayerLeftRequest& request,
    const FPlayerLeftDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetDeveloperSecretKey().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must first set your PlayFab developerSecretKey to use this function (Unreal Settings Menu, or in C++ code)"));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Matchmaker/PlayerLeft")), request.toJSONString(), TEXT("X-SecretKey"), PlayFabSettings::GetDeveloperSecretKey());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabMatchmakerAPI::OnPlayerLeftResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabMatchmakerAPI::OnPlayerLeftResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FPlayerLeftDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    MatchmakerModels::FPlayerLeftResponse outResult;
    FPlayFabError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabMatchmakerAPI::StartGame(
    MatchmakerModels::FStartGameRequest& request,
    const FStartGameDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetDeveloperSecretKey().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must first set your PlayFab developerSecretKey to use this function (Unreal Settings Menu, or in C++ code)"));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Matchmaker/StartGame")), request.toJSONString(), TEXT("X-SecretKey"), PlayFabSettings::GetDeveloperSecretKey());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabMatchmakerAPI::OnStartGameResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabMatchmakerAPI::OnStartGameResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FStartGameDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    MatchmakerModels::FStartGameResponse outResult;
    FPlayFabError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabMatchmakerAPI::UserInfo(
    MatchmakerModels::FUserInfoRequest& request,
    const FUserInfoDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetDeveloperSecretKey().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must first set your PlayFab developerSecretKey to use this function (Unreal Settings Menu, or in C++ code)"));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Matchmaker/UserInfo")), request.toJSONString(), TEXT("X-SecretKey"), PlayFabSettings::GetDeveloperSecretKey());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabMatchmakerAPI::OnUserInfoResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabMatchmakerAPI::OnUserInfoResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUserInfoDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    MatchmakerModels::FUserInfoResponse outResult;
    FPlayFabError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

