// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_AddJobExperience.h"

#include "Villager.h"
#include "VillagerAI.h"

UBTTask_AddJobExperience::UBTTask_AddJobExperience(FObjectInitializer const& ObjectInitializer)
{
	ExperienceToAdd = 0;
	NodeName = "Add Job Experience";
}

EBTNodeResult::Type UBTTask_AddJobExperience::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if(JobName == FName("NONE"))
		return EBTNodeResult::Failed;
	const AVillagerAI* AI = Cast<AVillagerAI>(OwnerComp.GetAIOwner());
	if (AI == nullptr)
		return EBTNodeResult::Failed;
	const AVillager* Villager = Cast<AVillager>(AI->GetPawn());
	if (Villager == nullptr)			
		return EBTNodeResult::Failed;
		
	UJobComponent* Component = Villager->GetComponentByClass<UJobComponent>();
	if(Component == nullptr)
		return EBTNodeResult::Failed;
	Component->AddExperienceJob(JobName, ExperienceToAdd);
	return EBTNodeResult::Succeeded;
}
	
	

