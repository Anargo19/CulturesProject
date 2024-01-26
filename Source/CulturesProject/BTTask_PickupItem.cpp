// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_PickupItem.h"
#include "BehaviorTree/BlackBoardComponent.h"

#include "Building.h"

UBTTask_PickupItem::UBTTask_PickupItem(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Pick up Item";
}


EBTNodeResult::Type UBTTask_PickupItem::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (ABuilding* Building = Cast<ABuilding>(
		OwnerComp.GetBlackboardComponent()->GetValueAsObject(BuildingKey.SelectedKeyName)))
	{
		if(Building->BuildingInventory->GetItemCount(OwnerComp.GetBlackboardComponent()->GetValueAsName(ItemNameKey.SelectedKeyName)) > 0)
		{
			
			Building->BuildingInventory->ChangeAmountItem(OwnerComp.GetBlackboardComponent()->GetValueAsName(ItemNameKey.SelectedKeyName), -1);
			return EBTNodeResult::Succeeded;
		}
	}
	else
	{
		if(AActor* Item = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(ItemKey.SelectedKeyName)))
		{
			Item->Destroy();
		return EBTNodeResult::Succeeded;
		}
	}
		return EBTNodeResult::Failed;
}
