// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindItemAndPickup.h"

#include "Building.h"
#include "VillagerAI.h"
#include "BehaviorTree/BlackBoardComponent.h"

UBTTask_FindItemAndPickup::UBTTask_FindItemAndPickup(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Find an item and pick it up";
}

EBTNodeResult::Type UBTTask_FindItemAndPickup::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (AVillagerAI* AI = Cast<AVillagerAI>(OwnerComp.GetAIOwner()))
	{
		FName name;

		if(ItemName == "" || ItemName == FName("NONE"))
			name = OwnerComp.GetBlackboardComponent()->GetValueAsName(ItemNameKey.SelectedKeyName);
		else 
			name = ItemName;
		OwnerComp.GetBlackboardComponent()->SetValueAsName(ItemNameKey.SelectedKeyName, name);
		TArray<FHitResult> results;
		FCollisionQueryParams TraceParams(FName(TEXT("Item Trace")), true, AI->GetOwner());
		FVector PawnLocation = AI->GetPawn()->GetActorLocation();
		TraceParams.bDebugQuery = true;
		if (GetWorld()->SweepMultiByChannel(
			results,
			PawnLocation,
			PawnLocation,
			FQuat(),
			ECollisionChannel::ECC_WorldDynamic,
			FCollisionShape::MakeSphere(1000),
			TraceParams

		))
		{
			for (int32 i = 0; i < results.Num(); i++)
			{
				if (results[i].GetActor()->Tags.Contains(name))
				{
					OwnerComp.GetBlackboardComponent()->SetValueAsObject(
						ItemActor.SelectedKeyName, results[i].GetActor());
					/*AI->MoveToActor(results[i].GetActor());
					WaitForMessage(OwnerComp, UBrainComponent::AIMessage_MoveFinished);
					FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);*/
					return EBTNodeResult::Succeeded;
				}
				else if(ABuilding* Building = Cast<ABuilding>(results[i].GetActor()))
				{
					if(Building->BuildingInventory->GetItemCount(name) > 0)
					{
						
						OwnerComp.GetBlackboardComponent()->SetValueAsObject(
							ItemActor.SelectedKeyName, results[i].GetActor());
						return EBTNodeResult::Succeeded;
					}
				}
			}
		}

		return EBTNodeResult::Failed;
	}
	return EBTNodeResult::Failed;
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
