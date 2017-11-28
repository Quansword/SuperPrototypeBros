// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "SuperPrototypeBrosCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ASuperPrototypeBrosCharacter::ASuperPrototypeBrosCharacter()
{
	// Set size for collision capsule

	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	AimCone = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AimCone"));
	AimCone->SetupAttachment(RootComponent);
	AimCone->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	AimCone->RelativeRotation = FRotator(-90.f, 0.f, 0.f);
	AimCone->RelativeLocation = FVector(50, 0, 0);

	moveAxis = 1;
	upAim = 0;
	rightAim = 0;
	rAiming = 0;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void ASuperPrototypeBrosCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASuperPrototypeBrosCharacter::MoveRight);
	PlayerInputComponent->BindAxis("AimUp", this, &ASuperPrototypeBrosCharacter::AimUp);
	PlayerInputComponent->BindAxis("AimRight", this, &ASuperPrototypeBrosCharacter::AimRight);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &ASuperPrototypeBrosCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ASuperPrototypeBrosCharacter::TouchStopped);
}

void ASuperPrototypeBrosCharacter::MoveRight(float Value)
{
	// add movement in that direction

	if (Value > 0.1f)
	{
		moveAxis = 1;
		this->SetActorRotation(FRotator(0, -90, 0));
	}
	else if (Value < -0.1f)
	{
		moveAxis = -1;
		this->SetActorRotation(FRotator(0, 90, 0));
	}
	AddMovementInput(FVector(0.f,-1.f,0.f), Value);
}

void ASuperPrototypeBrosCharacter::AimUp(float Value)
{
	upAim = Value;
}

void ASuperPrototypeBrosCharacter::AimRight(float Value)
{
	rightAim = Value;
}

void ASuperPrototypeBrosCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	Jump();
}

void ASuperPrototypeBrosCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	StopJumping();
}

void ASuperPrototypeBrosCharacter::Tick(float DeltaTime)
{
	if ((upAim < 0.1f && upAim > -0.1f) && (rightAim < 0.1f && rightAim > -0.1f))
	{
		AimCone->SetWorldRotation(FRotator(0, 0, -90 * moveAxis));
	}
	else
	{
		if (rightAim > 0)
		{
			rAiming = -1;
		}
		else if (rightAim < 0)
		{
			rAiming = 1;
		}

		if (upAim > 0)
		{
			AimCone->SetWorldRotation(FRotator(0, 0, rAiming * FMath::RadiansToDegrees(atan2f(fabs(rightAim), upAim))));
		}
		else if (upAim < 0)
		{
			AimCone->SetWorldRotation(FRotator(0, 0, -rAiming * (180 + FMath::RadiansToDegrees(atan2f(fabs(rightAim), fabs(upAim))))));
		}
		else
		{
			AimCone->SetWorldRotation(FRotator(0, 0, rAiming * 90));
		}
	}
}
