// Copyright © Benedikt Schnatterbeck

#pragma once

#include "CoreMinimal.h"
#include "Character/PM_CharacterBase.h"
#include "PM_PlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class PROJECTMUNDUS_API APM_PlayerCharacter : public APM_CharacterBase
{
	GENERATED_BODY()

public:
	APM_PlayerCharacter();

private:
	UPROPERTY(EditDefaultsOnly, Category="Camera")
	TObjectPtr<UCameraComponent> ThirdPersonCamera;

	UPROPERTY(EditDefaultsOnly, Category="Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;
};
