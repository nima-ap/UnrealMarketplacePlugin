
#include "PlayFabUtilities.h"
#include "Json.h"

using namespace PlayFab;

FString PlayFab::PlayFabUtilities::GetLocalSettingsFileContent()
{
    FString tempDirPath = PlayFabUtilities::GetTempDir();
    FString localSettingsFilePath = FPaths::Combine(tempDirPath, TEXT("playfab.local.settings.json"));
    FString localSettingsFileContent = "";
    if (FFileHelper::LoadFileToString(localSettingsFileContent, *localSettingsFilePath))
    {
        UE_LOG(LogTemp, Log, TEXT("LOCAL SETTINGS FILE CONTENT: %s"), *localSettingsFileContent);
        return localSettingsFileContent;
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("Failed to retrieve local settings file content"));
        return FString(TEXT(""));
    }
}

FString PlayFab::PlayFabUtilities::GetLocalSettingsFileProperty(const FString& propertyKey)
{
    FString fileContent = PlayFabUtilities::GetLocalSettingsFileContent();
    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
    TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(fileContent);

    if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
    {
        FString outString;
        return JsonObject->TryGetStringField(propertyKey, outString) ? outString : FString();
    }
    return FString();
}

FString PlayFab::PlayFabUtilities::GetTempDir()
{
    char* temp = NULL;
    if ((temp = getenv("TMPDIR")) != NULL || (temp = getenv("TMP")) != NULL || (temp = getenv("TEMP")) != NULL)
    {
        return FString(UTF8_TO_TCHAR(temp));
    }
    return FString(TEXT(""));
}
