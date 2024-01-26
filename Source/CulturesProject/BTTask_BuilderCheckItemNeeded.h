// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_BuilderCheckItemNeeded.generated.h"

/**
 * 
 */
UCLASS()
class CULTURESPROJECT_API UBTTask_BuilderCheckItemNeeded : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	explicit UBTTask_BuilderCheckItemNeeded(FObjectInitializer const& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector ItemNameKey;
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector BuildingKey;
};
