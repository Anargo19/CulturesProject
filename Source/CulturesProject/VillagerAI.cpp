// Fill out your copyright notice in the Description page of Project Settings.


#include "VillagerAI.h"

#include "BrainComponent.h"
#include "SNegativeActionButton.h"
#include "Navigation/PathFollowingComponent.h"

void AVillagerAI::MoveTo(const FVector& location, bool HumanAction)
{
	if (HumanAction && BrainComponent != nullptr)
	{
		
		BrainComponent->StopLogic(TEXT("Moving"));
		isOrdered = true;
	}
	MoveToLocation(location);
}

void AVillagerAI::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	UE_LOG(LogTemp, Warning, TEXT("STOPPED MOVING %s"),
	       BrainComponent->IsPaused()? TEXT("Paused") : TEXT("Not Paused"));
	Super::OnMoveCompleted(RequestID, Result);
	if (isOrdered && BrainComponent != nullptr)
	{
		BrainComponent->RestartLogic();
		isOrdered = false;
	}
}
