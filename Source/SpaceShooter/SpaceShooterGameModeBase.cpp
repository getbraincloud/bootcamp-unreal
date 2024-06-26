// Copyright 2022 bitHeads, Inc. All Rights Reserved.


#include "SpaceShooterGameModeBase.h"
#include "SpaceShooterPlayerController.h"
#include "SpaceShooterHUD.h"
#include "NetworkManager.h"
#include "Ship.h"
#include "Spawner.h"
#include "Constants.h"
#include "EngineUtils.h"
#include "Engine.h"


ASpaceShooterGameModeBase::ASpaceShooterGameModeBase() :
    m_HUD(nullptr),
    m_Ship(nullptr),
    m_Spawner(nullptr),
    m_NetworkManager(nullptr),
    m_LeaderboardsManager(nullptr),
    m_StatisticsManager(nullptr),
    m_AchievementsManager(nullptr),
    m_ElapsedTime(0.0f),
    m_TimeScale(1.0f),
    m_LevelIndicatorDisplayTime(0.0f),
    m_EndOfGameDisplayTime(0.0f),
    m_LevelIndex(-1),
    m_LevelCount(0),
    m_LeaderboardEntryIndex(-1),
    m_GameState(GameModeState::Authenticating),
    m_Mode(Mode::Unknown),
    m_UserData()
{
    PrimaryActorTick.bCanEverTick = true;
    
    DefaultPawnClass = AShip::StaticClass();
    PlayerControllerClass = ASpaceShooterPlayerController::StaticClass();
    HUDClass = ASpaceShooterHUD::StaticClass();
    
    // Create the Spawner
    m_Spawner = CreateDefaultSubobject<USpawner>("Spawner");
    
    // Create the Network Manager
    m_NetworkManager = CreateDefaultSubobject<UNetworkManager>("NetworkManager");
    m_NetworkManager->SetCallback(this);
    
    // Create the Leaderboards Manager
    m_LeaderboardsManager = CreateDefaultSubobject<ULeaderboardsManager>("LeaderboardsManager");
    
    // Create the Statistics Manager
    m_StatisticsManager = CreateDefaultSubobject<UStatisticsManager>("StatisticsManager");
    
    // Create the Achievements Manager
    m_AchievementsManager = CreateDefaultSubobject<UAchievementsManager>("AchievementsManager");
}

void ASpaceShooterGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    GetWorld()->GetGameViewport()->HandleViewModeCommand(TEXT("unlit"), *GLog, GetWorld());
    GetSpawner()->CreateObjectPools();
    GetDialogManager()->CreateDialogs();
    GetShip()->SetCallback(this);
    
    HandleAuthentication();
}

void ASpaceShooterGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (EndPlayReason == EEndPlayReason::Type::Quit || EndPlayReason == EEndPlayReason::Type::EndPlayInEditor)
    {
        if (GetNetworkManager()->IsAuthenticated())
            GetNetworkManager()->EndSession();
    }
}

void ASpaceShooterGameModeBase::Tick(float DeltaTime)
{
    if(m_NetworkManager != nullptr)
        m_NetworkManager->Tick(DeltaTime);
    
    if(m_Spawner != nullptr)
        m_Spawner->Tick(DeltaTime);
    
    if (m_GameState == GameModeState::GameOver || m_GameState == GameModeState::Victory)
    {
        if (m_EndOfGameDisplayTime > 0.0f)
        {
            m_EndOfGameDisplayTime -= DeltaTime;
            if (m_EndOfGameDisplayTime < 0.0f)
            {
                if (m_GameState == GameModeState::GameOver)
                    m_HUD->HideGameOverHUD();
                if (m_GameState == GameModeState::Victory)
                    m_HUD->HideGameWonHUD();

                if (m_Mode == Mode::Endless)
                {
                    if(GetNetworkManager()->IsAuthenticated())
                    {
                        if (GetNetworkManager()->IsUsernameSaved())
                            GetNetworkManager()->PostScoreToAllLeaderboards(m_ElapsedTime);
                        else
                            GetDialogManager()->ShowPostScoreDialog(m_ElapsedTime);
                    }
                    else
                    {
                        GetDialogManager()->ShowPlayAgainDialog();
                    }
                }
                else if (m_Mode == Mode::Horde)
                {
                    GetDialogManager()->ShowPlayAgainDialog();
                }
            }
        }
    }
    else if (m_GameState == GameModeState::Gameplay)
    {
        m_ElapsedTime += DeltaTime * m_TimeScale;
        m_HUD->SetElapsedTimeHUD(m_ElapsedTime);

        if (m_Mode == Mode::Endless)
        {
            CheckEndlessModeTimeAchievements();
            
            if (m_LeaderboardEntryIndex != -1)
            {
                Leaderboard* leaderboard = GetLeaderboardsManager()->GetLeaderboardByName(kBrainCloudMainLeaderboardID);
                if(leaderboard != nullptr)
                {
                    LeaderboardEntry* leaderboardEntry = leaderboard->GetLeaderboardEntryAtIndex(m_LeaderboardEntryIndex);
                    if (leaderboardEntry != nullptr && m_ElapsedTime > leaderboardEntry->GetTime())
                        DisplayNextLeaderboardEntry();
                }
            }
        }
        else if (m_Mode == Mode::Horde)
        {
            if (m_ElapsedTime > m_LevelDurations[m_LevelIndex] && m_LevelDurations[m_LevelIndex] != -1.0f)
            {
                m_ElapsedTime = m_LevelDurations[m_LevelIndex];
                NextLevel();
            }
        }
    }
    else if (m_GameState == GameModeState::LevelTransition)
    {
        if (m_LevelIndicatorDisplayTime > 0.0f)
        {
            m_LevelIndicatorDisplayTime -= DeltaTime;

            if (m_LevelIndicatorDisplayTime < 0.0f)
                StartLevel();
        }
    }
}

void ASpaceShooterGameModeBase::HandleAuthentication()
{
    m_GameState = GameModeState::Authenticating;
    
    if (GetNetworkManager()->HasAuthenticatedPreviously())
    {
        GetDialogManager()->ShowConnectingDialog();
        GetNetworkManager()->Reconnect();
    }
    else
    {
        GetDialogManager()->ShowEmailLoginDialog();
    }
}

bool ASpaceShooterGameModeBase::IsGameOver()
{
    return m_GameState == GameModeState::GameOver;
}

bool ASpaceShooterGameModeBase::IsGameWon()
{
    return m_GameState == GameModeState::Victory;
}

AShip* ASpaceShooterGameModeBase::GetShip() 
{
    if(m_Ship == nullptr)
    {
        m_Ship = Cast<AShip>(GetWorld()->GetFirstPlayerController()->GetPawn());
        check(m_Ship != nullptr);
    }
    
    return m_Ship;
}

ASpaceShooterHUD* ASpaceShooterGameModeBase::GetHUD()
{
    if(m_HUD == nullptr)
    {
        m_HUD = Cast<ASpaceShooterHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
        check(m_HUD != nullptr);
    }
    
    return m_HUD;
}

UDialogManager* ASpaceShooterGameModeBase::GetDialogManager()
{
    return GetHUD()->GetDialogManager();
}

USpawner* ASpaceShooterGameModeBase::GetSpawner()
{
    return m_Spawner;
}

UNetworkManager* ASpaceShooterGameModeBase::GetNetworkManager() const
{
    return m_NetworkManager;
}

ULeaderboardsManager* ASpaceShooterGameModeBase::GetLeaderboardsManager() const
{
    return m_LeaderboardsManager;
}

UStatisticsManager* ASpaceShooterGameModeBase::GetStatisticsManager() const
{
    return m_StatisticsManager;
}

UAchievementsManager* ASpaceShooterGameModeBase::GetAchievementsManager() const
{
    return m_AchievementsManager;
}

const UserData* ASpaceShooterGameModeBase::GetUserData() const
{
    return &m_UserData;
}

void ASpaceShooterGameModeBase::StartEndlessMode()
{
    m_Mode = Mode::Endless;
    PrepareLevel(-1); // -1 is the default level used for endless mode
}

void ASpaceShooterGameModeBase::StartHordeMode(int levelIndex)
{
    m_Mode = Mode::Horde;
    PrepareLevel(levelIndex);
}

void ASpaceShooterGameModeBase::ResetGame(bool startNewGame)
{
    GetSpawner()->Reset();
    GetShip()->Reset();
    GetHUD()->ResetHUD();

    if (startNewGame)
    {
        if (m_Mode == Mode::Endless)
            StartEndlessMode();
        else if (m_Mode == Mode::Horde)
            StartHordeMode();
    }
}

void ASpaceShooterGameModeBase::SetTimeScale(float timeScale)
{
    m_TimeScale = timeScale;
}

float ASpaceShooterGameModeBase::GetTimeScale()
{
    return m_TimeScale;
}

void ASpaceShooterGameModeBase::OnCheatAddTime()
{
    m_ElapsedTime += 15.0f;
}

void ASpaceShooterGameModeBase::OnCheatNextLevel()
{
    if(m_Mode == Mode::Horde)
        NextLevel();
}

void ASpaceShooterGameModeBase::OnCheatHealUp()
{
    GetShip()->HealUp();
}

void ASpaceShooterGameModeBase::PrepareLevel(int levelIndex)
{   
    m_GameState = GameModeState::LevelTransition;

    m_LevelIndicatorDisplayTime = kLevelDisplayDuration;
    m_LevelIndex = levelIndex;

    m_ElapsedTime = 0.0f;

    if (m_Mode == Mode::Endless)
    {
        Leaderboard* mainLeaderboard = GetLeaderboardsManager()->GetLeaderboardByName(kBrainCloudMainLeaderboardID);
        if (mainLeaderboard != nullptr && mainLeaderboard->GetCount() > 0)
        {
            m_LeaderboardEntryIndex = mainLeaderboard->GetCount() - 1;
            GetHUD()->PushLeaderboardEntry(GetLeaderboardsManager()->GetLeaderboardByName(kBrainCloudMainLeaderboardID)->GetLeaderboardEntryAtIndex(m_LeaderboardEntryIndex));
        }

        m_HUD->ShowLevelHUD(-1, "");
    }
    else if (m_Mode == Mode::Horde)
    {
        GetHUD()->ShowLevelHUD(m_LevelIndex + 1, m_LevelDescriptions[m_LevelIndex]);
        GetHUD()->PushLevelGoal(m_LevelDescriptions[m_LevelIndex]);
    }
}

void ASpaceShooterGameModeBase::StartLevel()
{
    m_GameState = GameModeState::Gameplay;

    m_HUD->HideLevelHUD();

    GetSpawner()->StartSpawning(m_LevelIndex);

    if (!GetShip()->IsActive())
    {
        GetShip()->Activate();
        GetShip()->Spawn();
    }
}

void ASpaceShooterGameModeBase::NextLevel()
{
    GetSpawner()->StopSpawning();
    GetSpawner()->ExplodeAllActive();

    if(m_LevelIndex == 0)
    {
        Achievement* beatLevel1 = GetAchievementsManager()->GetAchievementByID(kBrainCloudAchievementBeatLevel1);
        if (beatLevel1 != nullptr && !beatLevel1->IsAwarded())
        {
            beatLevel1->Award(this);
            GetHUD()->PushAchievement(beatLevel1);
        }
    }
    
    bool needsSync = m_UserData.SetLevelCompleted(m_LevelIndex);
    if (needsSync)
        GetNetworkManager()->UpdateUserEntityData(m_UserData.GetEntityID(), m_UserData.GetEntityType(), m_UserData.GetJsonData());
    
    if (m_LevelIndex + 1 < m_LevelCount)
    {
        GetShip()->HealUp();
        m_HUD->UpdateShipDamageHUD(1.0f, 1.0f);

        PrepareLevel(m_LevelIndex + 1);
    }
}

void ASpaceShooterGameModeBase::DisplayNextLeaderboardEntry()
{
    Leaderboard* leaderboard = GetLeaderboardsManager()->GetLeaderboardByName(kBrainCloudMainLeaderboardID);
    
    if (m_LeaderboardEntryIndex == -1 || leaderboard == nullptr || leaderboard->GetCount() == 0)
        return;
    
    if (m_LeaderboardEntryIndex > 0)
    {
        m_LeaderboardEntryIndex--;
        GetHUD()->PushLeaderboardEntry(leaderboard->GetLeaderboardEntryAtIndex(m_LeaderboardEntryIndex));
    }
    else if (m_LeaderboardEntryIndex == 0)
    {
        GetHUD()->PushPlayerHasAllTimeHighScore();
    }
}

void ASpaceShooterGameModeBase::CheckEndlessModeTimeAchievements()
{
    Achievement* last30 = GetAchievementsManager()->GetAchievementByID(kBrainCloudAchievementLast30);
    if (last30 != nullptr && !last30->IsAwarded() && m_ElapsedTime >= 30.0f)
    {
        last30->Award(this);
        GetHUD()->PushAchievement(last30);
    }
    
    Achievement* last60 = GetAchievementsManager()->GetAchievementByID(kBrainCloudAchievementLast60);
    if (last60 != nullptr && !last60->IsAwarded() && m_ElapsedTime >= 60.0f)
    {
        last60->Award(this);
        GetHUD()->PushAchievement(last60);
    }
}

void ASpaceShooterGameModeBase::RequestLeaderboards()
{
    GetNetworkManager()->RequestLeaderboard(kBrainCloudMainLeaderboardID);
    GetNetworkManager()->RequestLeaderboard(kBrainCloudDailyLeaderboardID);
    GetNetworkManager()->RequestCountryLeaderboard();
}

void ASpaceShooterGameModeBase::OnShipHasTakenDamage(AShip* ship, int damageTaken, int currentHealth, int currentShield)
{
    float healthPct = (float)currentHealth / (float)kShipInitialHealth;
    float shieldPct = (float)currentShield / (float)kShipInitialShieldHealth;
    m_HUD->UpdateShipDamageHUD(healthPct, shieldPct);
}

void ASpaceShooterGameModeBase::OnShipHasPickedUpShield(class AShip* ship, int currentShield)
{
    float healthPct = (float)ship->GetHealth() / (float)kShipInitialHealth;
    float shieldPct = (float)currentShield / (float)kShipInitialShieldHealth;
    m_HUD->UpdateShipDamageHUD(healthPct, shieldPct);
}

void ASpaceShooterGameModeBase::OnShipHasExploded(AShip* ship)
{
    m_GameState = GameModeState::GameOver;
    m_EndOfGameDisplayTime = kEndOfGameDisplayDuration;
    m_HUD->ShowGameOverHUD();
    
    // Update the statistics
    Statistic* gamesPlayed = GetStatisticsManager()->GetStatisticByName(kBrainCloudStatGamesPlayed);
    if (gamesPlayed != nullptr)
        gamesPlayed->ApplyIncrement();
        
    // Send all the statistics increments to brainCloud now that the game has ended
    FString jsonData = GetStatisticsManager()->GetFormatedIncrementsData();
    GetNetworkManager()->IncrementUserStatistics(jsonData);
}

void ASpaceShooterGameModeBase::OnBossHasExploded(ABoss* boss)
{
    m_GameState = GameModeState::Victory;
    m_EndOfGameDisplayTime = kEndOfGameDisplayDuration;
    m_HUD->ShowGameWonHUD();

    GetSpawner()->StopSpawning();
    GetSpawner()->ExplodeAllActive();
    
    // The user beat the boss level, update the user's progress
    bool needsSync = m_UserData.SetLevelCompleted(m_LevelIndex);
    if (needsSync)
        GetNetworkManager()->UpdateUserEntityData(m_UserData.GetEntityID(), m_UserData.GetEntityType(), m_UserData.GetJsonData());
    
    // Update the statistics
    Statistic* gamesPlayed = GetStatisticsManager()->GetStatisticByName(kBrainCloudStatGamesPlayed);
    if (gamesPlayed != nullptr)
        gamesPlayed->ApplyIncrement();

    // Send all the statistics increments to brainCloud now that the game has ended
    FString jsonData = GetStatisticsManager()->GetFormatedIncrementsData();
    GetNetworkManager()->IncrementUserStatistics(jsonData);
}

void ASpaceShooterGameModeBase::OnAuthenticationRequestCompleted(AuthenticationData* authenticationData)
{
    if (m_GameState == GameModeState::Authenticating)
    {
        m_GameState = GameModeState::LoadingData;

        GetDialogManager()->HideConnectingDialog();
        GetDialogManager()->ShowMainMenuDialog();
        
        if(authenticationData && authenticationData->levelData.size() > 0)
        {
            GetSpawner()->SetLevelData(authenticationData->levelData);
            m_LevelCount = authenticationData->levelData.size();
            
            for (const LevelData& ld : authenticationData->levelData)
            {
                m_LevelDurations.push_back(ld.GetDuration());
                m_LevelDescriptions.push_back(ld.GetDescription());
            }
        }
        else
            GetNetworkManager()->RequestGlobalEntityLevelData();
        
        
        if(authenticationData && authenticationData->mainLeaderboard)
            GetLeaderboardsManager()->AddLeaderboard(*authenticationData->mainLeaderboard);
        else
            GetNetworkManager()->RequestLeaderboard(kBrainCloudMainLeaderboardID);
            
        
        if(authenticationData && authenticationData->dailyLeaderboard)
            GetLeaderboardsManager()->AddLeaderboard(*authenticationData->dailyLeaderboard);
        else
            GetNetworkManager()->RequestLeaderboard(kBrainCloudDailyLeaderboardID);

        
        if(authenticationData && authenticationData->countryLeaderboard)
            GetLeaderboardsManager()->AddLeaderboard(*authenticationData->countryLeaderboard);
        else
            GetNetworkManager()->RequestCountryLeaderboard();

        
        if(authenticationData && authenticationData->statistics.size() > 0)
            GetStatisticsManager()->SetStatistics(authenticationData->statistics);
        else
            GetNetworkManager()->RequestUserStatistics();

        
        if(authenticationData && authenticationData->achievements.size() > 0)
            GetAchievementsManager()->SetAchievements(authenticationData->achievements);
        else
            GetNetworkManager()->RequestAchievements();
        
        
        if(authenticationData && authenticationData->userData)
            m_UserData = UserData(*(authenticationData->userData));
        else
            GetNetworkManager()->RequestUserEntityData();
    }
}

void ASpaceShooterGameModeBase::OnAuthenticationRequestFailed(const FString& errorMessage)
{
    if (m_GameState == GameModeState::Authenticating)
    {
        m_GameState = GameModeState::Gameplay;
        
        GetDialogManager()->HideConnectingDialog();
        GetDialogManager()->ShowErrorDialog(errorMessage);
    }
}

void ASpaceShooterGameModeBase::OnLogOutRequestCompleted()
{
    UBrainCloudDialogWidget* brainCloudDialog = Cast<UBrainCloudDialogWidget>(GetDialogManager()->GetDialogByType(UDialogWidget::Type::BrainCloud));
    brainCloudDialog->Refresh();
}

void ASpaceShooterGameModeBase::OnLeaderboardRequestCompleted(const Leaderboard& leaderboard)
{
    GetLeaderboardsManager()->AddLeaderboard(leaderboard);
    
    if (IsGameOver())
    {
        if (m_Mode == Mode::Endless)
        {
            GetDialogManager()->ShowPlayAgainDialog();
            GetDialogManager()->ShowLeaderboardsDialog();
        }
    }
}

void ASpaceShooterGameModeBase::OnPostScoreToLeaderboardRequestCompleted()
{
    GetLeaderboardsManager()->SetUserTime(m_ElapsedTime);
    RequestLeaderboards();
}

void ASpaceShooterGameModeBase::OnPostScoreToAllLeaderboardsRequestCompleted()
{
    GetLeaderboardsManager()->SetUserTime(m_ElapsedTime);
    RequestLeaderboards();
}

void ASpaceShooterGameModeBase::OnGlobalEntityLevelDataRequestCompleted(const std::vector<LevelData>& levelData)
{
    GetSpawner()->SetLevelData(levelData);
    m_LevelCount = levelData.size();
    
    for (const LevelData& ld : levelData)
    {
        m_LevelDurations.push_back(ld.GetDuration());
        m_LevelDescriptions.push_back(ld.GetDescription());
    }
    
    GetDialogManager()->HideConnectingDialog();
    GetDialogManager()->ShowMainMenuDialog();
}

void ASpaceShooterGameModeBase::OnUserStatisticsRequestCompleted(const std::vector<Statistic>& statistics)
{
    GetStatisticsManager()->SetStatistics(statistics);
}

void ASpaceShooterGameModeBase::OnIncrementUserStatisticsCompleted(const std::vector<Statistic>& statistics)
{
    GetStatisticsManager()->SetStatistics(statistics);
}

void ASpaceShooterGameModeBase::OnReadAchievementsRequestCompleted(const std::vector<Achievement>& achievements)
{
    GetAchievementsManager()->SetAchievements(achievements);
}

void ASpaceShooterGameModeBase::OnUserEntityDataRequestCompleted(UserData* userData)
{
    if (userData != nullptr)
        m_UserData = UserData(*userData);
    else
        GetNetworkManager()->CreateUserEntityData();   // User entity for User progress data doesn't exist, create one
}

void ASpaceShooterGameModeBase::OnCreateUserEntityDataRequestCompleted(const FString& entityID, const FString& entityType)
{
    m_UserData = UserData(entityID, entityType);
}

void ASpaceShooterGameModeBase::OnGetIdentitiesRequestCompleted()
{
    UBrainCloudDialogWidget* brainCloudDialog = Cast<UBrainCloudDialogWidget>(GetDialogManager()->GetDialogByType(UDialogWidget::Type::BrainCloud));
    brainCloudDialog->Refresh();
}

void ASpaceShooterGameModeBase::OnAttachEmailIdentityRequestCompleted()
{
    GetDialogManager()->HideConnectingDialog();
    
    UBrainCloudDialogWidget* brainCloudDialog = Cast<UBrainCloudDialogWidget>(GetDialogManager()->GetDialogByType(UDialogWidget::Type::BrainCloud));
    brainCloudDialog->Refresh();
}

void ASpaceShooterGameModeBase::OnAttachEmailIdentityRequestFailed()
{
    GetDialogManager()->HideConnectingDialog();
    GetDialogManager()->ShowErrorDialog("Error: Failed to attach email identity");
}
