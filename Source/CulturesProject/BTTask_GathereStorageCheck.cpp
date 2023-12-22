// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GathereStorageCheck.h"
#include "BehaviorTree/BlackBoardComponent.h"
#include "Building_FlagStorage.h"
#include "VillagerAI.h"

UBTTask_GathereStorageCheck::UBTTask_GathereStorageCheck(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Check for storage";
}

EBTNodeResult::Type UBTTask_GathereStorageCheck::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

		if (AVillagerAI* AI = Cast<AVillagerAI>(OwnerComp.GetAIOwner())) {
			ABuilding_FlagStorage* Storage = GetWorld()->SpawnActor<ABuilding_FlagStorage>(StorageBuilding, AI->GetPawn()->GetActorLocation(), FRotator(0.0f, 0.f, 0.f), FActorSpawnParameters());
			Storage->BuildingInventory->Inventory.Add(TEXT("Stone"), 0);
			OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), Storage);
			FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
			return EBTNodeResult::Succeeded;
		}
	
	return EBTNodeResult::Failed;
	return EBTNodeResult::Type();
}
