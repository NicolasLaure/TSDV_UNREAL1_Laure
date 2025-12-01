// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MenuHUD.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class TSDV_UNREAL1_LAURE_API AMainMenu : public AGameModeBase
{
	GENERATED_BODY()

	AMenuHUD* menuHUD;

public:
	AMainMenu();

	UFUNCTION(BlueprintCallable)
	void Init();

	UFUNCTION()
	void Play();
	UFUNCTION()
	void Quit();
};
