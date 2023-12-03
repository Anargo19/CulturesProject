// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_PickupResource.generated.h"

/**
 * 
 */
UCLASS()
class CULTURESPROJECT_API UBTTask_PickupResource : public UBTTask_BlackboardBase
{
	GENERATED_BODY()


public:
	explicit UBTTask_PickupResource(FObjectInitializer const& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	UPROPERTY(EditAnywhere)
		FBlackboardKeySelector item;
};
