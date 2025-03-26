// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TetrisGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_API UTetrisGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	static void SetXValue(int _X)
	{
		XValue = _X;
	}

	UFUNCTION(BlueprintCallable)
	static void SetYValue(int _Y)
	{
		YValue = _Y;
	}

	UFUNCTION(BlueprintCallable)
	static int GetXValue()
	{
		return XValue;
	}

	UFUNCTION(BlueprintCallable)
	static int GetYValue()
	{
		return YValue;
	}

private:
	static int XValue;

	static int YValue;
};
