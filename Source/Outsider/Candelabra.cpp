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

	FVector CandleScale = FVector(0.4f, 0.4f, 0.4f);

	LeftLight = this->CreateDefaultSubobject<UParticleSystemComponent>(TEXT("LeftLight"));
	LeftLight->SetupAttachment(RootComponent);
	LeftLight->SetRelativeLocation(FVector(-33.06255f, 21.131275f, 38.799744f));
	LeftLight->SetWorldScale3D(CandleScale);
	LeftLight->bVisible = false;
	LeftLight->SetMobility(EComponentMobility::Stationary);

	RightLight = this->CreateDefaultSubobject<UParticleSystemComponent>(TEXT("RightLight"));
	RightLight->SetupAttachment(RootComponent);
	RightLight->SetRelativeLocation(FVector(33.876526f, 20.970655f, 39.f));
	RightLight->SetWorldScale3D(CandleScale);
	RightLight->bVisible = false;
	RightLight->SetMobility(EComponentMobility::Stationary);

	BoxComponent = this->CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxComponent->SetupAttachment(RootComponent);
	BoxComponent->SetCollisionProfileName(TEXT("BlockAll"));
	BoxComponent->SetRelativeLocation(FVector(0.f, 15.f, 14.f));
	BoxComponent->SetWorldScale3D(FVector(1.2f, 0.5f, 0.8f));

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
	LeftLight->SetVisibility(true);
	RightLight->SetVisibility(true);
}

