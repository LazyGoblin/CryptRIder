// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingWall.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMovingWall::UMovingWall()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMovingWall::BeginPlay()
{
	Super::BeginPlay();

	OriginalLocation = GetOwner() -> GetActorLocation();
}


// Called every frame
void UMovingWall::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(ShallItMove)
	{
	FVector CurrentLocation = GetOwner() -> GetActorLocation();
	FVector TargetLocation = OriginalLocation + MovingDirection;
	float Speed = FVector::Distance(OriginalLocation, TargetLocation) / DistanceTime;

	FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);
	GetOwner() -> SetActorLocation(NewLocation);
	}
}

void UMovingWall::SetShallItmove(bool NewShallItMove)
{
	ShallItMove = NewShallItMove;
}