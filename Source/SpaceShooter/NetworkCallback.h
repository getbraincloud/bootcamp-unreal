// Copyright 2022 bitHeads, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Leaderboard.h"

/**
 * 
 */
class SPACESHOOTER_API NetworkCallback
{
public:
    NetworkCallback() = default;
    virtual ~NetworkCallback() = default;
    
    virtual void OnAuthenticationRequestCompleted() {}
    virtual void OnAuthenticationRequestFailed(const FString& errorMessage) {}
    
    virtual void OnLogOutRequestCompleted() {}
    virtual void OnLogOutRequestFailed() {}
    
    virtual void OnUpdateUsernameRequestCompleted() {}
    virtual void OnUpdateUsernameRequestFailed() {}
    
    virtual void OnLeaderboardRequestCompleted(const Leaderboard& leaderboard) {}
    virtual void OnLeaderboardRequestFailed() {}
    
    //TODO: Add Network callback methods here
};
