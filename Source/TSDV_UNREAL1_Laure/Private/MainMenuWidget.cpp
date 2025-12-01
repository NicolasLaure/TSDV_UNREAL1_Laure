// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (playButton)
		playButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnPlayClicked);
	if (quitButton)
		quitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnQuitClicked);
}

void UMainMenuWidget::OnPlayClicked()
{
	onPlay.Broadcast();
}

void UMainMenuWidget::OnQuitClicked()
{
	onQuit.Broadcast();
}
