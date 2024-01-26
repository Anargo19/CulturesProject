// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"

#include "Kismet/GameplayStatics.h"

void UMainMenu::NativeConstruct()
{
	if (PlayButton) {
		PlayButton->OnClicked.AddDynamic(this, &UMainMenu::PlayGame);
	}
	if (QuitButton) {
		QuitButton->OnClicked.AddDynamic(this, &UMainMenu::QuitGame);
	}
}

void UMainMenu::PlayGame()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("/Game/TopDown/Maps/TopDownMap'"), TRAVEL_Absolute);
}

void UMainMenu::QuitGame()
{
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	UKismetSystemLibrary::QuitGame(GetWorld(), PC , EQuitPreference::Quit, false);
}
