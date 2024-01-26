// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingSelectionListItem.h"
#include "CulturesProjectPlayerController.h"
#include "FS_Building.h"
#include "VillagerHUD.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void UBuildingSelectionListItem::NativeConstruct()
{
	if (BuildingButton) {
		BuildingButton->OnClicked.AddDynamic(this, &UBuildingSelectionListItem::ButtonClicked);
	}
}

void UBuildingSelectionListItem::ButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Clicked Button of %s"), *BuildingText->GetText().ToString());
	//ACulturesProjectPlayerController* PC = Cast<ACulturesProjectPlayerController>(GetOwningPlayer());
	
	if(TSubclassOf<ABuilding> Building = BuildingDatatable->FindRow<FS_Building>(FName(*BuildingText->GetText().ToString()), "")->Building)
		GetWorld()->SpawnActor(Building);
	
	ACulturesProjectPlayerController* PC = Cast<ACulturesProjectPlayerController>(GetOwningPlayer());
	AVillagerHUD* HUD = PC->GetHUD<AVillagerHUD>();
	HUD->HideBuildingList();
}