// Copyright 2022 bitHeads, Inc. All Rights Reserved.


#include "Achievement.h"
#include "NetworkManager.h"
#include "SpaceShooterGameModeBase.h"


Achievement::Achievement(const FString& achievementID, const FString& title, const FString& description, const FString& status) :
    m_AchievementID(achievementID),
    m_Title(title),
    m_Description(description),
    m_Status(status == "AWARDED" ? Status::Awarded : Status::NotAwarded)
{
    
}

void Achievement::Award(ASpaceShooterGameModeBase* gameMode)
{
    if(m_Status == Status::NotAwarded)
    {
        m_Status = Status::Awarded;
        gameMode->GetNetworkManager()->AwardAchievement(this);
    }
}

bool Achievement::IsAwarded() const
{
    return m_Status == Status::Awarded;
}

FString Achievement::GetStatusString() const
{
    if (m_Status == Status::Awarded)
        return TEXT("Earned");
    return TEXT("");
}

FString Achievement::GetAchievementID() const
{
    return m_AchievementID;
}

FString Achievement::GetTitle() const
{
    return m_Title;
}

FString Achievement::GetDescription() const
{
    return m_Description;
}
