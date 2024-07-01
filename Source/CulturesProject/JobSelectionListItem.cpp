// Fill out your copyright notice in the Description page of Project Settings.


#include "JobSelectionListItem.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "CulturesProjectPlayerController.h"
#include "VillagerHUD.h"

void UJobSelectionListItem::NativeConstruct()
{
	if (JobButton) {
		JobButton->OnClicked.AddDynamic(this, &UJobSelectionListItem::ButtonClicked);
	}
}

void UJobSelectionListItem::ButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Clicked Button of %s"), *JobText->GetText().ToString());
	ACulturesProjectPlayerController* PC = Cast<ACulturesProjectPlayerController>(GetOwningPlayer());
	if (PC->SelectedActors.Num() > 0)
	{
		AVillager* Villager = Cast<AVillager>(PC->SelectedActors[0]);
		if(Villager == nullptr)
			return;
		UJobComponent* JobComponent = Villager->GetComponentByClass<UJobComponent>();

		if(JobComponent==nullptr)
			return;
		JobComponent->SetJob(FName(*JobText->GetText().ToString()));

		AVillagerHUD* HUD = PC->GetHUD<AVillagerHUD>();
		HUD->HideJobList();
	}
}
