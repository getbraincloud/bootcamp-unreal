// Copyright 2024 bitHeads, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GetVersionProjectLibrary.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API UGetVersionProjectLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetAppVersion"), Category = "Game Config")
	static FString GetAppVersion();
};
