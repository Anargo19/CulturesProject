// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BuildingSystem.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CULTURESPROJECT_API UBuildingSystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBuildingSystem();
	bool IsBuildingPlaced();
	void Place();
	//Changes static mesh to next step construction
	bool NextConstructionStep(FName Item);
	//Changes static mesh to final and end construction
	void EndConstruction();
	//Get a random item needed for construction
	FName CheckRandomNeededItem();
	//Get all items needed for contruction
	TArray<FName> GetAllNeededItem();

protected:
	UFUNCTION()
	void OnCollisionEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	bool isPlaced;
	UPROPERTY(EditAnywhere)
	bool CanPlace;
	UPROPERTY(EditAnywhere, Category = Construction)
	int32 CurrentConstructionStep;
	UPROPERTY(EditAnywhere, Category = Material)
	UMaterialInstance* BuildingValid;
	UPROPERTY(EditAnywhere, Category = Material)
	UMaterialInstance* BuildingInvalid;
	UPROPERTY(EditAnywhere, Category = Material)
	UMaterialInstance* BuildingMaterial;
	UPROPERTY(EditAnywhere, Category = Construction)
	TArray<UStaticMesh*> ConstructionSteps;
	UPROPERTY(EditAnywhere, Category = Construction)
	UStaticMesh* Finished;
	UPROPERTY(EditAnywhere)
	TArray<FName> CurrentNeededResources;
	UPROPERTY(EditAnywhere)
	TArray<FName> NeededResources;
	UFUNCTION(BlueprintCallable)
	void OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
