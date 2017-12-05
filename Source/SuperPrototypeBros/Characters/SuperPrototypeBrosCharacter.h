// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SuperPrototypeBrosCharacter.generated.h"

UCLASS(config=Game)
class ASuperPrototypeBrosCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Aim, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* AimCone;

protected:
	/** Called for side to side input */
	void MoveRight(float Val);

	void AimUp(float Val);

	void AimRight(float Val);

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

	float moveAxis, upAim, rightAim;
	short rAiming;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool loaded;

public:
	ASuperPrototypeBrosCharacter();

	virtual void Tick(float deltaTime) override;

	FORCEINLINE class UStaticMeshComponent* GetAimCone() const { return AimCone; }
};
