// Copyright © Benedikt Schnatterbeck


#include "Character/PM_CharacterBase.h"

APM_CharacterBase::APM_CharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APM_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void APM_CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
