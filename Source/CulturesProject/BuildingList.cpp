// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingList.h"

#include "BuildingSelectionListItem.h"
#include "JobSelectionListItem.h"
#include "Components/TextBlock.h"

void UBuildingList::SetBuildingList(TArray<FName> BuildingNames)
{
	for (size_t i = 0; i < BuildingNames.Num(); i++)
{
	APlayerController* PC = Cast<APlayerController>(GetOwningPlayer());
	UE_LOG(LogTemp, Warning, TEXT("Owner : %s"), *PC->GetName());
	//UJobSelectionListItem* Job = NewObject<UJobSelectionListItem>();
	UBuildingSelectionListItem* Building = CreateWidget<UBuildingSelectionListItem>(PC, BuildingButton);
	UE_LOG(LogTemp, Warning, TEXT("Job Widget %s"), *Building->GetName());
	//UE_LOG(LogTemp, Warning, TEXT("Job Text %s"), *Job->JobText->GetName());
	Building->BuildingText->SetText(FText::FromName(BuildingNames[i]));
	UE_LOG(LogTemp, Warning, TEXT("TEXT SET"));
	BuildingList->AddChild(Building);
}
}

