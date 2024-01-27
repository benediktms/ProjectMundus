// Copyright © Benedikt Schnatterbeck


#include "Player/PM_PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void APM_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(InputContext);

	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> Subsystem = ULocalPlayer::GetSubsystem<
		UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	check(Subsystem);

	Subsystem->AddMappingContext(InputContext, 0);
}

void APM_PlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void APM_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	TObjectPtr<UEnhancedInputComponent> EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(
		MoveAction, ETriggerEvent::Triggered, this, &APM_PlayerController::Move);
	EnhancedInputComponent->BindAction(
		LookAction, ETriggerEvent::Triggered, this, &APM_PlayerController::Look);
	EnhancedInputComponent->BindAction(
		JumpAction, ETriggerEvent::Triggered, this, &APM_PlayerController::Jump);
	EnhancedInputComponent->BindAction(
		JumpAction, ETriggerEvent::Completed, this, &APM_PlayerController::StopJumping);
	EnhancedInputComponent->BindAction(
		CrouchAction, ETriggerEvent::Completed, this, &APM_PlayerController::Crouch);
}

void APM_PlayerController::Move(const FInputActionValue& Value)
{
	const FVector2D MoveVector = Value.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (TObjectPtr<APawn> ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardVector, MoveVector.Y);
		ControlledPawn->AddMovementInput(RightVector, MoveVector.X);
	}
}

void APM_PlayerController::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();
	if (TObjectPtr<APawn> ControlledPawn = GetPawn<APawn>())
	{
		if (LookAxisVector.X > 0.3)
		{
			bIsTurningLeft = false;
			bIsTurningRight = true;
		}
		else if (LookAxisVector.X < -0.3)
		{
			bIsTurningLeft = true;
			bIsTurningRight = false;
		}
		else
		{
			bIsTurningLeft = false;
			bIsTurningRight = false;
		}

		ControlledPawn->AddControllerYawInput(LookAxisVector.X);
		ControlledPawn->AddControllerPitchInput(LookAxisVector.Y);
		ControlledPawn->SetActorRotation(GetControlRotation());
	}
}

void APM_PlayerController::Jump(const FInputActionValue& Value)
{
	if (TObjectPtr<ACharacter> ControlledCharacter = GetPawn<ACharacter>())
	{
		if (ControlledCharacter->bIsCrouched)
		{
			ControlledCharacter->UnCrouch();
		}

		ControlledCharacter->Jump();
	}
}

void APM_PlayerController::StopJumping(const FInputActionValue& Value)
{
	if (TObjectPtr<ACharacter> ControlledCharacter = GetPawn<ACharacter>())
	{
		ControlledCharacter->StopJumping();
	}
}

void APM_PlayerController::Crouch(const FInputActionValue& Value)
{
	if (TObjectPtr<ACharacter> ControlledCharacter = GetPawn<ACharacter>())
	{
		if (ControlledCharacter->bIsCrouched)
		{
			ControlledCharacter->UnCrouch();
		}
		else
		{
			ControlledCharacter->Crouch();
		}
	}
}
