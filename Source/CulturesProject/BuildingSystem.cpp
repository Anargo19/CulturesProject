// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingSystem.h"

// Sets default values for this component's properties
UBuildingSystem::UBuildingSystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	isPlaced = false;

	// ...
}


// Called when the game starts
void UBuildingSystem::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBuildingSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!isPlaced) {
		FVector MousePosition;
		FVector nice;
		GetWorld()->GetFirstPlayerController()->DeprojectMousePositionToWorld(MousePosition, nice);
		//GetOwner()->SetActorLocation(FVector(MousePosition.X, MousePosition.Y, GetOwner() -> GetActorLocation().Z));
	}
	if (isPlaced)
		DestroyComponent();

	// ...
}

