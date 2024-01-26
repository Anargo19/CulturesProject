// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_Build.generated.h"

/**
 * 
 */
UCLASS()
class CULTURESPROJECT_API UBTTask_Build : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	explicit UBTTask_Build(FObjectInitializer const& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector ItemName;
};
