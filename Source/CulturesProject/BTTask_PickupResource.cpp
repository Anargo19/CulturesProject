// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_PickupResource.h"
#include "VillagerAI.h"
#include <Kismet/KismetSystemLibrary.h>
#include "BehaviorTree/BlackBoardComponent.h"
#include "Resource.h"
#include "Villager.h"

UBTTask_PickupResource::UBTTask_PickupResource(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Pick Up Resource";
}

EBTNodeResult::Type UBTTask_PickupResource::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AResource* Resource = Cast<AResource>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(GetSelectedBlackboardKey()));
	if (Resource) 
		return EBTNodeResult::Failed;

	AVillager* Villager = Cast<AVillager>(OwnerComp.GetAIOwner()->GetPawn());
	if(Villager == nullptr)
		return EBTNodeResult::Failed;
	
	Resource->ChangeResourceAmount(-1);
	OwnerComp.GetBlackboardComponent()->SetValueAsName(item.SelectedKeyName, Resource->GetResourceItemName());
	Villager->GetComponentByClass<UJobComponent>()->AddExperienceJob(Villager->Tags[0], 1);
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}