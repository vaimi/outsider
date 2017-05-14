// Fill out your copyright notice in the Description page of Project Settings.

#include "Outsider.h"
#include "FlintSteel.h"


// Sets default values
AFlintSteel::AFlintSteel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Flint = this->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Flint"));
	Flint->SetWorldScale3D(FVector(0.15f, 0.15f, 0.15f));
	SetRootComponent(Flint);
	
	Steel = this->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Steel"));
	Steel->SetRelativeLocation(FVector(45.065102f, 0.f, 21.83375f));
	Steel->SetRelativeRotation(FRotator(69.86013f, 60.21883f, -7.505371f));
	Steel->SetWorldScale3D(FVector(10.f, 10.f, 10.f));
	Steel->SetupAttachment(RootComponent);

	BoxComponent = this->CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxComponent->SetupAttachment(RootComponent);
	BoxComponent->SetCollisionProfileName(TEXT("BlockAll"));
	BoxComponent->SetRelativeLocation(FVector(30.527344f, 0.23112f, 24.209034f));
	BoxComponent->SetWorldScale3D(FVector(1.875f, 1.5f, 0.7f));
}

// Called when the game starts or when spawned
void AFlintSteel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFlintSteel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFlintSteel::PickUp()
{
	this->Destroy();
}

