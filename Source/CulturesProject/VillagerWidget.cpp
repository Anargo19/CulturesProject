// Fill out your copyright notice in the Description page of Project Settings.


#include "VillagerWidget.h"
#include "Components/ProgressBar.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/EditableText.h"
#include "Villager.h"
#include "VillagerHUD.h"

void UVillagerWidget::SetVillager(AVillager* Villager)
{
	CurrentVillager = Villager;
	SetJob("None");
}

void UVillagerWidget::SetValues(FName VillagerName, int32 Health, int32 Hunger, int32 Sleep)
{
	UE_LOG(LogTemp, Warning, TEXT("Update Health to  %d with %f"), Health, (float)Health / (float)100);
	HealthBar->SetPercent( (float)Health / (float)100);

	HungerBar->SetPercent((float)Hunger / (float)100);

	SleepBar->SetPercent((float)Sleep / (float)100);

	VillagerNameText->SetText(FText::FromName(VillagerName));

}

void UVillagerWidget::SetJob(FName Job)
{
	if(Job != FName("None"))
	{
	JobText->SetText(FText::FromName(Job));
		return;
	}
	UJobComponent* JobComponent = CurrentVillager->GetComponentByClass<UJobComponent>();

	UE_LOG(LogTemp, Warning, TEXT("Job COmponent %s"), *JobComponent->GetFName().ToString());
	
	JobText->SetText(FText::FromName(JobComponent->GetJob()));
}

void UVillagerWidget::NativeConstruct()
{
	if (JobButton) {
		JobButton->OnClicked.AddDynamic(this, &UVillagerWidget::JobButtonClicked);
	}
}

void UVillagerWidget::JobButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Clicked the job Button"));
	TArray<FName> PossibleJobs = CurrentVillager->GetComponentByClass<UJobComponent>()->PossibleJobs;

	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	AVillagerHUD* HUD = PC->GetHUD<AVillagerHUD>();
	HUD->ShowJobList(PossibleJobs);
	

}
