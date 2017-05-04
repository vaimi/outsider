// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "OutsiderCharacter.h"
#include "Candle.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OUTSIDER_API UCandle : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCandle();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	bool isLighted = false;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		uint8 CandleID = 0;
	
	UFUNCTION()
		void WhenTriggered(uint8 triggerID);

	void LightCandle();

	UPROPERTY(VisibleAnywhere)
	class UPointLightComponent* LeftLight;

	UPROPERTY(VisibleAnywhere)
	class UPointLightComponent* RightLight;
	
};
