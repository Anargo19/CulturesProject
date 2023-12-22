// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingInventory.h"

// Sets default values for this component's properties
UBuildingInventory::UBuildingInventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UBuildingInventory::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBuildingInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int16 UBuildingInventory::GetItemCount(FName Name)
{

	if (Inventory.Contains(Name)) {
		return Inventory[Name];
	}
	return int16();
}

void UBuildingInventory::ChangeAmountItem(FName Name, int16 amount)
{


	GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("Contains %s"), Inventory.Contains(Name) ? TEXT("true") : TEXT("false")));
	if (Inventory.Contains(Name)) {
		if ((Inventory[Name] + amount) < 0) { Inventory[Name] = 0; return; }
		Inventory[Name] += amount;
		GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("Num %f"), &Inventory[Name]));
	}
}

TMap<FName, int16> UBuildingInventory::GetInventory()
{
	return Inventory;
}


