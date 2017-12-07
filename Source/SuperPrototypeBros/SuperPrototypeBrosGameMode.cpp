// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "SuperPrototypeBrosGameMode.h"
#include "Characters/SuperPrototypeBrosCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

ASuperPrototypeBrosGameMode::ASuperPrototypeBrosGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> OneBulletChar(TEXT("/Game/SideScrollerCPP/Blueprints/CatCharacter"));
	if (OneBulletChar.Class != NULL)
	{
		DefaultPawnClass = OneBulletChar.Class;
	}
}

void ASuperPrototypeBrosGameMode::BeginPlay()
{
	UGameplayStatics::CreatePlayer(this);
}
