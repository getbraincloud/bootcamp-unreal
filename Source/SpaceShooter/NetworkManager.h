// Copyright 2022 bitHeads, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NetworkCallback.h"
#include "NetworkCallbackHandler.h"
#include "BrainCloudWrapper.h"
#include "TwitchHelper.h"
#include "UObject/NoExportTypes.h"
#include "NetworkManager.generated.h"


/**
 * 
 */
UCLASS()
class SPACESHOOTER_API UNetworkManager : public UObject, public TwitchHelperCallback
{
	GENERATED_BODY()
    
public:
    UNetworkManager();
    ~UNetworkManager();
    
    void Tick(float DeltaTime);
    
    void SetCallback(NetworkCallback* callback);
    
    FString GetBrainCloudClientVersion();

    bool HasAuthenticatedPreviously();
    bool IsAuthenticated();
    bool IsUsernameSaved();

    void EndSession();
    void LogOut();
    void Reconnect();
    
    void RequestAnonymousAuthentication();
    void RequestUniversalAuthentication(const FString& userID, const FString& password);
    void RequestEmailAuthentication(const FString& email, const FString& password);
    void RequestTwitchExternalAuthentication();
    
    void UpdateUsername(const FString& username);
    FString GetUsername();
    
    void RequestLeaderboard(const FString& leaderboardId);
    void RequestLeaderboard(const FString& leaderboardId, int startIndex, int endIndex);
    void RequestCountryLeaderboard();
    
    void PostScoreToLeaderboard(const FString& leaderboardId, float time);
    void PostScoreToLeaderboard(const FString& leaderboardId, float time, const FString& nickname);
    
    void PostScoreToAllLeaderboards(float time);
    void PostScoreToAllLeaderboards(float time, const FString& nickname);
    
    void RequestGlobalEntityLevelData();
    
    void RequestUserStatistics();
    void IncrementUserStatistics(const FString& jsonDataToSync);
    
    void RequestAchievements();
    void AwardAchievement(Achievement* achievement);
    
    void RequestUserEntityData();
    void CreateUserEntityData();
    void UpdateUserEntityData(const FString& entityID, const FString& entityType, const FString& jsonData);
    
    void AttachEmailIdentity(const FString& email, const FString& password);
    void GetIdentities();
    bool DoesIdentityTypesListContain(const FString& identity);

private:
    UFUNCTION(Category = "CallBack") void OnAuthenticationCallback(const FString& jsonData);
    UFUNCTION(Category = "CallBack") void OnAuthenticationError(int statusCode, int reasonCode, const FString& jsonError);
    
    UFUNCTION(Category = "CallBack") void OnLogOutCallback(const FString& jsonData);
    UFUNCTION(Category = "CallBack") void OnLogOutError(int statusCode, int reasonCode, const FString& jsonError);
    
    UFUNCTION(Category = "CallBack") void OnUpdateUsernameCallback(const FString& jsonData);
    UFUNCTION(Category = "CallBack") void OnUpdateUsernameError(int statusCode, int reasonCode, const FString& jsonError);
    
    UFUNCTION(Category = "CallBack") void OnGetGlobalLeaderboardCallback(const FString& jsonData);
    UFUNCTION(Category = "CallBack") void OnGetGlobalLeaderboardError(int statusCode, int reasonCode, const FString& jsonError);
    
    UFUNCTION(Category = "CallBack") void OnPostScoreToLeaderboardCallback(const FString& jsonData);
    UFUNCTION(Category = "CallBack") void OnPostScoreToLeaderboardError(int statusCode, int reasonCode, const FString& jsonError);
    
    UFUNCTION(Category = "CallBack") void OnGlobalEntityLevelDataCallback(const FString& jsonData);
    UFUNCTION(Category = "CallBack") void OnGlobalEntityLevelDataError(int statusCode, int reasonCode, const FString& jsonError);
    
    UFUNCTION(Category = "CallBack") void OnReadUserStatisticsCallback(const FString& jsonData);
    UFUNCTION(Category = "CallBack") void OnReadUserStatisticsError(int statusCode, int reasonCode, const FString& jsonError);
    
    UFUNCTION(Category = "CallBack") void OnIncrementUserStatsCallback(const FString& jsonData);
    UFUNCTION(Category = "CallBack") void OnIncrementUserStatsError(int statusCode, int reasonCode, const FString& jsonError);
    
    UFUNCTION(Category = "CallBack") void OnReadAchievementsCallback(const FString& jsonData);
    UFUNCTION(Category = "CallBack") void OnReadAchievementsError(int statusCode, int reasonCode, const FString& jsonError);
    
    UFUNCTION(Category = "CallBack") void OnAwardAchievementCallback(const FString& jsonData);
    UFUNCTION(Category = "CallBack") void OnAwardAchievementError(int statusCode, int reasonCode, const FString& jsonError);
    
    UFUNCTION(Category = "CallBack") void OnGetUserEntityDataCallback(const FString& jsonData);
    UFUNCTION(Category = "CallBack") void OnGetUserEntityDataError(int statusCode, int reasonCode, const FString& jsonError);
    UFUNCTION(Category = "CallBack") void OnCreateUserEntityDataCallback(const FString& jsonData);
    UFUNCTION(Category = "CallBack") void OnCreateUserEntityDataError(int statusCode, int reasonCode, const FString& jsonError);
    UFUNCTION(Category = "CallBack") void OnUpdateUserEntityDataCallback(const FString& jsonData);
    UFUNCTION(Category = "CallBack") void OnUpdateUserEntityDataError(int statusCode, int reasonCode, const FString& jsonError);
    
    UFUNCTION(Category = "CallBack") void OnAttachEmailCallback(const FString& jsonData);
    UFUNCTION(Category = "CallBack") void OnAttachEmailError(int statusCode, int reasonCode, const FString& jsonError);
    UFUNCTION(Category = "CallBack") void OnGetIdentitiesCallback(const FString& jsonData);
    UFUNCTION(Category = "CallBack") void OnGetIdentitiesError(int statusCode, int reasonCode, const FString& jsonError);
    
    UFUNCTION(Category = "CallBack") void OnPostScoreToAllLeaderboardsCallback(const FString& jsonData);
    UFUNCTION(Category = "CallBack") void OnPostScoreToAllLeaderboardsError(int statusCode, int reasonCode, const FString& jsonError);
    
    UFUNCTION(Category = "CallBack") void OnGetCustomLeaderboardCallback(const FString& jsonData);
    UFUNCTION(Category = "CallBack") void OnGetCustomLeaderboardError(int statusCode, int reasonCode, const FString& jsonError);
    
    FString ExtractErrorStatusMessage(const FString& jsonError);
    FString ExtractUpgradeAppIdMessage(const FString& jsonError);

    void OnTwitchAuthorizationGranted(const FString& accessToken, const FString& email, const FString& username) override;
    void OnTwitchAuthorizationDenied() override;
    void OnTwitchAuthorizationError(const FString& errorMessage) override;
    
    void ParseLeaderboard(Leaderboard** leaderboard, TSharedPtr<FJsonObject>& leaderboardData);
    std::vector<Statistic> ParseStatistics(TSharedPtr<FJsonObject>& statisticsData);
    std::vector<LevelData> ParseLevelData(TSharedPtr<FJsonObject>& levelEntityData);
    std::vector<Achievement> ParseAchievements(TArray<TSharedPtr<FJsonValue>>& achievementsData);
    void ParseUserProgress(UserData** userData, TSharedPtr<FJsonObject>& userProgressData);
    
    UPROPERTY() UBrainCloudWrapper* m_BrainCloud;
    TwitchHelper* m_TwitchHelper;
    NetworkCallback* m_Callback;
    NetworkCallbackHandler m_AuthenticationCallback;
    NetworkCallbackHandler m_LogOutCallback;
    NetworkCallbackHandler m_UpdateUsernameCallback;
    NetworkCallbackHandler m_GetGlobalLeaderboardCallback;
    NetworkCallbackHandler m_PostScoreToLeaderboardCallback;
    NetworkCallbackHandler m_GetGlobalEntityLevelDataCallback;
    NetworkCallbackHandler m_ReadUserStatisticsCallback;
    NetworkCallbackHandler m_IncrementUserStatsCallback;
    NetworkCallbackHandler m_ReadAchievementsCallback;
    NetworkCallbackHandler m_AwardAchievementCallback;
    NetworkCallbackHandler m_GetUserEntityDataCallback;
    NetworkCallbackHandler m_CreateUserEntityDataCallback;
    NetworkCallbackHandler m_UpdateUserEntityDataCallback;
    NetworkCallbackHandler m_AttachEmailCallback;
    NetworkCallbackHandler m_GetIdentitiesCallback;
    NetworkCallbackHandler m_PostScoreToAllLeaderboardsCallback;
    NetworkCallbackHandler m_GetCustomLeaderboardCallback;
    
    std::vector<FString> m_IdentityTypesList;
};
