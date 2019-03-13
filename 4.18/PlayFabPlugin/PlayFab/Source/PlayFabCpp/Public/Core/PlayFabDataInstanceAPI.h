//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "Core/PlayFabError.h"
#include "Core/PlayFabDataDataModels.h"
#include "Core/PlayFabSettings.h"
#include "PlayFabAPISettings.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"

namespace PlayFab
{
    /**
     * Main interface for PlayFab Sdk, specifically all Data APIs
     */
    class PLAYFABCPP_API UPlayFabDataInstanceAPI
    {
    public:
        DECLARE_DELEGATE_OneParam(FAbortFileUploadsDelegate, const DataModels::FAbortFileUploadsResponse&);
        DECLARE_DELEGATE_OneParam(FDeleteFilesDelegate, const DataModels::FDeleteFilesResponse&);
        DECLARE_DELEGATE_OneParam(FFinalizeFileUploadsDelegate, const DataModels::FFinalizeFileUploadsResponse&);
        DECLARE_DELEGATE_OneParam(FGetFilesDelegate, const DataModels::FGetFilesResponse&);
        DECLARE_DELEGATE_OneParam(FGetObjectsDelegate, const DataModels::FGetObjectsResponse&);
        DECLARE_DELEGATE_OneParam(FInitiateFileUploadsDelegate, const DataModels::FInitiateFileUploadsResponse&);
        DECLARE_DELEGATE_OneParam(FSetObjectsDelegate, const DataModels::FSetObjectsResponse&);


    private:
        TSharedPtr<UPlayFabAPISettings> settings;
        TSharedPtr<UPlayFabAuthenticationContext> authContext;
    
    public:
        UPlayFabDataInstanceAPI();
        explicit UPlayFabDataInstanceAPI(TSharedPtr<UPlayFabAPISettings> apiSettings);
        explicit UPlayFabDataInstanceAPI(TSharedPtr<UPlayFabAuthenticationContext> authenticationContext);
        UPlayFabDataInstanceAPI(TSharedPtr<UPlayFabAPISettings> apiSettings, TSharedPtr<UPlayFabAuthenticationContext> authenticationContext);
        ~UPlayFabDataInstanceAPI();
        UPlayFabDataInstanceAPI(const UPlayFabDataInstanceAPI& source) = delete; // disable copy
        UPlayFabDataInstanceAPI(UPlayFabDataInstanceAPI&&) = delete; // disable move
        UPlayFabDataInstanceAPI& operator=(const UPlayFabDataInstanceAPI& source) = delete; // disable assignment
        UPlayFabDataInstanceAPI& operator=(UPlayFabDataInstanceAPI&& other) = delete; // disable move assignment

        int GetPendingCalls() const;
        TSharedPtr<UPlayFabAPISettings> GetSettings() const;
        void SetSettings(TSharedPtr<UPlayFabAPISettings> apiSettings);
        TSharedPtr<UPlayFabAuthenticationContext> GetAuthenticationContext() const;
        void SetAuthenticationContext(TSharedPtr<UPlayFabAuthenticationContext> authenticationContext);
        void ForgetAllCredentials();

    private:
        TSharedPtr<UPlayFabAuthenticationContext> GetOrCreateAuthenticationContext();
    
    public:


        // ------------ Generated API calls
        /**
         * Abort pending file uploads to an entity's profile.
         * Aborts the pending upload of the requested files.
         */
        bool AbortFileUploads(DataModels::FAbortFileUploadsRequest& request, const FAbortFileUploadsDelegate& SuccessDelegate = FAbortFileUploadsDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Delete files on an entity's profile.
         * Deletes the requested files from the entity's profile.
         */
        bool DeleteFiles(DataModels::FDeleteFilesRequest& request, const FDeleteFilesDelegate& SuccessDelegate = FDeleteFilesDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Finalize file uploads to an entity's profile.
         * Finalizes the upload of the requested files. Verifies that the files have been successfully uploaded and moves the file pointers from pending to live.
         */
        bool FinalizeFileUploads(DataModels::FFinalizeFileUploadsRequest& request, const FFinalizeFileUploadsDelegate& SuccessDelegate = FFinalizeFileUploadsDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Retrieves file metadata from an entity's profile.
         * Returns URLs that may be used to download the files for a profile for a limited length of time. Only returns files that have been successfully uploaded, files that are still pending will either return the old value, if it exists, or nothing. 
         */
        bool GetFiles(DataModels::FGetFilesRequest& request, const FGetFilesDelegate& SuccessDelegate = FGetFilesDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Retrieves objects from an entity's profile.
         * Gets JSON objects from an entity profile and returns it. 
         */
        bool GetObjects(DataModels::FGetObjectsRequest& request, const FGetObjectsDelegate& SuccessDelegate = FGetObjectsDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Initiates file uploads to an entity's profile.
         * Returns URLs that may be used to upload the files for a profile 5 minutes. After using the upload calls FinalizeFileUploads must be called to move the file status from pending to live.
         */
        bool InitiateFileUploads(DataModels::FInitiateFileUploadsRequest& request, const FInitiateFileUploadsDelegate& SuccessDelegate = FInitiateFileUploadsDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Sets objects on an entity's profile.
         * Sets JSON objects on the requested entity profile. May include a version number to be used to perform optimistic concurrency operations during update. If the current version differs from the version in the request the request will be ignored. If no version is set on the request then the value will always be updated if the values differ. Using the version value does not guarantee a write though, ConcurrentEditError may still occur if multiple clients are attempting to update the same profile. 
         */
        bool SetObjects(DataModels::FSetObjectsRequest& request, const FSetObjectsDelegate& SuccessDelegate = FSetObjectsDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());

    private:
        // ------------ Generated result handlers
        void OnAbortFileUploadsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FAbortFileUploadsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnDeleteFilesResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FDeleteFilesDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnFinalizeFileUploadsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FFinalizeFileUploadsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnGetFilesResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetFilesDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnGetObjectsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetObjectsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnInitiateFileUploadsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FInitiateFileUploadsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnSetObjectsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FSetObjectsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);

    };
};
