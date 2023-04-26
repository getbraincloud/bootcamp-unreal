// Copyright 2022 bitHeads, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LeaderboardEntry.h"

/**
 * 
 */
class SPACESHOOTER_API Leaderboard
{
public:
    Leaderboard(const FString& name, TArray<LeaderboardEntry>& leaderboardEntries);
    
    FString GetName() const;
    
    LeaderboardEntry* GetLeaderboardEntryAtIndex(int index);
    int GetCount() const;
    
private:
    TArray<LeaderboardEntry> m_LeaderboardEntries;
    FString m_Name;
};
