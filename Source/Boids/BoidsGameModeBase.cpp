// Copyright Epic Games, Inc. All Rights Reserved.


#include "BoidsGameModeBase.h"
#include "FlockingManager.h"

ABoidsGameModeBase::ABoidsGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;

	AgentMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AgentMesh"));
}

void ABoidsGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("GAMEMODE BEGINPLAY()"));
	Manager = NewObject<UFlockingManager>();
	Manager->Init( GetWorld(), AgentMesh );
}

void ABoidsGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Manager->Flock();
}
