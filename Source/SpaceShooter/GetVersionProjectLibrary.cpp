// Copyright 2024 bitHeads, Inc. All Rights Reserved.

#include "GetVersionProjectLibrary.h"


FString UGetVersionProjectLibrary::GetAppVersion()
{
	FString AppVersion;
	GConfig->GetString(
		TEXT("/Script/EngineSettings.GeneralProjectSettings"),
		TEXT("ProjectVersion"),
		AppVersion,
		GGameIni
	);

	return AppVersion;
}