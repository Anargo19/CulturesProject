// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BuildingInventory.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CULTURESPROJECT_API UBuildingInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBuildingInventory();
	UPROPERTY(EditAnywhere)
		TMap<FName, int16> Inventory;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(Blueprintable)
	int16 GetItemCount(FName Name);
	UFUNCTION(Blueprintable)
		void ChangeAmountItem(FName Name, int16 amount);
	UFUNCTION(Blueprintable)
	TMap<FName, int16> GetInventory();

		
};
