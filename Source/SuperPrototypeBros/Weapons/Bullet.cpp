// Fill out your copyright notice in the Description page of Project Settings.

#include "Bullet.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ABullet::ABullet()
{
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetRelativeLocation(FVector(0, 0, 0));
	Capsule->SetCapsuleHalfHeight(22.f);
	Capsule->SetEnableGravity(false);
	SetRootComponent(Capsule);
}
