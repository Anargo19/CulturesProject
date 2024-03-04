// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_FarmWork.generated.h"

/**
 * 
 */
UCLASS()
class CULTURESPROJECT_API UBTTask_FarmWork : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	explicit UBTTask_FarmWork(FObjectInitializer const& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector Building;
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector Item;
	UPROPERTY(EditAnywhere)
	FName ItemName;
};
