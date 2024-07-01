// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Deposit.h"
#include "GameFramework/Actor.h"
#include "Building.h"
#include "BehaviorTree/BlackBoardComponent.h"

UBTTask_Deposit::UBTTask_Deposit(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Deposit";
}

EBTNodeResult::Type UBTTask_Deposit::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AActor* Actor = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(Building.SelectedKeyName));
	if (Actor == nullptr)
		return EBTNodeResult::Failed;
	UBuildingInventory* TargetBuilding = Actor->FindComponentByClass<UBuildingInventory>();
	if (TargetBuilding == nullptr)
		return EBTNodeResult::Failed;
	
	FName name;

	if(ItemName == "" || ItemName == FName("NONE"))
		name = OwnerComp.GetBlackboardComponent()->GetValueAsName(Item.SelectedKeyName);
	else 
		name = ItemName;
	TargetBuilding->ChangeAmountItem(name,
									 1);
	OwnerComp.GetBlackboardComponent()->SetValueAsName(Item.SelectedKeyName, FName("NONE")),
	GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("DEPOSIT RESOURCE")));
	return EBTNodeResult::Succeeded;
}
