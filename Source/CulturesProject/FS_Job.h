// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <BehaviorTree/BehaviorTree.h>
#include "FS_Job.generated.h"

/**
 * 
 */
USTRUCT(Blueprintable)
struct CULTURESPROJECT_API FS_Job : public FTableRowBase
{
	GENERATED_BODY()
public:

	FS_Job() {}
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Tool", MakeStructureDefaultValue = "None"))
		UStaticMesh* Tool;


	/** List of jobs unlockable with an experience amount */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "JobEvolution", MakeStructureDefaultValue = "()"))
		TMap<FName, int32> JobEvolution;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "JobBuilding", MakeStructureDefaultValue = "None"))
		FName JobBuilding;

	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "BehaviorTree"))
		UBehaviorTree* BehaviorTree;

};
