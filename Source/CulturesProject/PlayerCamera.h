// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>
#include "InputAction.h"
#include <InputMappingContext.h>
#include "PlayerCamera.generated.h"

UCLASS()
class CULTURESPROJECT_API APlayerCamera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCamera();

	/** Please add a variable description */
	UPROPERTY(VisibleAnywhere)
		UCameraComponent* Camera;

	/** Please add a variable description */
	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* SpringArm;
	/** Please add a variable description */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UInputAction* MoveF;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UInputAction* MoveR;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UInputAction* LeftC;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UInputMappingContext* InputMapping;
	UPROPERTY()
		FVector TargetLocation;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 moveSpeed;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MoveForward(const FInputActionInstance& Instance);
	void MoveRight(const FInputActionInstance& Instance);
	void LeftClick(const FInputActionInstance& Instance);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};
