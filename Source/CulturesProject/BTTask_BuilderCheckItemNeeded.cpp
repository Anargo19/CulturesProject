// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_BuilderCheckItemNeeded.h"

#include "Building.h"
#include "BehaviorTree/BlackBoardComponent.h"

UBTTask_BuilderCheckItemNeeded::UBTTask_BuilderCheckItemNeeded(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Builder check Item";
}

EBTNodeResult::Type UBTTask_BuilderCheckItemNeeded::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (ABuilding* Building = Cast<ABuilding>(
		OwnerComp.GetBlackboardComponent()->GetValueAsObject(BuildingKey.SelectedKeyName)))
	{
		FName ItemName = Building->BuildingSystem->CheckRandomNeededItem();
		if (ItemName.IsNone())
			return EBTNodeResult::Failed;
		OwnerComp.GetBlackboardComponent()->SetValueAsName(ItemNameKey.SelectedKeyName, ItemName);
		
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
