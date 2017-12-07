// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SuperPrototypeBrosGameMode.generated.h"

UCLASS(minimalapi)
class ASuperPrototypeBrosGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	TSubclassOf<APawn> OBPawn;
	TSubclassOf<APawn> CatPawn;

public:
	ASuperPrototypeBrosGameMode();

	virtual void BeginPlay() override;
};



