// Copyright 2022 bitHeads, Inc. All Rights Reserved.


#include "NetworkManager.h"
#include "Constants.h"


UNetworkManager::UNetworkManager() :
    m_Callback(nullptr)
{
   
}

void UNetworkManager::Tick(float DeltaTime)
{
}

void UNetworkManager::SetCallback(NetworkCallback* callback)
{
    m_Callback = callback;
}

FString UNetworkManager::GetBrainCloudClientVersion()
{
    return "";
}

bool UNetworkManager::IsAuthenticated()
{
    return false;
}
