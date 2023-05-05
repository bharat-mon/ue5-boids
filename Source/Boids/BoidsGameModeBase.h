// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BoidsGameModeBase.generated.h"

// Forward declarations
class UStaticMeshComponent;
class UFlockingManager;

UCLASS()
class BOIDS_API ABoidsGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABoidsGameModeBase();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* AgentMesh;

	UPROPERTY()
	UFlockingManager* Manager;
};
