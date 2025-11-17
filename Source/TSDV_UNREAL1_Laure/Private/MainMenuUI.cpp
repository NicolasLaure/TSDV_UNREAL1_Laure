// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuUI.h"

void UMainMenuUI::NativeConstruct()
{
	Super::NativeConstruct();
	if (playButton)
		playButton->OnClicked.AddDynamic(this, &UMainMenuUI::OnPlayClicked);
	if (quitButton)
		quitButton->OnClicked.AddDynamic(this, &UMainMenuUI::OnQuitClicked);
}

void UMainMenuUI::OnPlayClicked()
{
	onPlay.Broadcast();
}

void UMainMenuUI::OnQuitClicked()
{
	onQuit.Broadcast();
}
