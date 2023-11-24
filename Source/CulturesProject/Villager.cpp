// Fill out your copyright notice in the Description page of Project Settings.


#include "Villager.h"
#include "CulturesProjectPlayerController.h"

// Sets default values
AVillager::AVillager()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	_health = 100;
	_hunger = 100;
	_sleep = 100;
	VillagerName = TEXT("NICE");

}

// Called when the game starts or when spawned
void AVillager::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(NeedTimer, this, &AVillager::NeedDecreaseFunction, 2.0f, true);
	
}

// Called every frame
void AVillager::Tick(float DeltaTime)
{
	//Super::Tick(DeltaTime);


}
// Called every frame
void AVillager::Interact()
{
	
	GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("CLICKED ! %s"), *VillagerName.ToString()));
	if (ACulturesProjectPlayerController* playerController = Cast<ACulturesProjectPlayerController>(GetWorld()->GetFirstPlayerController()))
	{
		playerController->SelectedVillager = this;

	}


}

// Called to bind functionality to input
void AVillager::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Called to bind functionality to input
void AVillager::NeedDecreaseFunction()
{

	_hunger -= 1;
	_sleep -= 2;

}

