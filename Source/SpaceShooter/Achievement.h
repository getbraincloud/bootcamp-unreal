// Copyright 2022 bitHeads, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/**
 *
 */
class SPACESHOOTER_API Achievement
{
public:
    Achievement(const FString& achievementID, const FString& title, const FString& description, const FString& status);
        
    void Award(class ASpaceShooterGameModeBase* gameMode);
    
    bool IsAwarded() const;
    FString GetStatusString() const;
    FString GetAchievementID() const;
    FString GetTitle() const;
    FString GetDescription() const;
    
private:
    enum class Status
    {
        Awarded,
        NotAwarded
    };
    
    FString m_AchievementID;
    FString m_Title;
    FString m_Description;
    Status m_Status;
};
