// Copyright 2022 bitHeads, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Leaderboard.h"
#include "LevelData.h"
#include "Statistic.h"
#include "Achievement.h"
#include "UserData.h"
#include <vector>

struct SPACESHOOTER_API AuthenticationData
{
    AuthenticationData() : mainLeaderboard(nullptr), dailyLeaderboard(nullptr), countryLeaderboard(nullptr), userData(nullptr) {}
    ~AuthenticationData() {
                            if(mainLeaderboard) {delete mainLeaderboard; mainLeaderboard = nullptr;}
                            if(dailyLeaderboard) {delete dailyLeaderboard; dailyLeaderboard = nullptr;}
                            if(countryLeaderboard) {delete countryLeaderboard; countryLeaderboard = nullptr;}
                            if(userData) {delete userData; userData = nullptr;}
                          }
    
    Leaderboard* mainLeaderboard;
    Leaderboard* dailyLeaderboard;
    Leaderboard* countryLeaderboard;
    UserData* userData;

    std::vector<LevelData> levelData;
    std::vector<Statistic> statistics;
    std::vector<Achievement> achievements;
};


/**
 * 
 */
class SPACESHOOTER_API NetworkCallback
{
public:
    NetworkCallback() = default;
    virtual ~NetworkCallback() = default;
    
    virtual void OnAuthenticationRequestCompleted(AuthenticationData* authenticationData) {}
    virtual void OnAuthenticationRequestFailed(const FString& errorMessage) {}
    
    virtual void OnLogOutRequestCompleted() {}
    virtual void OnLogOutRequestFailed() {}
    
    virtual void OnUpdateUsernameRequestCompleted() {}
    virtual void OnUpdateUsernameRequestFailed() {}
    
    virtual void OnLeaderboardRequestCompleted(const Leaderboard& leaderboard) {}
    virtual void OnLeaderboardRequestFailed() {}
    
    virtual void OnPostScoreToLeaderboardRequestCompleted() {}
    virtual void OnPostScoreToLeaderboardRequestFailed() {}
    
    virtual void OnPostScoreToAllLeaderboardsRequestCompleted() {}
    virtual void OnPostScoreToAllLeaderboardsRequestFailed() {}
    
    virtual void OnGlobalEntityLevelDataRequestCompleted(const std::vector<LevelData>& levelData) {}
    virtual void OnGlobalEntityLevelDataRequestFailed() {}
    
    virtual void OnUserStatisticsRequestCompleted(const std::vector<Statistic>& statistics) {}
    virtual void OnUserStatisticsRequestFailed() {}
    
    virtual void OnIncrementUserStatisticsCompleted(const std::vector<Statistic>& statistics) {}
         virtual void OnIncrementUserStatisticsFailed() {}
    
    virtual void OnReadAchievementsRequestCompleted(const std::vector<Achievement>& achievements) {}
    virtual void OnReadAchievementsRequestFailed() {}
    
    virtual void OnAwardAchievementRequestCompleted() {}
    virtual void OnAwardAchievementRequestFailed() {}
    
    virtual void OnUserEntityDataRequestCompleted(UserData* userData) {}
    virtual void OnUserEntityDataRequestFailed() {}
    virtual void OnCreateUserEntityDataRequestCompleted(const FString& entityID, const FString& entityType) {}
    virtual void OnCreateUserEntityDataRequestFailed() {}
    virtual void OnUpdateUserEntityDataRequestCompleted() {}
    virtual void OnUpdateUserEntityDataRequestFailed() {}
    
    virtual void OnAttachEmailIdentityRequestCompleted() {}
    virtual void OnAttachEmailIdentityRequestFailed() {}
    virtual void OnGetIdentitiesRequestCompleted() {}
    virtual void OnGetIdentitiesRequestFailed() {}

    //TODO: Add Network callback methods here
};
