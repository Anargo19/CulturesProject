// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingSystem.h"

#include "Building.h"
#include "CulturesProjectPlayerController.h"
#include "Components/ShapeComponent.h"

// Sets default values for this component's properties
UBuildingSystem::UBuildingSystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	isPlaced = false;
	CanPlace = false;
	
	// ...
}

bool UBuildingSystem::IsBuildingPlaced()
{
	return isPlaced;
}

void UBuildingSystem::Place()
{
	if (!CanPlace)
		return;
	isPlaced = true;
	GetOwner()->SetActorEnableCollision(true);
	if (ACulturesProjectPlayerController* PC = Cast<ACulturesProjectPlayerController>(
		GetWorld()->GetFirstPlayerController()))
		PC->SelectedBuilding = nullptr;
	if (ABuilding* Building = Cast<ABuilding>(GetOwner()))
	{
		Building->Tags.Add(TEXT("Builder"));
		Building->StaticMesh->SetCollisionProfileName(TEXT("BlockAllDynamic"));
		Building->StaticMesh->SetStaticMesh(ConstructionSteps[CurrentConstructionStep]);
		Building->StaticMesh->SetMaterial(0, BuildingMaterial);
	}
	//DestroyComponent();
}

bool UBuildingSystem::NextConstructionStep(FName Item)
{
	CurrentNeededResources.RemoveSingle(Item);
	if (CurrentNeededResources.Num() == 0)
	{
		EndConstruction();
		return true;
	}
	float StepPercent = 100.0f / static_cast<float>(ConstructionSteps.Num());
	float BuildPercent = 100.0f - static_cast<float>(CurrentNeededResources.Num()) / static_cast<float>(NeededResources.
		Num()) * 100.0f;
	UE_LOG(LogTemp, Warning, TEXT("Item Name : %s"), *Item.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Build step : %f"), StepPercent);
	UE_LOG(LogTemp, Warning, TEXT("Current build percent : %f"), BuildPercent);
	int32 CurrentStep = FMath::DivideAndRoundNearest<int32>(BuildPercent , StepPercent);
	if ( CurrentConstructionStep < CurrentStep-1)
	{
		if(CurrentConstructionStep == ConstructionSteps.Num()-1)
			return false;
		
		CurrentConstructionStep++;
		if(ABuilding* Building = Cast<ABuilding>(GetOwner()))
		{
			Building->StaticMesh->SetStaticMesh(ConstructionSteps[CurrentConstructionStep]);
		}
	}

	return false;
}

// Used to finish the construction
void UBuildingSystem::EndConstruction()
{
	//If the owner is a building actor
	if (ABuilding* Building = Cast<ABuilding>(GetOwner()))
	{
		// We set the static mesh to finished
		Building->StaticMesh->SetStaticMesh(Finished);

		// We remove the tag for builders
		Building->Tags.Remove(TEXT("Builder"));

		// Destroy the component
		DestroyComponent();
	}
}

FName UBuildingSystem::CheckRandomNeededItem()
{
	int32 RandomNumber = FMath::RandRange(0, CurrentNeededResources.Num() - 1);
	return CurrentNeededResources[RandomNumber];
}

TArray<FName> UBuildingSystem::GetAllNeededItem()
{
	return CurrentNeededResources;
}

void UBuildingSystem::OnCollisionEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                     UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (ABuilding* Building = Cast<ABuilding>(GetOwner()))
	{
		if (Building->StaticMesh->GetOverlapInfos().Num() > 0)
			return;
		CanPlace = true;
		Building->StaticMesh->SetMaterial(0, BuildingValid);
	}
}


// Called when the game starts
void UBuildingSystem::BeginPlay()
{
	Super::BeginPlay();
	if(isPlaced)
	{
		
		DestroyComponent();
		return;
	}
	CurrentNeededResources = NeededResources;
	if (ABuilding* Building = Cast<ABuilding>(GetOwner()))
	{
		Building->StaticMesh->SetCollisionProfileName(TEXT("OverlapAll"));
		Building->StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &UBuildingSystem::OnCollision);
		Building->StaticMesh->OnComponentEndOverlap.AddDynamic(this, &UBuildingSystem::OnCollisionEnd);
		CanPlace = Building->StaticMesh->GetOverlapInfos().Num() > 0;
		CurrentConstructionStep = 0;
		if (ACulturesProjectPlayerController* PC = Cast<ACulturesProjectPlayerController>(
			GetWorld()->GetFirstPlayerController()))
			PC->SelectedBuilding = Cast<ABuilding>(GetOwner());
		// ...	
	}
}


void UBuildingSystem::OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                  UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
                                  const FHitResult& Hit)
{
	if (ABuilding* Building = Cast<ABuilding>(GetOwner()))
	{
		Building->StaticMesh->SetMaterial(0, BuildingInvalid);
		CanPlace = false;
	}
}

// Called every frame
void UBuildingSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!isPlaced)
	{
		FHitResult result;
		GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursor(ECollisionChannel::ECC_WorldDynamic, true,
		                                                                result);
		if (IsValid(result.GetActor()))
			GetOwner()->SetActorLocation(
				FVector(result.Location.X, result.Location.Y, GetOwner()->GetActorLocation().Z));
	}

	// ...
}
