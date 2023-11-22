// Fill out your copyright notice in the Description page of Project Settings.


#include "Building_Headquarter.h"

// Sets default values for this component's properties
ABuilding_Headquarter::ABuilding_Headquarter()
{
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
}


// Called when the game starts
void ABuilding_Headquarter::BeginPlay()
{
	Super::BeginPlay();
	// ...

}

void ABuilding_Headquarter::OnSelected(AActor* Target, FKey ButtonPressed)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, FString("EEEEEEEEEEEEEEEEE"));
}
