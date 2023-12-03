// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_PickupResource.h"
#include "VillagerAI.h"
#include <Kismet/KismetSystemLibrary.h>
#include "BehaviorTree/BlackBoardComponent.h"
#include "Resource.h"

UBTTask_PickupResource::UBTTask_PickupResource(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Pick Up Resource";
}

EBTNodeResult::Type UBTTask_PickupResource::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (AResource* Resource = Cast<AResource>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(GetSelectedBlackboardKey()))) {

		Resource->ChangeResourceAmount(-1);
		OwnerComp.GetBlackboardComponent()->SetValueAsName(item.SelectedKeyName, Resource->GetResourceItemName());
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
	return EBTNodeResult::Type();
}
