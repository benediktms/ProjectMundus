// Copyright © Benedikt Schnatterbeck

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PM_CharacterBase.generated.h"

UCLASS()
class PROJECTMUNDUS_API APM_CharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	APM_CharacterBase();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
};
