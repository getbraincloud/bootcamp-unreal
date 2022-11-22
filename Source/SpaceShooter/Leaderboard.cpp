// Copyright 2022 bitHeads, Inc. All Rights Reserved.


#include "Leaderboard.h"

Leaderboard::Leaderboard(const FString& name, TArray<LeaderboardEntry>& leaderboardEntries) :
    m_LeaderboardEntries(leaderboardEntries),
    m_Name(name)
{
    
}

FString Leaderboard::GetName() const
{
    return m_Name;
}

LeaderboardEntry* Leaderboard::GetLeaderboardEntryAtIndex(int index)
{
    if (index >= 0 && index < m_LeaderboardEntries.Num())
        return &m_LeaderboardEntries[index];
    return nullptr;
}

int Leaderboard::GetCount() const
{
    return m_LeaderboardEntries.Num();
}
