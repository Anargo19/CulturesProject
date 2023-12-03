// Fill out your copyright notice in the Description page of Project Settings.


#include "Villager.h"
#include "Components/DecalComponent.h"
#include "JobComponent.h"
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

	Decal = CreateDefaultSubobject<UDecalComponent>(TEXT("Decal"));
	Decal->SetupAttachment(GetComponentByClass<USkeletalMeshComponent>());
	JobComponent = CreateDefaultSubobject<UJobComponent>(TEXT("Job Component"));
	Decal->SetRelativeRotation(FQuat::MakeFromEuler(FVector(0, 90, 0)));
	Decal->SetRelativeLocation(FVector(0, 0, -240));
	//Decal->SetRelativeScale3D(FVector(1, 1, 1));
	Decal->SetHiddenInGame(true);

}

// Called when the game starts or when spawned
void AVillager::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(NeedTimer, this, &AVillager::NeedDecreaseFunction, 2.0f, true);
	

	JobComponent->SetJob(TEXT("Lumber"));
	
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
	Decal->SetHiddenInGame(false);
	if (ACulturesProjectPlayerController* playerController = Cast<ACulturesProjectPlayerController>(GetWorld()->GetFirstPlayerController()))
	{
		playerController->SelectedActors.AddUnique(this);

	}

	
	

}

void AVillager::Deselect()
{
	Decal->SetHiddenInGame(true);
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

