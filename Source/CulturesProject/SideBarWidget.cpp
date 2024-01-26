// Fill out your copyright notice in the Description page of Project Settings.


#include "SideBarWidget.h"

#include "CulturesProjectPlayerController.h"
#include "VillagerHUD.h"
#include "Components/Button.h"

void USideBarWidget::NativeConstruct() {
	if (BuildingButton) {
		BuildingButton->OnClicked.AddDynamic(this, &USideBarWidget::BuildingButtonClicked);
	}
}
void USideBarWidget::BuildingButtonClicked() {

	ACulturesProjectPlayerController* PC = Cast<ACulturesProjectPlayerController>(GetWorld()->GetFirstPlayerController());
	UE_LOG(LogTemp, Warning, TEXT("Selected Controller %s"), *PC->GetName());
	AVillagerHUD* HUD = PC->GetHUD<AVillagerHUD>();
	UE_LOG(LogTemp, Warning, TEXT("Get HUD %s"), *HUD->GetName());
	HUD->ShowBuildingList(PC->PossibleBuildings);
	UE_LOG(LogTemp, Warning, TEXT("Clicked on Building Button"));
}