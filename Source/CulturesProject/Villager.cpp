// Fill out your copyright notice in the Description page of Project Settings.


#include "Villager.h"
#include "Components/DecalComponent.h"
#include "JobComponent.h"
#include "CulturesProjectPlayerController.h"
#include "VillagerAI.h"
#include "VillagerHUD.h"
#include "Navigation/PathFollowingComponent.h"

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
	AVillagerAI* AIC = Cast<AVillagerAI>(GetController());
	//AIC->GetPathFollowingComponent()->OnRequestFinished.AddUObject(AIC, &AVillagerAI::OnMoveCompleted);
	GetWorldTimerManager().SetTimer(NeedTimer, this, &AVillager::NeedDecreaseFunction, 2.0f, true);
	

	//JobComponent->SetJob(TEXT("Miner"));
	
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
		//playerController->SelectedActors.AddUnique(this);
		for (int32 ItemIndex = 0; ItemIndex < playerController->SelectedActors.Num(); ItemIndex++)
		{
			GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("REMOVING %s"), *FString::FromInt(playerController->SelectedActors.Num())));
			if (IInteractable* Interactable = Cast<IInteractable>(playerController->SelectedActors[ItemIndex])) {
				Interactable->Deselect();
			}
		}
		playerController->SelectedActors.Empty();
		playerController->SelectedActors.AddUnique(this);

	}
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	UE_LOG(LogTemp, Warning, TEXT("Selected Controller %s"), *PC->GetName());
	AVillagerHUD* HUD = PC->GetHUD<AVillagerHUD>();
	UE_LOG(LogTemp, Warning, TEXT("Get HUD %s"), *HUD->GetName());
	HUD->ShowVillagerMenu(VillagerName, _health, _hunger, _sleep, this);
	
	

}

void AVillager::Deselect()
{
	Decal->SetHiddenInGame(true);

	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	AVillagerHUD* HUD = PC->GetHUD<AVillagerHUD>();
	HUD->HideVillagerMenu();
}

// Called to bind functionality to input
void AVillager::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Called to bind functionality to input
void AVillager::NeedDecreaseFunction()
{

	if (_hunger <= 0) {
		_health -= 1;
	}
	else {
		_hunger -= 1;

	}
	if (_sleep - 2 < 0) {
		_sleep = 0;
		return;
	}
	_sleep -= 2;

	if (ACulturesProjectPlayerController* playerController = Cast<ACulturesProjectPlayerController>(GetWorld()->GetFirstPlayerController()))
	{
		if (playerController->SelectedActors.Contains(this)) {
			APlayerController* PC = GetWorld()->GetFirstPlayerController();
			//UE_LOG(LogTemp, Warning, TEXT("Selected Controller %s"), *PC->GetName());
			AVillagerHUD* HUD = PC->GetHUD<AVillagerHUD>();
			//UE_LOG(LogTemp, Warning, TEXT("Get HUD %s"), *HUD->GetName());
			HUD->UpdateValues(VillagerName, _health, _hunger, _sleep);
		}

	}

}

