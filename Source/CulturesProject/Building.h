// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "Components/DecalComponent.h"
#include "BuildingInventory.h"
#include "BuildingSystem.h"
#include <Components/BoxComponent.h>
#include "Building.generated.h"

UCLASS()
class CULTURESPROJECT_API ABuilding : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilding();
	/** Please add a variable description */
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneComponent* Entry;
	UPROPERTY(EditAnywhere)
		UDecalComponent* Decal;
	UPROPERTY(EditAnywhere)
		UBuildingInventory* BuildingInventory;
	UPROPERTY(EditAnywhere)
		UBuildingSystem* BuildingSystem;
	UPROPERTY(EditAnywhere)
		int16 Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<USceneComponent*> BuildingEntries;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(Blueprintable, BlueprintCallable)
		virtual void Interact() override;
	UFUNCTION(Blueprintable, BlueprintCallable)
	virtual void Deselect() override;
	UFUNCTION(BlueprintCallable, BlueprintCallable)
	FVector FindMainEntry();
	UFUNCTION(BlueprintCallable, BlueprintCallable)
	FVector FindEntry(int32 entryID);

};
