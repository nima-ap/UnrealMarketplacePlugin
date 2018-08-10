//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "Core/PlayFabGroupsAPI.h"
#include "Core/PlayFabSettings.h"
#include "Core/PlayFabResultHandler.h"
#include "PlayFab.h"

using namespace PlayFab;
using namespace PlayFab::GroupsModels;

UPlayFabGroupsAPI::UPlayFabGroupsAPI() {}

UPlayFabGroupsAPI::~UPlayFabGroupsAPI() {}

int UPlayFabGroupsAPI::GetPendingCalls() const
{
    return PlayFabRequestHandler::GetPendingCalls();
}

FString UPlayFabGroupsAPI::GetBuildIdentifier() const
{
    return PlayFabSettings::buildIdentifier;
}

void UPlayFabGroupsAPI::SetTitleId(const FString& titleId)
{
	PlayFabSettings::SetTitleId(titleId);
}

void UPlayFabGroupsAPI::SetDevSecretKey(const FString& developerSecretKey)
{
    PlayFabSettings::SetDeveloperSecretKey(developerSecretKey);
}

bool UPlayFabGroupsAPI::AcceptGroupApplication(
    GroupsModels::FAcceptGroupApplicationRequest& request,
    const FAcceptGroupApplicationDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/AcceptGroupApplication")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnAcceptGroupApplicationResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnAcceptGroupApplicationResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FAcceptGroupApplicationDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FEmptyResult outResult;
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

bool UPlayFabGroupsAPI::AcceptGroupInvitation(
    GroupsModels::FAcceptGroupInvitationRequest& request,
    const FAcceptGroupInvitationDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/AcceptGroupInvitation")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnAcceptGroupInvitationResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnAcceptGroupInvitationResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FAcceptGroupInvitationDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FEmptyResult outResult;
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

bool UPlayFabGroupsAPI::AddMembers(
    GroupsModels::FAddMembersRequest& request,
    const FAddMembersDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/AddMembers")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnAddMembersResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnAddMembersResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FAddMembersDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FEmptyResult outResult;
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

bool UPlayFabGroupsAPI::ApplyToGroup(
    GroupsModels::FApplyToGroupRequest& request,
    const FApplyToGroupDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/ApplyToGroup")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnApplyToGroupResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnApplyToGroupResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FApplyToGroupDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FApplyToGroupResponse outResult;
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

bool UPlayFabGroupsAPI::BlockEntity(
    GroupsModels::FBlockEntityRequest& request,
    const FBlockEntityDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/BlockEntity")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnBlockEntityResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnBlockEntityResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FBlockEntityDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FEmptyResult outResult;
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

bool UPlayFabGroupsAPI::ChangeMemberRole(
    GroupsModels::FChangeMemberRoleRequest& request,
    const FChangeMemberRoleDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/ChangeMemberRole")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnChangeMemberRoleResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnChangeMemberRoleResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FChangeMemberRoleDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FEmptyResult outResult;
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

bool UPlayFabGroupsAPI::CreateGroup(
    GroupsModels::FCreateGroupRequest& request,
    const FCreateGroupDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/CreateGroup")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnCreateGroupResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnCreateGroupResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FCreateGroupDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FCreateGroupResponse outResult;
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

bool UPlayFabGroupsAPI::CreateRole(
    GroupsModels::FCreateGroupRoleRequest& request,
    const FCreateRoleDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/CreateRole")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnCreateRoleResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnCreateRoleResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FCreateRoleDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FCreateGroupRoleResponse outResult;
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

bool UPlayFabGroupsAPI::DeleteGroup(
    GroupsModels::FDeleteGroupRequest& request,
    const FDeleteGroupDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/DeleteGroup")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnDeleteGroupResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnDeleteGroupResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FDeleteGroupDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FEmptyResult outResult;
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

bool UPlayFabGroupsAPI::DeleteRole(
    GroupsModels::FDeleteRoleRequest& request,
    const FDeleteRoleDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/DeleteRole")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnDeleteRoleResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnDeleteRoleResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FDeleteRoleDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FEmptyResult outResult;
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

bool UPlayFabGroupsAPI::GetGroup(
    GroupsModels::FGetGroupRequest& request,
    const FGetGroupDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/GetGroup")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnGetGroupResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnGetGroupResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetGroupDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FGetGroupResponse outResult;
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

bool UPlayFabGroupsAPI::InviteToGroup(
    GroupsModels::FInviteToGroupRequest& request,
    const FInviteToGroupDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/InviteToGroup")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnInviteToGroupResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnInviteToGroupResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FInviteToGroupDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FInviteToGroupResponse outResult;
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

bool UPlayFabGroupsAPI::IsMember(
    GroupsModels::FIsMemberRequest& request,
    const FIsMemberDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/IsMember")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnIsMemberResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnIsMemberResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FIsMemberDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FIsMemberResponse outResult;
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

bool UPlayFabGroupsAPI::ListGroupApplications(
    GroupsModels::FListGroupApplicationsRequest& request,
    const FListGroupApplicationsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/ListGroupApplications")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnListGroupApplicationsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnListGroupApplicationsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FListGroupApplicationsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FListGroupApplicationsResponse outResult;
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

bool UPlayFabGroupsAPI::ListGroupBlocks(
    GroupsModels::FListGroupBlocksRequest& request,
    const FListGroupBlocksDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/ListGroupBlocks")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnListGroupBlocksResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnListGroupBlocksResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FListGroupBlocksDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FListGroupBlocksResponse outResult;
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

bool UPlayFabGroupsAPI::ListGroupInvitations(
    GroupsModels::FListGroupInvitationsRequest& request,
    const FListGroupInvitationsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/ListGroupInvitations")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnListGroupInvitationsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnListGroupInvitationsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FListGroupInvitationsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FListGroupInvitationsResponse outResult;
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

bool UPlayFabGroupsAPI::ListGroupMembers(
    GroupsModels::FListGroupMembersRequest& request,
    const FListGroupMembersDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/ListGroupMembers")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnListGroupMembersResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnListGroupMembersResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FListGroupMembersDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FListGroupMembersResponse outResult;
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

bool UPlayFabGroupsAPI::ListMembership(
    GroupsModels::FListMembershipRequest& request,
    const FListMembershipDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/ListMembership")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnListMembershipResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnListMembershipResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FListMembershipDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FListMembershipResponse outResult;
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

bool UPlayFabGroupsAPI::ListMembershipOpportunities(
    GroupsModels::FListMembershipOpportunitiesRequest& request,
    const FListMembershipOpportunitiesDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/ListMembershipOpportunities")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnListMembershipOpportunitiesResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnListMembershipOpportunitiesResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FListMembershipOpportunitiesDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FListMembershipOpportunitiesResponse outResult;
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

bool UPlayFabGroupsAPI::RemoveGroupApplication(
    GroupsModels::FRemoveGroupApplicationRequest& request,
    const FRemoveGroupApplicationDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/RemoveGroupApplication")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnRemoveGroupApplicationResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnRemoveGroupApplicationResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FRemoveGroupApplicationDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FEmptyResult outResult;
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

bool UPlayFabGroupsAPI::RemoveGroupInvitation(
    GroupsModels::FRemoveGroupInvitationRequest& request,
    const FRemoveGroupInvitationDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/RemoveGroupInvitation")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnRemoveGroupInvitationResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnRemoveGroupInvitationResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FRemoveGroupInvitationDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FEmptyResult outResult;
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

bool UPlayFabGroupsAPI::RemoveMembers(
    GroupsModels::FRemoveMembersRequest& request,
    const FRemoveMembersDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/RemoveMembers")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnRemoveMembersResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnRemoveMembersResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FRemoveMembersDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FEmptyResult outResult;
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

bool UPlayFabGroupsAPI::UnblockEntity(
    GroupsModels::FUnblockEntityRequest& request,
    const FUnblockEntityDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/UnblockEntity")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnUnblockEntityResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnUnblockEntityResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUnblockEntityDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FEmptyResult outResult;
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

bool UPlayFabGroupsAPI::UpdateGroup(
    GroupsModels::FUpdateGroupRequest& request,
    const FUpdateGroupDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/UpdateGroup")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnUpdateGroupResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnUpdateGroupResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUpdateGroupDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FUpdateGroupResponse outResult;
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

bool UPlayFabGroupsAPI::UpdateRole(
    GroupsModels::FUpdateGroupRoleRequest& request,
    const FUpdateRoleDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFab, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::getURL(TEXT("/Group/UpdateRole")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabGroupsAPI::OnUpdateRoleResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabGroupsAPI::OnUpdateRoleResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUpdateRoleDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    GroupsModels::FUpdateGroupRoleResponse outResult;
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

