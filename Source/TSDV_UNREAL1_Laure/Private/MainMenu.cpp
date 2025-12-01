// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"

#include "MenuHUD.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

AMainMenu::AMainMenu()
{
}

void AMainMenu::Init()
{
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
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
