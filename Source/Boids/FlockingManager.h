// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FlockingManager.generated.h"

#define AGENT_COUNT 10

UCLASS()
class BOIDS_API UFlockingManager : public UObject
{
	GENERATED_BODY()

public:
	void Init(UWorld* World, UStaticMeshComponent* Mesh);

	void Flock();

private:
	UWorld* WorldObj;	

	bool bInitialized;
	
	TArray<class AAgent*> Agents;

	FVector Rule1(AAgent* BAgent);
	FVector Rule2(AAgent* BAgent);
	FVector Rule3(AAgent* BAgent);

	void LimitVelocity(AAgent* BAgent);
};
