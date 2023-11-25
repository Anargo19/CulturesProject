// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "JobComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CULTURESPROJECT_API UJobComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UJobComponent();
	UPROPERTY(EditAnywhere)
	TArray<FName> PossibleJobs;
	UPROPERTY(EditAnywhere)
	TMap<FName, int32> Experience;
	UPROPERTY(EditAnywhere)
	UDataTable* JobDatatable;
	
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void AddExperienceJob(FName JobName, int32 amount);

		
};
