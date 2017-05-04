// Fill out your copyright notice in the Description page of Project Settings.

#include "Outsider.h"
#include "OutsiderCharacter.h"
#include "Candelabra.h"
#include "Engine.h"

// Sets default values
ACandelabra::ACandelabra()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = this->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);

	LeftLight = this->CreateDefaultSubobject<UPointLightComponent>(TEXT("LeftLight"));
	LeftLight->SetupAttachment(RootComponent);
	LeftLight->SetRelativeLocation(FVector(-35.f, 20.f, 36.f));
	LeftLight->Intensity = 500.f;
	LeftLight->bVisible = false;
	LeftLight->SetMobility(EComponentMobility::Stationary);

	RightLight = this->CreateDefaultSubobject<UPointLightComponent>(TEXT("RightLight"));
	RightLight->SetupAttachment(RootComponent);
	RightLight->SetRelativeLocation(FVector(35.f, 20.f, 36.f));
	RightLight->Intensity = 500.f;
	RightLight->bVisible = false;
	RightLight->SetMobility(EComponentMobility::Stationary);
}

// Called when the game starts or when spawned
void ACandelabra::BeginPlay()
{
	Super::BeginPlay();
	
	AOutsiderCharacter* MainChar = Cast<AOutsiderCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (MainChar)
	{
		MainChar->OnCandleLighted.AddDynamic(this, &ACandelabra::WhenTriggered);
	}
}

// Called every frame
void ACandelabra::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACandelabra::WhenTriggered(uint8 triggerID)
{
	if (triggerID == this->CandleID) LightCandles();
}

void ACandelabra::LightCandles()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Black, "Lights on!");
	LeftLight->ToggleVisibility();
	RightLight->ToggleVisibility();
}

