// Fill out your copyright notice in the Description page of Project Settings.


#include "JobList.h"
#include "JobSelectionListItem.h"
#include "Components/TextBlock.h"
#include <Components/ScrollBox.h>
#include <Components/Button.h>

void UJobList::SetJobList(TArray<FName> JobNames)
{
	for (size_t i = 0; i < JobNames.Num(); i++)
	{
		APlayerController* PC = Cast<APlayerController>(GetOwningPlayer());
		UE_LOG(LogTemp, Warning, TEXT("Owner : %s"), *PC->GetName());
		//UJobSelectionListItem* Job = NewObject<UJobSelectionListItem>();
		UJobSelectionListItem* Job = CreateWidget<UJobSelectionListItem>(PC, JobButton);
		UE_LOG(LogTemp, Warning, TEXT("Job Widget %s"), *Job->GetName());
		//UE_LOG(LogTemp, Warning, TEXT("Job Text %s"), *Job->JobText->GetName());
		Job->JobText->SetText(FText::FromName(JobNames[i]));
		UE_LOG(LogTemp, Warning, TEXT("TEXT SET"));
		JobList->AddChild(Job);
	}
}

void UJobList::JobButtonClicked()
{
	
}
