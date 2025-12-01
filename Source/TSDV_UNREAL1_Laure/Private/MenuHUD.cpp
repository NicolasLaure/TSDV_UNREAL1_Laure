// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuHUD.h"

#include "MainMenu.h"
#include "Kismet/GameplayStatics.h"

AMenuHUD::AMenuHUD()
{
}

void AMenuHUD::InitHud_Implementation()
{
	MenuWidget = Cast<UMainMenuWidget>(CreateWidget(GetWorld(), MenuUIBp));
	MenuWidget->AddToViewport();

	AMainMenu* menuMode = Cast<AMainMenu>(UGameplayStatics::GetGameMode(GetWorld()));
	
	MenuWidget->onPlay.AddUObject(menuMode, &AMainMenu::Play);
	MenuWidget->onQuit.AddUObject(menuMode, &AMainMenu::Quit);
}
