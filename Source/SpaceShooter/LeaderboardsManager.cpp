// Copyright 2022 bitHeads, Inc. All Rights Reserved.


#include "LeaderboardsManager.h"

void ULeaderboardsManager::AddLeaderboard(const Leaderboard& leaderboard)
{
    // Remove all existing leaderboards with the same name
    FString name = leaderboard.GetName();
    
    m_Leaderboards.RemoveAll([&, name](Leaderboard& leaderboard) {
        return leaderboard.GetName() == name;
    });
    
    // Add the Leaderboard object to the list
    m_Leaderboards.Add(leaderboard);
    
    // Check the leaderboard for the user's time
    if (m_UserTime > 0.0f)
    {
        for (int i = 0; i < m_Leaderboards.Last().GetCount(); i++)
        {
            if (m_Leaderboards.Last().GetLeaderboardEntryAtIndex(i)->GetTime() == m_UserTime)
            {
                m_Leaderboards.Last().GetLeaderboardEntryAtIndex(i)->SetIsUserScore(true);
                break;
            }
        }
    }
}

int ULeaderboardsManager::GetCount()
{
    return m_Leaderboards.Num();
}

Leaderboard* ULeaderboardsManager::GetLeaderboardByName(const FString& name)
{
    for (int i = 0; i < m_Leaderboards.Num(); i++)
        if (m_Leaderboards[i].GetName() == name)
            return &m_Leaderboards[i];
    
    return nullptr;
}

Leaderboard* ULeaderboardsManager::GetLeaderboardAtIndex(int index)
{
    if (index >= 0 && index < m_Leaderboards.Num())
        return &m_Leaderboards[index];
    return nullptr;
}

void ULeaderboardsManager::SetUserTime(float userTime)
{
    long ms = (long)(userTime * 1000.0f);       // Convert the time from seconds to milleseconds
    m_UserTime = (float)(ms) / 1000.0f;
}
