// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Building.h"
#include "BehaviorTree/BehaviorTree.h"
#include "FS_Building.generated.h"

/**
 * 
 */
USTRUCT(Blueprintable)
struct CULTURESPROJECT_API FS_Building: public FTableRowBase
{
	GENERATED_BODY();
public:
 
 FS_Building() {}


 /** List of jobs unlockable with an experience amount */
 UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Building", MakeStructureDefaultValue = "()"))
 TSubclassOf<ABuilding> Building;


};
