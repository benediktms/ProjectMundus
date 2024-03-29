// Copyright © Benedikt Schnatterbeck

#pragma once

#include "CoreMinimal.h"
#include "Character/PM_CharacterBase.h"
#include "PM_PlayerCharacter.generated.h"

class UCameraComponent;

UCLASS()
class PROJECTMUNDUS_API APM_PlayerCharacter : public APM_CharacterBase
{
	GENERATED_BODY()

public:
	APM_PlayerCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
	bool bIsInFirstPerson = true;

private:
	UPROPERTY(EditDefaultsOnly, Category="Camera")
	TObjectPtr<UCameraComponent> PlayerCamera;
};
