// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Deposit.h"
#include "Building.h"
#include "BehaviorTree/BlackBoardComponent.h"

UBTTask_Deposit::UBTTask_Deposit(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Deposit";
}

EBTNodeResult::Type UBTTask_Deposit::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (ABuilding* TargetBuilding = Cast<ABuilding>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(Building.SelectedKeyName))) {
		GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("DEPOSIT RESOURCE")));
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
