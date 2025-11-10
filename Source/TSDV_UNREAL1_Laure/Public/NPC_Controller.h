// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NPC_Controller.generated.h"

/**
 * 
 */
UCLASS()
class TSDV_UNREAL1_LAURE_API ANPC_Controller : public AAIController
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	explicit ANPC_Controller(FObjectInitializer const& ObjectInitializer);
};
