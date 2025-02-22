// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CRYPTRIDER_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void Press();

	UFUNCTION(BlueprintCallable)
	void Release();

	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(EditAnywhere)
	float MaxRange = 400;

	UPROPERTY(EditAnywhere)
	float GrabbingRadius = 100;

	UPROPERTY(EditAnywhere)
	float GrabbingDistance = 200;

	UPhysicsHandleComponent *GetPhysicsHandle() const;
	
	bool GetGrabbleInReach(FHitResult &OutHitResult) const;
};
