// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_PickupItem.generated.h"

/**
 * 
 */
UCLASS()
class CULTURESPROJECT_API UBTTask_PickupItem : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	explicit UBTTask_PickupItem(FObjectInitializer const& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
public:
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector ItemKey;
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector ItemNameKey;
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector BuildingKey;
};
