// Copyright © Benedikt Schnatterbeck


#include "Character/PM_AnimInstance.h"

#include "KismetAnimationLibrary.h"
#include "Character/PM_PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Player/PM_PlayerController.h"

void UPM_AnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (auto Owner = Cast<APM_PlayerCharacter>(TryGetPawnOwner()))
	{
		PMPlayerCharacter = Owner;
		PMCharacterMovement = Owner->GetCharacterMovement();
	}
}

void UPM_AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (PMCharacterMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(PMCharacterMovement->Velocity);
		Direction = UKismetAnimationLibrary::CalculateDirection(PMCharacterMovement->Velocity,
		                                                        PMPlayerCharacter->GetActorRotation());
		bIsFalling = PMCharacterMovement->IsFalling();
	}

	if (PMPlayerCharacter)
	{
		bIsCrouching = PMPlayerCharacter->bIsCrouched;
		if (const auto PlayerController = Cast<APM_PlayerController>(PMPlayerCharacter->Controller))
		{
			bIsTurningRight = PlayerController->bIsTurningRight;
			bIsTurningLeft = PlayerController->bIsTurningLeft;
		}
	}
}
