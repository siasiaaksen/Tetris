// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SideBar.generated.h"

UCLASS()
class TETRIS_API ASideBar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASideBar();

	UFUNCTION(BlueprintCallable)
	int Calculate(int _Value, bool _IsMinus)
	{
		int Result = (_Value * 0.5f * 50) + 50;

		if (true == _IsMinus)
		{
			Result = Result * -1.0f;
		}

		return Result;
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
