// Fill out your copyright notice in the Description page of Project Settings.


#include "JobComponent.h"
#include "Kismet/DataTableFunctionLibrary.h"
#include "FS_Job.h"
#include "Villager.h"
#include "VillagerAI.h"

// Sets default values for this component's properties
UJobComponent::UJobComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UJobComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UJobComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UJobComponent::AddExperienceJob(FName JobName, int32 amount)
{
	if (Experience.Contains(JobName))
		Experience[JobName] += amount;
	else
		Experience.Add(JobName, amount);


	FS_Job* JobRow = JobDatatable->FindRow<FS_Job>(JobName, "");
	GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("Found %s"), *JobRow->JobBuilding.ToString()));

	for (auto& Job : JobRow->JobEvolution)
	{
		if (Experience[JobName] >= Job.Value) {
			GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("ENOUGH XP TO UNLOCK %s"), *Job.Key.ToString()));
		}
	}

	
	
	

}

void UJobComponent::SetJob(FName JobName)
{
	GetOwner()->Tags.Empty();
	GetOwner()->Tags.Add(JobName);
	CurrentJob = JobName;
	if (AVillager* Villager = Cast<AVillager>(GetOwner())) {
		if (AVillagerAI* ai = Cast<AVillagerAI>(Villager->GetController())) {
			ai->RunBehaviorTree(JobDatatable->FindRow<FS_Job>(JobName, "")->BehaviorTree);
		}
	}
}

