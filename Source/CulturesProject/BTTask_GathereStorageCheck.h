// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Building_FlagStorage.h"
#include "BTTask_GathereStorageCheck.generated.h"

/**
 * 
 */
UCLASS()
class CULTURESPROJECT_API UBTTask_GathereStorageCheck : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
		explicit UBTTask_GathereStorageCheck(FObjectInitializer const& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	UPROPERTY(EditAnywhere)
		FBlackboardKeySelector Building;
public :
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABuilding_FlagStorage> StorageBuilding;
};
