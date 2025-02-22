// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MovingWall.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CRYPTRIDER_API UMovingWall : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMovingWall();

	void SetShallItmove(bool ShallItMove);

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	FVector MovingDirection;

	UPROPERTY(EditAnywhere)
	float DistanceTime = 4;

	bool ShallItMove = false;

	FVector OriginalLocation;
};
