// Fill out your copyright notice in the Description page of Project Settings.


#include "Building.h"
#include "Components/DecalComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABuilding::ABuilding()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRootComponent")));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Entry = CreateDefaultSubobject<USceneComponent>(TEXT("Entry"));
	Decal = CreateDefaultSubobject<UDecalComponent>(TEXT("Decal"));
	BuildingSystem = CreateDefaultSubobject<UBuildingSystem>(TEXT("Building System"));
	BuildingInventory = CreateDefaultSubobject<UBuildingInventory>(TEXT("Building Inventory"));
	StaticMesh->SetupAttachment(RootComponent);
	Entry->SetupAttachment(RootComponent);
	//BuildingEntries.AddUnique(Entry);
	Decal->SetupAttachment(StaticMesh);
	Decal->SetRelativeRotation(FQuat::MakeFromEuler(FVector(0, 90, 0)));
	Decal->SetRelativeLocation(FVector(0, 0, -240));
	//Decal->SetRelativeScale3D(FVector(1, 1, 1));
	Decal->SetHiddenInGame(true); 


	Health = 200;

}

// Called when the game starts or when spawned
void ABuilding::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuilding::Interact()
{
	GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("CLICKED BUILDING! %s"), *this->GetFName().ToString()));

	//Decal->SetHiddenInGame(false);

}

void ABuilding::Deselect()
{
}

FVector ABuilding::FindMainEntry()
{
	FVector EntryPosition = Entry->GetRelativeLocation() + GetActorLocation();
	return EntryPosition;
}

FVector ABuilding::FindEntry(int32 entryID)
{
	FVector EntryPosition = BuildingEntries[entryID]->GetRelativeLocation() + GetActorLocation();
	return EntryPosition;
}

