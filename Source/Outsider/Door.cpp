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
	

	DoorAudioComponent = CreateDefaultSubobject<UAudioComponent>(
		TEXT("Audio Component")
	);

	DoorAudioComponent->bAutoActivate = false;

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
	if (this->rotate)
	{
		this->currentAngle += this->rotationRate * DeltaTime;
		if (currentAngle < this->rotationEnd)
		{
			currentAngle = this->rotationEnd;
			this->rotate = false;
		}
		GetOwner()->SetActorRotation(FRotator(0.f, currentAngle, 0.f));
	}
	// ...
}

void UDoor::OpenAngle()
{
	this->rotationEnd = -90.f;
	this->rotationRate = this->rotationEnd/2.5;
	this->rotate = true;
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
		this->DoorAudioComponent->Play();
		this->OpenAngle();
	}
}
