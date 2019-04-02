#pragma once

#include "CoreMinimal.h"
#include "FileHelper.h"
#include "Misc/Paths.h"
namespace PlayFab
{
    class PlayFabUtilities
    {
    private:
        static FString GetLocalSettingsFileContent();
        static FString GetTempDir();
    public:
        static FString GetLocalSettingsFileProperty(const FString& propertyKey);
    };
}
