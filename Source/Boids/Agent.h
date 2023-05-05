// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Agent.generated.h"

UCLASS()
class BOIDS_API AAgent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAgent();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Init( UStaticMeshComponent* Mesh, int Id );

	FVector GetVelocity();

	void SetVelocity(FVector Vel);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UStaticMeshComponent* MeshObj;

	FVector Velocity;
};
