// Fill out your copyright notice in the Description page of Project Settings.


#include "FlockingManager.h"
#include "Agent.h"

void UFlockingManager::Init(UWorld* World, UStaticMeshComponent* Mesh)
{
	UE_LOG(LogTemp, Warning, TEXT("MANAGER INIT"));

	WorldObj = World;
	float Incr = (PI * 2.f) / AGENT_COUNT;
	for (int i = 0; i < AGENT_COUNT; i++)
	{
		if(World != nullptr)
		{
			FRotator Rotation = FRotator();

			FVector Location = FVector();
			Location.X = FMath::Sin(Incr * i) * 150.f;
			Location.Z = FMath::Cos(Incr * i) * 150.f;

			AAgent * Agent = World->SpawnActor<AAgent>(Location, Rotation);
			Agent->Init(Mesh, i);
			Agents.Add(Agent);
		}
	}

	bInitialized = true;
}

void UFlockingManager::Flock()
{
	if (bInitialized)
	{
		for (AAgent* Agent : Agents)
		{
			FVector V1 = Rule1(Agent);
			FVector V2 = Rule2(Agent);
			FVector V3 = Rule3(Agent);

			Agent->SetVelocity(Agent->GetVelocity() + V1 + V2 + V3);
			LimitVelocity(Agent);
		}
	}
}

FVector UFlockingManager::Rule1(AAgent* BAgent)
{
	FVector Pcj;

	for (AAgent* Agent : Agents)
	{
		if (Agent != BAgent)
		{
			Pcj = Pcj + Agent->GetActorLocation();
		}
	}

	Pcj = Pcj / (Agents.Num() - 1);
	return (Pcj - BAgent->GetActorLocation()) / 100;
}

FVector UFlockingManager::Rule2(AAgent* BAgent)
{
	FVector C = FVector(0.f);

	for (AAgent* Agent : Agents)
	{
		if (Agent != BAgent)
		{
			if (FVector::Dist(Agent->GetActorLocation(), BAgent->GetActorLocation()) < 100)
			{
				C = C - (Agent->GetActorLocation() - BAgent->GetActorLocation());
			}
		}
	}

	return C;
}

FVector UFlockingManager::Rule3(AAgent* BAgent)
{
	FVector Pvj;

	for (AAgent* Agent : Agents)
	{
		if (Agent != BAgent)
		{
			Pvj = Pvj + Agent->GetVelocity();
		}
	}

	Pvj = Pvj / (Agents.Num() - 1);
	return (Pvj - BAgent->GetVelocity()) / 8;
}

void UFlockingManager::LimitVelocity(AAgent* BAgent)
{
	const int Vlim = 10;
	FVector V;

	if (BAgent->GetVelocity().Size() > Vlim)
	{
		BAgent->SetVelocity((BAgent->GetVelocity() / BAgent->GetVelocity().Size()) * Vlim);
	}
}
