// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "OutsiderCharacter.h"
#include "Candelabra.generated.h"

UCLASS()
class OUTSIDER_API ACandelabra : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACandelabra();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		uint8 CandleID = 0;

	UFUNCTION()
		void WhenTriggered(uint8 triggerID);

	void LightCandles();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
	class UPointLightComponent* LeftLight;

	UPROPERTY(VisibleAnywhere)
	class UPointLightComponent* RightLight;

	
};
