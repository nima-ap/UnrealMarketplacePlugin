//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "Core/PlayFabBaseModel.h"

namespace PlayFab
{
namespace ProfilesModels
{

    enum EffectType
    {
        EffectTypeAllow,
        EffectTypeDeny
    };

    PLAYFABCPP_API void writeEffectTypeEnumJSON(EffectType enumVal, JsonWriter& writer);
    PLAYFABCPP_API EffectType readEffectTypeFromValue(const TSharedPtr<FJsonValue>& value);
    PLAYFABCPP_API EffectType readEffectTypeFromValue(const FString& value);

    struct PLAYFABCPP_API FEntityDataObject : public FPlayFabBaseModel
    {
        // [optional] Un-escaped JSON object, if DataAsObject is true.
        FJsonKeeper DataObject;

        // [optional] Escaped string JSON body of the object, if DataAsObject is default or false.
        FString EscapedDataObject;

        // [optional] Name of this object.
        FString ObjectName;

        FEntityDataObject() :
            FPlayFabBaseModel(),
            DataObject(),
            EscapedDataObject(),
            ObjectName()
            {}

        FEntityDataObject(const FEntityDataObject& src) :
            FPlayFabBaseModel(),
            DataObject(src.DataObject),
            EscapedDataObject(src.EscapedDataObject),
            ObjectName(src.ObjectName)
            {}

        FEntityDataObject(const TSharedPtr<FJsonObject>& obj) : FEntityDataObject()
        {
            readFromValue(obj);
        }

        ~FEntityDataObject();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FEntityKey : public FPlayFabBaseModel
    {
        // Entity profile ID.
        FString Id;

        // Entity type. See https://api.playfab.com/docs/tutorials/entities/entitytypes
        FString Type;

        FEntityKey() :
            FPlayFabBaseModel(),
            Id(),
            Type()
            {}

        FEntityKey(const FEntityKey& src) :
            FPlayFabBaseModel(),
            Id(src.Id),
            Type(src.Type)
            {}

        FEntityKey(const TSharedPtr<FJsonObject>& obj) : FEntityKey()
        {
            readFromValue(obj);
        }

        ~FEntityKey();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FEntityPermissionStatement : public FPlayFabBaseModel
    {
        // The action this statement effects. May be 'Read', 'Write' or '*' for both read and write.
        FString Action;

        // [optional] A comment about the statement. Intended solely for bookkeeping and debugging.
        FString Comment;

        // [optional] Additional conditions to be applied for entity resources.
        FJsonKeeper Condition;

        // The effect this statement will have. It may be either Allow or Deny
        EffectType Effect;

        // The principal this statement will effect.
        FJsonKeeper Principal;

        // The resource this statements effects. Similar to 'pfrn:data--title![Title ID]/Profile/*'
        FString Resource;

        FEntityPermissionStatement() :
            FPlayFabBaseModel(),
            Action(),
            Comment(),
            Condition(),
            Effect(),
            Principal(),
            Resource()
            {}

        FEntityPermissionStatement(const FEntityPermissionStatement& src) :
            FPlayFabBaseModel(),
            Action(src.Action),
            Comment(src.Comment),
            Condition(src.Condition),
            Effect(src.Effect),
            Principal(src.Principal),
            Resource(src.Resource)
            {}

        FEntityPermissionStatement(const TSharedPtr<FJsonObject>& obj) : FEntityPermissionStatement()
        {
            readFromValue(obj);
        }

        ~FEntityPermissionStatement();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FEntityProfileFileMetadata : public FPlayFabBaseModel
    {
        // [optional] Checksum value for the file
        FString Checksum;

        // [optional] Name of the file
        FString FileName;

        // Last UTC time the file was modified
        FDateTime LastModified;

        // Storage service's reported byte count
        int32 Size;

        FEntityProfileFileMetadata() :
            FPlayFabBaseModel(),
            Checksum(),
            FileName(),
            LastModified(0),
            Size(0)
            {}

        FEntityProfileFileMetadata(const FEntityProfileFileMetadata& src) :
            FPlayFabBaseModel(),
            Checksum(src.Checksum),
            FileName(src.FileName),
            LastModified(src.LastModified),
            Size(src.Size)
            {}

        FEntityProfileFileMetadata(const TSharedPtr<FJsonObject>& obj) : FEntityProfileFileMetadata()
        {
            readFromValue(obj);
        }

        ~FEntityProfileFileMetadata();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FEntityProfileBody : public FPlayFabBaseModel
    {
        // [optional] The entity id and type.
        TSharedPtr<FEntityKey> Entity;

        /**
         * [optional] The chain of responsibility for this entity. This is a representation of 'ownership'. It is constructed using the
         * following formats (replace '[ID]' with the unique identifier for the given entity): Namespace: 'namespace![Namespace
         * ID]' Title: 'title![Namespace ID]/[Title ID]' Master Player Account: 'master_player_account![Namespace
         * ID]/[MasterPlayerAccount ID]' Title Player Account: 'title_player_account![Namespace ID]/[Title ID]/[MasterPlayerAccount
         * ID]/[TitlePlayerAccount ID]' Character: 'character![Namespace ID]/[Title ID]/[MasterPlayerAccount
         * ID]/[TitlePlayerAccount ID]/[Character ID]'
         */
        FString EntityChain;

        // [optional] The files on this profile.
        TMap<FString, FEntityProfileFileMetadata> Files;
        // [optional] The language on this profile.
        FString Language;

        // [optional] The objects on this profile.
        TMap<FString, FEntityDataObject> Objects;
        /**
         * [optional] The permissions that govern access to this entity profile and its properties. Only includes permissions set on this
         * profile, not global statements from titles and namespaces.
         */
        TArray<FEntityPermissionStatement> Permissions;
        /**
         * The version number of the profile in persistent storage at the time of the read. Used for optional optimistic
         * concurrency during update.
         */
        int32 VersionNumber;

        FEntityProfileBody() :
            FPlayFabBaseModel(),
            Entity(nullptr),
            EntityChain(),
            Files(),
            Language(),
            Objects(),
            Permissions(),
            VersionNumber(0)
            {}

        FEntityProfileBody(const FEntityProfileBody& src) :
            FPlayFabBaseModel(),
            Entity(src.Entity.IsValid() ? MakeShareable(new FEntityKey(*src.Entity)) : nullptr),
            EntityChain(src.EntityChain),
            Files(src.Files),
            Language(src.Language),
            Objects(src.Objects),
            Permissions(src.Permissions),
            VersionNumber(src.VersionNumber)
            {}

        FEntityProfileBody(const TSharedPtr<FJsonObject>& obj) : FEntityProfileBody()
        {
            readFromValue(obj);
        }

        ~FEntityProfileBody();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    enum EntityTypes
    {
        EntityTypestitle,
        EntityTypesmaster_player_account,
        EntityTypestitle_player_account,
        EntityTypescharacter,
        EntityTypesgroup,
        EntityTypesservice
    };

    PLAYFABCPP_API void writeEntityTypesEnumJSON(EntityTypes enumVal, JsonWriter& writer);
    PLAYFABCPP_API EntityTypes readEntityTypesFromValue(const TSharedPtr<FJsonValue>& value);
    PLAYFABCPP_API EntityTypes readEntityTypesFromValue(const FString& value);

    struct PLAYFABCPP_API FGetEntityProfileRequest : public FPlayFabBaseModel
    {
        /**
         * [optional] Determines whether the objects will be returned as an escaped JSON string or as a un-escaped JSON object. Default is
         * JSON string.
         */
        Boxed<bool> DataAsObject;

        // The entity to perform this action on.
        FEntityKey Entity;

        FGetEntityProfileRequest() :
            FPlayFabBaseModel(),
            DataAsObject(),
            Entity()
            {}

        FGetEntityProfileRequest(const FGetEntityProfileRequest& src) :
            FPlayFabBaseModel(),
            DataAsObject(src.DataAsObject),
            Entity(src.Entity)
            {}

        FGetEntityProfileRequest(const TSharedPtr<FJsonObject>& obj) : FGetEntityProfileRequest()
        {
            readFromValue(obj);
        }

        ~FGetEntityProfileRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FGetEntityProfileResponse : public FPlayFabBaseModel
    {
        // [optional] Entity profile
        TSharedPtr<FEntityProfileBody> Profile;

        FGetEntityProfileResponse() :
            FPlayFabBaseModel(),
            Profile(nullptr)
            {}

        FGetEntityProfileResponse(const FGetEntityProfileResponse& src) :
            FPlayFabBaseModel(),
            Profile(src.Profile.IsValid() ? MakeShareable(new FEntityProfileBody(*src.Profile)) : nullptr)
            {}

        FGetEntityProfileResponse(const TSharedPtr<FJsonObject>& obj) : FGetEntityProfileResponse()
        {
            readFromValue(obj);
        }

        ~FGetEntityProfileResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FGetEntityProfilesRequest : public FPlayFabBaseModel
    {
        /**
         * [optional] Determines whether the objects will be returned as an escaped JSON string or as a un-escaped JSON object. Default is
         * JSON string.
         */
        Boxed<bool> DataAsObject;

        // Entity keys of the profiles to load. Must be between 1 and 25
        TArray<FEntityKey> Entities;
        FGetEntityProfilesRequest() :
            FPlayFabBaseModel(),
            DataAsObject(),
            Entities()
            {}

        FGetEntityProfilesRequest(const FGetEntityProfilesRequest& src) :
            FPlayFabBaseModel(),
            DataAsObject(src.DataAsObject),
            Entities(src.Entities)
            {}

        FGetEntityProfilesRequest(const TSharedPtr<FJsonObject>& obj) : FGetEntityProfilesRequest()
        {
            readFromValue(obj);
        }

        ~FGetEntityProfilesRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FGetEntityProfilesResponse : public FPlayFabBaseModel
    {
        // [optional] Entity profiles
        TArray<FEntityProfileBody> Profiles;
        FGetEntityProfilesResponse() :
            FPlayFabBaseModel(),
            Profiles()
            {}

        FGetEntityProfilesResponse(const FGetEntityProfilesResponse& src) :
            FPlayFabBaseModel(),
            Profiles(src.Profiles)
            {}

        FGetEntityProfilesResponse(const TSharedPtr<FJsonObject>& obj) : FGetEntityProfilesResponse()
        {
            readFromValue(obj);
        }

        ~FGetEntityProfilesResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FGetGlobalPolicyRequest : public FPlayFabBaseModel
    {
        FGetGlobalPolicyRequest() :
            FPlayFabBaseModel()
            {}

        FGetGlobalPolicyRequest(const FGetGlobalPolicyRequest& src) :
            FPlayFabBaseModel()
            {}

        FGetGlobalPolicyRequest(const TSharedPtr<FJsonObject>& obj) : FGetGlobalPolicyRequest()
        {
            readFromValue(obj);
        }

        ~FGetGlobalPolicyRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FGetGlobalPolicyResponse : public FPlayFabBaseModel
    {
        // [optional] The permissions that govern access to all entities under this title or namespace.
        TArray<FEntityPermissionStatement> Permissions;
        FGetGlobalPolicyResponse() :
            FPlayFabBaseModel(),
            Permissions()
            {}

        FGetGlobalPolicyResponse(const FGetGlobalPolicyResponse& src) :
            FPlayFabBaseModel(),
            Permissions(src.Permissions)
            {}

        FGetGlobalPolicyResponse(const TSharedPtr<FJsonObject>& obj) : FGetGlobalPolicyResponse()
        {
            readFromValue(obj);
        }

        ~FGetGlobalPolicyResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    enum OperationTypes
    {
        OperationTypesCreated,
        OperationTypesUpdated,
        OperationTypesDeleted,
        OperationTypesNone
    };

    PLAYFABCPP_API void writeOperationTypesEnumJSON(OperationTypes enumVal, JsonWriter& writer);
    PLAYFABCPP_API OperationTypes readOperationTypesFromValue(const TSharedPtr<FJsonValue>& value);
    PLAYFABCPP_API OperationTypes readOperationTypesFromValue(const FString& value);

    struct PLAYFABCPP_API FSetEntityProfilePolicyRequest : public FPlayFabBaseModel
    {
        // The entity to perform this action on.
        FEntityKey Entity;

        // [optional] The statements to include in the access policy.
        TArray<FEntityPermissionStatement> Statements;
        FSetEntityProfilePolicyRequest() :
            FPlayFabBaseModel(),
            Entity(),
            Statements()
            {}

        FSetEntityProfilePolicyRequest(const FSetEntityProfilePolicyRequest& src) :
            FPlayFabBaseModel(),
            Entity(src.Entity),
            Statements(src.Statements)
            {}

        FSetEntityProfilePolicyRequest(const TSharedPtr<FJsonObject>& obj) : FSetEntityProfilePolicyRequest()
        {
            readFromValue(obj);
        }

        ~FSetEntityProfilePolicyRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FSetEntityProfilePolicyResponse : public FPlayFabBaseModel
    {
        /**
         * [optional] The permissions that govern access to this entity profile and its properties. Only includes permissions set on this
         * profile, not global statements from titles and namespaces.
         */
        TArray<FEntityPermissionStatement> Permissions;
        FSetEntityProfilePolicyResponse() :
            FPlayFabBaseModel(),
            Permissions()
            {}

        FSetEntityProfilePolicyResponse(const FSetEntityProfilePolicyResponse& src) :
            FPlayFabBaseModel(),
            Permissions(src.Permissions)
            {}

        FSetEntityProfilePolicyResponse(const TSharedPtr<FJsonObject>& obj) : FSetEntityProfilePolicyResponse()
        {
            readFromValue(obj);
        }

        ~FSetEntityProfilePolicyResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FSetGlobalPolicyRequest : public FPlayFabBaseModel
    {
        // [optional] The permissions that govern access to all entities under this title or namespace.
        TArray<FEntityPermissionStatement> Permissions;
        FSetGlobalPolicyRequest() :
            FPlayFabBaseModel(),
            Permissions()
            {}

        FSetGlobalPolicyRequest(const FSetGlobalPolicyRequest& src) :
            FPlayFabBaseModel(),
            Permissions(src.Permissions)
            {}

        FSetGlobalPolicyRequest(const TSharedPtr<FJsonObject>& obj) : FSetGlobalPolicyRequest()
        {
            readFromValue(obj);
        }

        ~FSetGlobalPolicyRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FSetGlobalPolicyResponse : public FPlayFabBaseModel
    {
        FSetGlobalPolicyResponse() :
            FPlayFabBaseModel()
            {}

        FSetGlobalPolicyResponse(const FSetGlobalPolicyResponse& src) :
            FPlayFabBaseModel()
            {}

        FSetGlobalPolicyResponse(const TSharedPtr<FJsonObject>& obj) : FSetGlobalPolicyResponse()
        {
            readFromValue(obj);
        }

        ~FSetGlobalPolicyResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FSetProfileLanguageRequest : public FPlayFabBaseModel
    {
        // [optional] The entity to perform this action on.
        TSharedPtr<FEntityKey> Entity;

        // The expected version of a profile to perform this update on
        int32 ExpectedVersion;

        // [optional] The language to set on the given entity. Deletes the profile's language if passed in a null string.
        FString Language;

        FSetProfileLanguageRequest() :
            FPlayFabBaseModel(),
            Entity(nullptr),
            ExpectedVersion(0),
            Language()
            {}

        FSetProfileLanguageRequest(const FSetProfileLanguageRequest& src) :
            FPlayFabBaseModel(),
            Entity(src.Entity.IsValid() ? MakeShareable(new FEntityKey(*src.Entity)) : nullptr),
            ExpectedVersion(src.ExpectedVersion),
            Language(src.Language)
            {}

        FSetProfileLanguageRequest(const TSharedPtr<FJsonObject>& obj) : FSetProfileLanguageRequest()
        {
            readFromValue(obj);
        }

        ~FSetProfileLanguageRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FSetProfileLanguageResponse : public FPlayFabBaseModel
    {
        // [optional] The type of operation that occured on the profile's language
        Boxed<OperationTypes> OperationResult;

        // [optional] The updated version of the profile after the language update
        Boxed<int32> VersionNumber;

        FSetProfileLanguageResponse() :
            FPlayFabBaseModel(),
            OperationResult(),
            VersionNumber()
            {}

        FSetProfileLanguageResponse(const FSetProfileLanguageResponse& src) :
            FPlayFabBaseModel(),
            OperationResult(src.OperationResult),
            VersionNumber(src.VersionNumber)
            {}

        FSetProfileLanguageResponse(const TSharedPtr<FJsonObject>& obj) : FSetProfileLanguageResponse()
        {
            readFromValue(obj);
        }

        ~FSetProfileLanguageResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

}
}
