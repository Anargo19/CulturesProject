// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "VillagerAI.generated.h"

/**
 * 
 */
UCLASS()
class CULTURESPROJECT_API AVillagerAI : public AAIController
{
	GENERATED_BODY()
	
public:
	void MoveTo(FVector location);
};
