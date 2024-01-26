// Fill out your copyright notice in the Description page of Project Settings.


#include "VillagerHUD.h"
#include <Blueprint/UserWidget.h>
#include <GameFramework/PlayerController.h>
#include <Kismet/GameplayStatics.h>

#include "BuildingList.h"
#include "VillagerWidget.h"
#include "JobList.h"

void AVillagerHUD::ShowVillagerMenu(FName VillagerName, int32 Health, int32 Hunger, int32 Sleep, AVillager* Villager)
{
	// Make widget owned by our PlayerController
	APlayerController* PC = Cast<APlayerController>(GetOwner());
	VillagerMenuInstance = CreateWidget<UUserWidget>(PC, VillagerPanel);
	if (UVillagerWidget* Widget = Cast<UVillagerWidget>(VillagerMenuInstance)) {

		UE_LOG(LogTemp, Warning, TEXT("Get Widget %s"), *Widget->GetName());
		Widget->SetValues(VillagerName, Health, Hunger, Sleep);
		Widget->SetVillager(Villager);
		VillagerMenuInstance->AddToViewport();
	}
}

void AVillagerHUD::ShowMainMenu()
{
	APlayerController* PC = Cast<APlayerController>(GetOwner());
	MainMenuInstance = CreateWidget<UUserWidget>(PC, MainMenu);
	MainMenuInstance->AddToViewport();
}

void AVillagerHUD::ShowSidebar()
{
	APlayerController* PC = Cast<APlayerController>(GetOwner());
	SidebarInstance = CreateWidget<UUserWidget>(PC, Sidebar);
	SidebarInstance->AddToViewport();
	
}

void AVillagerHUD::ShowJobList(TArray<FName> Jobs)
{
	APlayerController* PC = Cast<APlayerController>(GetOwner());
	JobListInstance = CreateWidget<UJobList>(PC, JobList);
	if (UJobList* Widget = Cast<UJobList>(JobListInstance)) {
		Widget->SetJobList(Jobs);
	}
	JobListInstance->AddToViewport();

}

void AVillagerHUD::HideJobList()
{
	if (JobListInstance)
	{
		JobListInstance->RemoveFromParent();
		JobListInstance = nullptr;
	}
}
void AVillagerHUD::ShowBuildingList(TArray<FName> Buildings)
{
	APlayerController* PC = Cast<APlayerController>(GetOwner());
	BuildingListInstance = CreateWidget<UBuildingList>(PC, BuildingList);
	if (UBuildingList* Widget = Cast<UBuildingList>(BuildingListInstance)) {
		Widget->SetBuildingList(Buildings);
	}
	BuildingListInstance->AddToViewport();

}

void AVillagerHUD::HideBuildingList()
{
	if (BuildingListInstance)
	{
		BuildingListInstance->RemoveFromParent();
		BuildingListInstance = nullptr;
	}
}

void AVillagerHUD::HideMainMenu()
{
	if (MainMenuInstance)
	{
		MainMenuInstance->RemoveFromParent();
		MainMenuInstance = nullptr;
	}
}

void AVillagerHUD::HideVillagerMenu()
{
	if (VillagerMenuInstance)
	{
		VillagerMenuInstance->RemoveFromParent();
		VillagerMenuInstance = nullptr;
	}
}

void AVillagerHUD::UpdateValues(FName VillagerName, int32 Health, int32 Hunger, int32 Sleep)
{
	if (VillagerMenuInstance == nullptr)
		return;
	if (UVillagerWidget* Widget = Cast<UVillagerWidget>(VillagerMenuInstance)) {
		Widget->SetValues(VillagerName, Health, Hunger, Sleep);
	}
}

void AVillagerHUD::SetJob(FName Job)
{
	if (VillagerMenuInstance == nullptr)
		return;
	if (UVillagerWidget* Widget = Cast<UVillagerWidget>(VillagerMenuInstance)) {
		Widget->SetJob(Job);
	}
}
