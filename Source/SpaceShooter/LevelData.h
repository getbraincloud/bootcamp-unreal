// Copyright 2022 bitHeads, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include <vector>

/**
 *
 */
class SPACESHOOTER_API LevelData
{
public:
    LevelData();

    struct EnemyType
    {
    public:
        EnemyType(const FString& type, int health);

        FString type;
        int health;
    };
    
    int GetHealthForEnemyType(const FString& enemyType);

    FString GetEntityType() const;
    FString GetEntityID() const;
    FString GetDescription() const;

    int GetIndex() const;
    
    float GetDuration() const;

    int GetAsteroidMinSpawnCount() const;
    int GetAsteroidMaxSpawnCount() const;

    float GetAsteroidMinSpawnTime() const;
    float GetAsteroidMaxSpawnTime() const;

    float GetAsteroidMinSpeed() const;
    float GetAsteroidMaxSpeed() const;

    int GetEnemyMinSpawnCount() const;
    int GetEnemyMaxSpawnCount() const;

    float GetEnemyMinSpawnTime() const;
    float GetEnemyMaxSpawnTime() const;

    float GetEnemyMinSpeed() const;
    float GetEnemyMaxSpeed() const;

    std::vector<EnemyType> GetEnemyTypes();
    std::vector<FString> GetStartingAsteroids();
    std::vector<FString> GetStartingEnemies();
        
    static bool Compare(LevelData& a, LevelData& b);
    
private:
    std::vector<EnemyType> m_EnemyTypes;
    std::vector<FString> m_StartingAsteroids;
    std::vector<FString> m_StartingEnemies;
    FString m_EntityType;
    FString m_EntityID;
    FString m_Description;
    int m_Index;
    float m_Duration;
    int m_AsteroidMinSpawnCount;
    int m_AsteroidMaxSpawnCount;
    float m_AsteroidMinSpawnTime;
    float m_AsteroidMaxSpawnTime;
    float m_AsteroidMinSpeed;
    float m_AsteroidMaxSpeed;
    int m_EnemyMinSpawnCount;
    int m_EnemyMaxSpawnCount;
    float m_EnemyMinSpawnTime;
    float m_EnemyMaxSpawnTime;
    float m_EnemyMinSpeed;
    float m_EnemyMaxSpeed;
};
