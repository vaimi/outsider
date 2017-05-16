// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "OutsiderCharacter.h"
#include "Door.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OUTSIDER_API UDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		TArray<uint8> Triggers;

	TArray<uint8> CompletedTriggers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UAudioComponent* DoorAudioComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UAudioComponent* WindAudioComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float WaitBeforeOpen = 300;

	void OpenAngle();
	
	float rotationRate;
	float rotationEnd;
	float currentAngle = 0.f; 
	bool rotate = false;

	UFUNCTION()
		void WhenTriggered(uint8 triggerID);
	
};
