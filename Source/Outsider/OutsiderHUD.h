// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "OutsiderHUD.generated.h"

UCLASS()
class AOutsiderHUD : public AHUD
{
	GENERATED_BODY()

public:
	AOutsiderHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:

};

