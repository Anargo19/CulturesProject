// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_CheckandGetResources.h"
#include "VillagerAI.h"
#include "Villager.h"
#include <Kismet/KismetSystemLibrary.h>
#include "BehaviorTree/BlackBoardComponent.h"
#include "Villager.h"

UBTTask_CheckandGetResources::UBTTask_CheckandGetResources(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Check and Get Resources";
}

EBTNodeResult::Type UBTTask_CheckandGetResources::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AActor* Resource = nullptr;
	TArray<AActor*> Resources = {};

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
			FCollisionShape::MakeSphere(500),
			TraceParams

		)) {
			for (int32 i = 0; i < results.Num(); i++)
			{
				
				if (results[i].GetActor()->ActorHasTag(AI->GetPawn()->Tags[0])) {
					if (Cast<AVillager>(results[i].GetActor()))
						continue;
					Resources.Add(results[i].GetActor());
				}

			}
			for (int32 i = 0; i < Resources.Num(); i++)
			{
				if (Resource == nullptr) {
					Resource = Resources[i];
					continue;
				}
				if (FVector::Dist(Resources[i]->GetActorLocation(), PawnLocation) < FVector::Dist(Resource->GetActorLocation(), PawnLocation)) {
					Resource = Resources[i];
				}

			}

			OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), Resource);

			FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
			return EBTNodeResult::Succeeded;
		}

		return EBTNodeResult::Failed;
	}
	return EBTNodeResult::Type();
}
