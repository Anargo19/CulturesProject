// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FS_Item.generated.h"

/**
 * 
 */
USTRUCT(Blueprintable)
struct CULTURESPROJECT_API FS_Item : public FTableRowBase
{
	GENERATED_BODY();
public:
	FS_Item() {}
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Item Name", MakeStructureDefaultValue = "None"))
		FText ItemName;
	/** Please add a variable description */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Item Description", MakeStructureDefaultValue = "None"))
		FText ItemDescription;


};
