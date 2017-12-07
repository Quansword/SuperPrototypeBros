// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "SuperPrototypeBrosGameMode.h"
#include "Characters/SuperPrototypeBrosCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

ASuperPrototypeBrosGameMode::ASuperPrototypeBrosGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> OneBulletChar(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	static ConstructorHelpers::FClassFinder<APawn> CatChar(TEXT("/Game/SideScrollerCPP/Blueprints/CatCharacter"));
	OBPawn = OneBulletChar.Class;
	CatPawn = CatChar.Class;

	if (OBPawn != NULL)
	{
		DefaultPawnClass = OBPawn;
	}
}

void ASuperPrototypeBrosGameMode::BeginPlay()
{
	DefaultPawnClass = CatPawn;

	UGameplayStatics::CreatePlayer(this);
}
