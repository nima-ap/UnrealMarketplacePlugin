//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "Core/PlayFabDataInstanceAPI.h"
#include "Core/PlayFabSettings.h"
#include "Core/PlayFabResultHandler.h"
#include "PlayFab.h"

using namespace PlayFab;
using namespace PlayFab::DataModels;

UPlayFabDataInstanceAPI::UPlayFabDataInstanceAPI()
{
}

UPlayFabDataInstanceAPI::UPlayFabDataInstanceAPI(TSharedPtr<UPlayFabAPISettings> apiSettings)
{
    this->settings = MoveTemp(apiSettings);
}

UPlayFabDataInstanceAPI::UPlayFabDataInstanceAPI(TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->authContext = MoveTemp(authenticationContext);
}

UPlayFabDataInstanceAPI::UPlayFabDataInstanceAPI(TSharedPtr<UPlayFabAPISettings> apiSettings, TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->settings = MoveTemp(apiSettings);
    this->authContext = MoveTemp(authenticationContext);
}

UPlayFabDataInstanceAPI::~UPlayFabDataInstanceAPI()
{
}

TSharedPtr<UPlayFabAPISettings> UPlayFabDataInstanceAPI::GetSettings() const
{
    return this->settings;
}

int UPlayFabDataInstanceAPI::GetPendingCalls() const
{
    return PlayFabRequestHandler::GetPendingCalls();
}

void UPlayFabDataInstanceAPI::SetSettings(TSharedPtr<UPlayFabAPISettings> apiSettings)
{
    this->settings = MoveTemp(apiSettings);
}

TSharedPtr<UPlayFabAuthenticationContext> UPlayFabDataInstanceAPI::GetAuthenticationContext() const
{
    return this->authContext;
}

void UPlayFabDataInstanceAPI::SetAuthenticationContext(TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->authContext = MoveTemp(authenticationContext);
}

void UPlayFabDataInstanceAPI::ForgetAllCredentials()
{
    if (!this->authContext.IsValid())
        return;

    this->authContext->ForgetAllCredentials();
}

TSharedPtr<UPlayFabAuthenticationContext> UPlayFabDataInstanceAPI::GetOrCreateAuthenticationContext()
{
    if (!this->authContext.IsValid())
        this->authContext = TSharedPtr<UPlayFabAuthenticationContext>(NewObject<UPlayFabAuthenticationContext>((UObject*)GetTransientPackage(), NAME_None, RF_Standalone));

    return this->authContext;
}

bool UPlayFabDataInstanceAPI::AbortFileUploads(
    DataModels::FAbortFileUploadsRequest& request,
    const FAbortFileUploadsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/File/AbortFileUploads")) : this->settings->GetUrl(TEXT("/File/AbortFileUploads")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabDataInstanceAPI::OnAbortFileUploadsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabDataInstanceAPI::OnAbortFileUploadsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FAbortFileUploadsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    DataModels::FAbortFileUploadsResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabDataInstanceAPI::DeleteFiles(
    DataModels::FDeleteFilesRequest& request,
    const FDeleteFilesDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/File/DeleteFiles")) : this->settings->GetUrl(TEXT("/File/DeleteFiles")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabDataInstanceAPI::OnDeleteFilesResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabDataInstanceAPI::OnDeleteFilesResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FDeleteFilesDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    DataModels::FDeleteFilesResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabDataInstanceAPI::FinalizeFileUploads(
    DataModels::FFinalizeFileUploadsRequest& request,
    const FFinalizeFileUploadsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/File/FinalizeFileUploads")) : this->settings->GetUrl(TEXT("/File/FinalizeFileUploads")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabDataInstanceAPI::OnFinalizeFileUploadsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabDataInstanceAPI::OnFinalizeFileUploadsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FFinalizeFileUploadsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    DataModels::FFinalizeFileUploadsResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabDataInstanceAPI::GetFiles(
    DataModels::FGetFilesRequest& request,
    const FGetFilesDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/File/GetFiles")) : this->settings->GetUrl(TEXT("/File/GetFiles")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabDataInstanceAPI::OnGetFilesResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabDataInstanceAPI::OnGetFilesResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetFilesDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    DataModels::FGetFilesResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabDataInstanceAPI::GetObjects(
    DataModels::FGetObjectsRequest& request,
    const FGetObjectsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/Object/GetObjects")) : this->settings->GetUrl(TEXT("/Object/GetObjects")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabDataInstanceAPI::OnGetObjectsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabDataInstanceAPI::OnGetObjectsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetObjectsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    DataModels::FGetObjectsResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabDataInstanceAPI::InitiateFileUploads(
    DataModels::FInitiateFileUploadsRequest& request,
    const FInitiateFileUploadsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/File/InitiateFileUploads")) : this->settings->GetUrl(TEXT("/File/InitiateFileUploads")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabDataInstanceAPI::OnInitiateFileUploadsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabDataInstanceAPI::OnInitiateFileUploadsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FInitiateFileUploadsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    DataModels::FInitiateFileUploadsResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

bool UPlayFabDataInstanceAPI::SetObjects(
    DataModels::FSetObjectsRequest& request,
    const FSetObjectsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/Object/SetObjects")) : this->settings->GetUrl(TEXT("/Object/SetObjects")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabDataInstanceAPI::OnSetObjectsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabDataInstanceAPI::OnSetObjectsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FSetObjectsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    DataModels::FSetObjectsResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}
