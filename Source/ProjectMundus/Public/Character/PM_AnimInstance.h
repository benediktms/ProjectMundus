// Copyright © Benedikt Schnatterbeck

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PM_AnimInstance.generated.h"

class UCharacterMovementComponent;
class APM_PlayerCharacter;

UCLASS()
class PROJECTMUNDUS_API UPM_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<APM_PlayerCharacter> PMPlayerCharacter;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	TObjectPtr<UCharacterMovementComponent> PMCharacterMovement;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	float GroundSpeed;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	float Direction;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	bool bIsFalling;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	bool bIsCrouching;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	bool bIsTurningRight;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	bool bIsTurningLeft;
};
