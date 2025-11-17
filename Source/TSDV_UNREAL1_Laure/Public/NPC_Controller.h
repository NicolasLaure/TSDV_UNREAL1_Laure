// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "WheeledVehiclePawn.h"
#include "Components/SplineComponent.h"
#include "ChaosWheeledVehicleMovementComponent.h"
#include "NPC_Controller.generated.h"

/**
 * 
 */

UCLASS(Blueprintable)
class TSDV_UNREAL1_LAURE_API ANPC_Controller : public AAIController
{
	GENERATED_BODY()
	USplineComponent* track;
	AWheeledVehiclePawn* car;

public:
	UPROPERTY(BlueprintReadWrite)
	float steeringForce = 0.7f;
	
	UPROPERTY(BlueprintReadWrite)
	float carWidth = 1.0f;
	UPROPERTY(BlueprintReadWrite)
	float minDistance = 1.0f;
	
	UPROPERTY(BlueprintReadWrite)
	float accelThreshold = 0.85f;

	UFUNCTION(BlueprintCallable)
	void Init(USplineComponent* trackRef);

	UFUNCTION(BlueprintCallable)
	void TickAI(float& accel, float& brake, float& steering);

	explicit ANPC_Controller(FObjectInitializer const& ObjectInitializer);
};
