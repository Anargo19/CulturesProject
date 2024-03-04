// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindRandomLocation.h"
#include "VillagerAI.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackBoardComponent.h"

UBTTask_FindRandomLocation::UBTTask_FindRandomLocation(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Find Random Location";
}

EBTNodeResult::Type UBTTask_FindRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (AVillagerAI* AI = Cast<AVillagerAI>(OwnerComp.GetAIOwner())) {
		FVector PawnLocation = AI->GetPawn()->GetActorLocation();
		UNavigationSystemV1* Nav = UNavigationSystemV1::GetCurrent(GetWorld());
		FNavLocation Destination;
		if (Nav->GetRandomPointInNavigableRadius(PawnLocation, 200, Destination)) {
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Destination.Location);
		}

		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
