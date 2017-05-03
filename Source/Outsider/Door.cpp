// Fill out your copyright notice in the Description page of Project Settings.

#include "Outsider.h"
#include "Door.h"
#include "OutsiderCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"

// Sets default values for this component's properties
UDoor::UDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoor::BeginPlay()
{
	AOutsiderCharacter* MainChar = Cast<AOutsiderCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (MainChar)
	{
		MainChar->OnCandleLighted.AddDynamic(this, &UDoor::WhenTriggered);
	}
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDoor::OpenAngle()
{
	GetOwner()->SetActorRotation(FRotator(0.f, 90.f, 0.f));
}

void UDoor::WhenTriggered(uint8 triggerID)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Black, "Got a broadcast");
	for (auto& trigger : Triggers)
	{
		if (trigger == triggerID)
		{
			CompletedTriggers.Add(trigger);
		}
	}
	if (CompletedTriggers.Num() == Triggers.Num())
	{
		this->OpenAngle();
	}
}
