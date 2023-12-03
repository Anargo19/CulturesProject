// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/PlayerController.h"
#include "Villager.h"
#include <EnhancedInputSubsystemInterface.h>
#include "CulturesProjectPlayerController.generated.h"

/** Forward declaration to improve compiling times */
class UNiagaraSystem;
class UInputMappingContext;
class UInputAction;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS()
class ACulturesProjectPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ACulturesProjectPlayerController();

	/** Time Threshold to know if it was a short press */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	float ShortPressThreshold;

	/** FX Class that we will spawn when clicking */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UNiagaraSystem* FXCursor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* LeftC;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UInputAction* RightClick;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UInputMappingContext* InputMapping;
	UPROPERTY()
		FVector TargetLocation;
	/** Selected Villager */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Selection, meta = (AllowPrivateAccess = "true"))
		TArray<AActor*> SelectedActors;

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	virtual void SetupInputComponent() override;
	
	// To add mapping context
	virtual void BeginPlay();

	void LeftClick(const FInputActionInstance& Instance);
	void RightClickFunction(const FInputActionInstance& Instance);

private:
	FVector CachedDestination;

	bool bIsTouch; // Is it a touch device
	float FollowTime; // For how long it has been pressed
};


