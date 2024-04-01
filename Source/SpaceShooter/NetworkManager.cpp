// Copyright 2022 bitHeads, Inc. All Rights Reserved.


#include "NetworkManager.h"
#include "Constants.h"


UNetworkManager::UNetworkManager() :
    m_BrainCloud(nullptr),
    m_Callback(nullptr)
{
    m_BrainCloud = CreateDefaultSubobject<UBrainCloudWrapper>("BrainCloudWrapper");
    m_BrainCloud->initialize(kBrainCloudServer, kBrainCloudAppSecret, kBrainCloudAppID, kBrainCloudAppVersion);

    FString version = m_BrainCloud->getClient()->getBrainCloudClientVersion();
    FString profileId = m_BrainCloud->getStoredProfileId();
    FString anonymousId = m_BrainCloud->getStoredAnonymousId();
    UE_LOG(LogTemp, Warning, TEXT("UNetworkManager::UNetworkManager() BrainCloud client version %s (%s) (%s)"), *version, *profileId, *anonymousId);
    
    // Setup the callback functions
    m_AuthenticationCallback.successCallback.BindUObject(this, &UNetworkManager::OnAuthenticationCallback);
    m_AuthenticationCallback.failureCallback.BindUObject(this, &UNetworkManager::OnAuthenticationError);

    m_LogOutCallback.successCallback.BindUObject(this, &UNetworkManager::OnLogOutCallback);
    m_LogOutCallback.failureCallback.BindUObject(this, &UNetworkManager::OnLogOutError);
}

void UNetworkManager::Tick(float DeltaTime)
{
    m_BrainCloud->runCallbacks();
}

void UNetworkManager::SetCallback(NetworkCallback* callback)
{
    m_Callback = callback;
}

bool UNetworkManager::HasAuthenticatedPreviously()
{
    return m_BrainCloud->getStoredProfileId() != "" && m_BrainCloud->getStoredAnonymousId() != "";
}

bool UNetworkManager::IsAuthenticated()
{
    return m_BrainCloud->getClient()->isAuthenticated();
}

void UNetworkManager::EndSession()
{
    m_BrainCloud->logout(false, nullptr);
    m_BrainCloud->runCallbacks();
}

void UNetworkManager::LogOut()
{
    if (IsAuthenticated())
    {
        m_BrainCloud->logout(true, &m_LogOutCallback);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("UNetworkManager::RequestLogOut() Failed: user is not authenticated."));

        if (m_Callback != nullptr)
            m_Callback->OnLogOutRequestFailed();
    }
}

void UNetworkManager::Reconnect()
{
    m_BrainCloud->reconnect(&m_AuthenticationCallback);
}

void UNetworkManager::RequestAnonymousAuthentication()
{
    m_BrainCloud->authenticateAnonymous(&m_AuthenticationCallback);
}

void UNetworkManager::OnAuthenticationCallback(const FString& jsonData)
{
    UE_LOG(LogTemp, Warning, TEXT("UNetworkManager::OnAuthenticationCallback(%s)"), *jsonData);
        
    if(m_Callback != nullptr)
        m_Callback->OnAuthenticationRequestCompleted();
}

void UNetworkManager::OnAuthenticationError(int statusCode, int reasonCode, const FString& jsonError)
{
    UE_LOG(LogTemp, Warning, TEXT("UNetworkManager::OnAuthenticationError(%s)"), *jsonError);
    
    FString errorMessage = "Authentication failed. ";
    
    if(m_Callback != nullptr)
        m_Callback->OnAuthenticationRequestFailed(errorMessage);
}

void UNetworkManager::OnLogOutCallback(const FString& jsonData)
{
    UE_LOG(LogTemp, Warning, TEXT("UNetworkManager::OnLogOutCallback(%s)"), *jsonData);

    if (m_Callback != nullptr)
        m_Callback->OnLogOutRequestCompleted();
}

void UNetworkManager::OnLogOutError(int statusCode, int reasonCode, const FString& jsonError)
{
    UE_LOG(LogTemp, Warning, TEXT("UNetworkManager::OnLogOutError(%s)"), *jsonError);

    if (m_Callback != nullptr)
        m_Callback->OnLogOutRequestFailed();
}
