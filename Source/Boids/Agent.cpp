// Fill out your copyright notice in the Description page of Project Settings.


#include "Agent.h"

// Sets default values
AAgent::AAgent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshObj = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AgentMesh"));
	SetRootComponent(MeshObj);

	Velocity = FVector(0.f);
}

// Called when the game starts or when spawned
void AAgent::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAgent::Init(UStaticMeshComponent* Mesh, int Id)
{
	UE_LOG(LogTemp, Warning, TEXT("Agent initialized.") );

	MeshObj->SetStaticMesh(Mesh->GetStaticMesh());
}

FVector AAgent::GetVelocity()
{
	return Velocity;
}

void AAgent::SetVelocity(FVector Vel)
{
	Velocity = Vel;
}

// Called every frame
void AAgent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FVector Loc = GetActorLocation();
	SetActorLocation(Loc + Velocity);
}
