// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"

#include "UObject/ConstructorHelpers.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

AMainMenu::AMainMenu()
{
}

void AMainMenu::Init()
{
	menuUI = Cast<UMainMenuUI>(CreateWidget(GetWorld(), MenuUIBp));
	menuUI->AddToViewport();

	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
	menuUI->onPlay.AddUObject(this, &AMainMenu::Play);
	menuUI->onQuit.AddUObject(this, &AMainMenu::Quit);
}

void AMainMenu::Play()
{
	FName levelName = FName(TEXT("Race"));
	UGameplayStatics::OpenLevel(GetWorld(), levelName, true);
}

void AMainMenu::Quit()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);
}
