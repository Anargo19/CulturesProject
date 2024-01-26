// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindConstructionSite.h"

#include "Building.h"
#include "Villager.h"
#include "VillagerAI.h"
#include "BehaviorTree/BlackBoardComponent.h"

UBTTask_FindConstructionSite::UBTTask_FindConstructionSite(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Find a new construction site";
}

EBTNodeResult::Type UBTTask_FindConstructionSite::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ABuilding* Building;
	if (AVillagerAI* AI = Cast<AVillagerAI>(OwnerComp.GetAIOwner())) {
		
		TArray<FHitResult> results;
		FCollisionQueryParams TraceParams(FName(TEXT("VictoreCore Trace")), true);
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

	)) {
		for (int32 i = 0; i < results.Num(); i++)
		{
				
			if (results[i].GetActor()->ActorHasTag(AI->GetPawn()->Tags[0])) {
				if (Cast<AVillager>(results[i].GetActor()))
					continue;
				if(ABuilding* CastBuilding = Cast<ABuilding>(results[i].GetActor()))
				{
					Building = CastBuilding;
					OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), Building);
					FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
					return EBTNodeResult::Succeeded;
				}
			}

		}

		}


		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}