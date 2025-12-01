// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainMenuWidget.h"
#include "MenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class TSDV_UNREAL1_LAURE_API AMenuHUD : public AHUD
{
	GENERATED_BODY()

private:

public:
	UMainMenuWidget* MenuWidget;

	AMenuHUD();

	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<UMainMenuWidget> MenuUIBp;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void InitHud();

	void InitHud_Implementation();
};
