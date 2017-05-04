// Fill out your copyright notice in the Description page of Project Settings.

#include "Outsider.h"
#include "OutsiderCharacter.h"
#include "Candle.h"
#include "Engine.h"

// Sets default values for this component's properties
UCandle::UCandle()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	LeftLight = this->CreateDefaultSubobject<UPointLightComponent>(TEXT("LeftLight"));
	LeftLight->SetRelativeLocation(FVector(0, 0, 0));
	LeftLight->Intensity = 3000.f;
	LeftLight->bAffectsWorld = true;
	LeftLight->SetMobility(EComponentMobility::Movable);
}


// Called when the game starts
void UCandle::BeginPlay()
{
	Super::BeginPlay();

	// ...
	AOutsiderCharacter* MainChar = Cast<AOutsiderCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (MainChar)
	{
		MainChar->OnCandleLighted.AddDynamic(this, &UCandle::WhenTriggered);
	}
}


// Called every frame
void UCandle::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCandle::LightCandle()
{
	TArray<UPointLightComponent*> LightComponents;
	this->GetOwner()->GetComponents<UPointLightComponent>(LightComponents);
	for (int32 i = 0; i<LightComponents.Num(); i++) //Count is zero
	{
		UPointLightComponent* StaticMeshComponent = LightComponents[i]; //null
		FString name = StaticMeshComponent->GetName();
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Black, name);

	}
}

void UCandle::WhenTriggered(uint8 triggerID)
{
	if (triggerID == this->CandleID) LightCandle();
}

