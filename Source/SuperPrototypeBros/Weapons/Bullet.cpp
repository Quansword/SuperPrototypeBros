// Fill out your copyright notice in the Description page of Project Settings.

#include "Bullet.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	SetRootComponent(Capsule);
	Capsule->SetCapsuleHalfHeight(22.f);
	Capsule->SetEnableGravity(false);
	Capsule->OnComponentBeginOverlap.AddDynamic(this, &ABullet::Hit);
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABullet::Shoot(FVector position, float angle)
{

}

void ABullet::Catch()
{

}

void ABullet::Hit(UPrimitiveComponent* ThisComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}
