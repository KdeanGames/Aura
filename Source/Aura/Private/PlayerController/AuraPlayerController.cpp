// Copyright © 2024 Kdean Games. All Rights Reserved.


#include "PlayerController/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(AuraInputMappingContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = 
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	check(Subsystem);
	Subsystem->AddMappingContext(AuraInputMappingContext, 0);

	// Mouse Setup
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}