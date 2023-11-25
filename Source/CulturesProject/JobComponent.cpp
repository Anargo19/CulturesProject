// Fill out your copyright notice in the Description page of Project Settings.


#include "JobComponent.h"
#include "Kismet/DataTableFunctionLibrary.h"

// Sets default values for this component's properties
UJobComponent::UJobComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UJobComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UJobComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UJobComponent::AddExperienceJob(FName JobName, int32 amount)
{
	if (Experience.Contains(JobName))
		Experience[JobName] += amount;
	else
		Experience.Add(JobName, amount);

	FTableRowBase Row;

	UDataTableFunctionLibrary::GetDataTableRowFromName(JobDatatable, JobName, Row);
	

}

