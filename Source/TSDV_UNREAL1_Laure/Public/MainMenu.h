// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainMenuUI.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class TSDV_UNREAL1_LAURE_API AMainMenu : public AGameModeBase
{
	GENERATED_BODY()

private:
	UMainMenuUI* menuUI;

public:
	AMainMenu();
	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<UMainMenuUI> MenuUIBp;

	UFUNCTION(BlueprintCallable)
	void Init();

protected:
	UFUNCTION()
	void Play();
	UFUNCTION()
	void Quit();
};
