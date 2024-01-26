// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Build.h"

#include "Building.h"
#include "BehaviorTree/BlackBoardComponent.h"

UBTTask_Build::UBTTask_Build(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Build the building";
}

EBTNodeResult::Type UBTTask_Build::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (ABuilding* Building = Cast<ABuilding>(
		OwnerComp.GetBlackboardComponent()->GetValueAsObject(GetSelectedBlackboardKey())))
	{
		if (Building->BuildingSystem->NextConstructionStep(OwnerComp.GetBlackboardComponent()->GetValueAsName(ItemName.SelectedKeyName)))
		{
			OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), nullptr);
		}
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
