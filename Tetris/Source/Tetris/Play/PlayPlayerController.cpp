// Fill out your copyright notice in the Description page of Project Settings.


#include "Play/PlayPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"


void APlayPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameAndUI Mode;
	SetInputMode(Mode);
	SetShowMouseCursor(true);
}

void APlayPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	SetupInputComponentEvent();
}

void APlayPlayerController::AddMappingContext(UInputMappingContext* _MappingContext)
{
	if (nullptr == GetLocalPlayer())
	{
		return;
	}

	UEnhancedInputLocalPlayerSubsystem* InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	//UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);

	TArray<FEnhancedActionKeyMapping> Map = _MappingContext->GetMappings();

	for (FEnhancedActionKeyMapping& Action : Map)
	{
		FString Name = Action.Action->GetName();

		MappingActions.Add(Name, Action.Action);
	}

	InputSystem->ClearAllMappings();
	InputSystem->AddMappingContext(_MappingContext, 0);
}

const UInputAction* APlayPlayerController::GetInputAction(FStringView _Name)
{
	if (false == MappingActions.Contains(_Name.GetData()))
	{
		return nullptr;
	}

	return MappingActions[_Name.GetData()];
}
