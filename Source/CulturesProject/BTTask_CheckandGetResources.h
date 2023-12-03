// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_CheckandGetResources.generated.h"

/**
 * 
 */
UCLASS()
class CULTURESPROJECT_API UBTTask_CheckandGetResources : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	explicit UBTTask_CheckandGetResources(FObjectInitializer const& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
