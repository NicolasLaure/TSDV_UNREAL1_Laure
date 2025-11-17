// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "MainMenuUI.generated.h"

/**
 * 
 */
UCLASS()
class TSDV_UNREAL1_LAURE_API UMainMenuUI : public UUserWidget
{
	GENERATED_BODY()

	UFUNCTION()
	void OnPlayClicked();
	UFUNCTION()
	void OnQuitClicked();

public:
	virtual void NativeConstruct() override;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton* playButton;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton* quitButton;

	DECLARE_MULTICAST_DELEGATE(OnPlayPressed);
	OnPlayPressed onPlay;
	DECLARE_MULTICAST_DELEGATE(OnQuitPressed);
	OnQuitPressed onQuit;
};
