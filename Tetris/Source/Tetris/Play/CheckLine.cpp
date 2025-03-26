// Fill out your copyright notice in the Description page of Project Settings.


#include "Play/CheckLine.h"
#include "Components/BoxComponent.h"
#include "Global/TetrisGameInstance.h"


// Sets default values
ACheckLine::ACheckLine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetupAttachment(RootComponent);

	BoxComponent->SetWorldScale3D(FVector(0.1f, 7.5f, 0.1f));
	BoxComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
}

// Called when the game starts or when spawned
void ACheckLine::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void ACheckLine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

