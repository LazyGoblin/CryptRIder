// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "MovingWall.h"
#include "TriggerArea.generated.h"

/**
 * 
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class CRYPTRIDER_API UTriggerArea : public UBoxComponent
{
	GENERATED_BODY()
	
public:
	 // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UTriggerArea();

	UFUNCTION(BlueprintCallable)
	void SetMovingWall(UMovingWall* MovingWall);

	
protected:
	virtual void BeginPlay() override;


private:
	UPROPERTY(EditAnywhere)
	FName TriggerTag;

	UMovingWall* MovingWall;

	AActor* GetAcceptableActor() const;
};
