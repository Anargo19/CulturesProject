// Fill out your copyright notice in the Description page of Project Settings.


#include "Building_Headquarter.h"
#include "CulturesProjectPlayerController.h"

// Sets default values for this component's properties
ABuilding_Headquarter::ABuilding_Headquarter()
{
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	Decal->SetHiddenInGame(true);
}


// Called when the game starts
void ABuilding_Headquarter::BeginPlay()
{
	Super::BeginPlay();
	Decal->SetHiddenInGame(true);
	// ...

}

void ABuilding_Headquarter::Interact()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, FString("SELECT BUILDING"));
	Decal->SetHiddenInGame(false);
	if (ACulturesProjectPlayerController* controller = Cast<ACulturesProjectPlayerController>(GetWorld()->GetFirstPlayerController())) {
		controller->SelectedActors.AddUnique(this);
	}
}
void ABuilding_Headquarter::Deselect()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, FString("DESELECT BUILDING"));
	Decal->SetHiddenInGame(true);
}

