// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Building.h"
#include <Components/BoxComponent.h>
#include "Building_Headquarter.generated.h"

/**
 * 
 */
UCLASS()
class CULTURESPROJECT_API ABuilding_Headquarter : public ABuilding
{
	GENERATED_BODY()


public:
	// Sets default values for this actor's properties
	ABuilding_Headquarter();
	/** Please add a variable description */
	//UPROPERTY(VisibleAnywhere)
		//UBoxComponent* Collider;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	virtual void Interact() override;
	virtual void Deselect() override;
	
};
