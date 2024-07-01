// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FarmWork.h"

#include "Villager.h"
#include "VillagerAI.h"
#include "JobComponent.h"

UBTTask_FarmWork::UBTTask_FarmWork(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Farm Work";
}

EBTNodeResult::Type UBTTask_FarmWork::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const AVillager* Villager = Cast<AVillager>(OwnerComp.GetAIOwner()->GetPawn());
	if(Villager == nullptr)
		return EBTNodeResult::Failed;
	
	
	UJobComponent* Component = Villager->GetComponentByClass<UJobComponent>();
	if(Component == nullptr)
		return EBTNodeResult::Failed;
	Component->AddExperienceJob("Farmer", 1);
	return EBTNodeResult::Succeeded;
}