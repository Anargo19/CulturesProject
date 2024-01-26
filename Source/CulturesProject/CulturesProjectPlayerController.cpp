// Copyright Epic Games, Inc. All Rights Reserved.

#include "CulturesProjectPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "CulturesProjectCharacter.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "VillagerAI.h"
#include "VillagerHUD.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

ACulturesProjectPlayerController::ACulturesProjectPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	CachedDestination = FVector::ZeroVector;
	FollowTime = 0.f;
}

void ACulturesProjectPlayerController::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Level %s"), *GetWorld()->GetName())
	AVillagerHUD* HUD = GetHUD<AVillagerHUD>();
	HUD->ShowSidebar();
	
	if(GetWorld()->GetName() == "MainMenu")
	HUD->ShowMainMenu();
	

	//Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputMapping, 0);
	}
}

void ACulturesProjectPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(LeftC, ETriggerEvent::Triggered, this, &ACulturesProjectPlayerController::LeftClick);
		EnhancedInputComponent->BindAction(RightClick, ETriggerEvent::Triggered, this, &ACulturesProjectPlayerController::RightClickFunction);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}


void ACulturesProjectPlayerController::LeftClick(const FInputActionInstance& Instance)
{
	//your code
	float MoveValue = Instance.GetValue().Get<bool>();
	if (!MoveValue)
		return;
	FHitResult result;
	GetHitResultUnderCursor(ECollisionChannel::ECC_WorldDynamic, true, result);
	FName name = TEXT("");

	if(SelectedBuilding)
	{
		UE_LOG(LogTemp, Warning, TEXT("Can place %s"),  SelectedBuilding->BuildingSystem->IsBuildingPlaced() ? TEXT("true") : TEXT("false") )
		SelectedBuilding->BuildingSystem->Place();
		return;
	}
	if (IInteractable* Interactable = Cast<IInteractable>(result.GetActor()))
	{
		Interactable->Interact();
		return;
	}
	if (SelectedActors.IsEmpty())
		return;
	for (int32 ItemIndex = 0; ItemIndex < SelectedActors.Num(); ItemIndex++)
	{

		if (AVillager* Villager = Cast<AVillager>(SelectedActors[ItemIndex])) {
			if (AVillagerAI* ai = Cast<AVillagerAI>(Villager->GetController())) {

				GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("HAVE AI")));
				ai->MoveTo(result.Location, true);
			}
		}
	}
}
void ACulturesProjectPlayerController::RightClickFunction(const FInputActionInstance& Instance)
{
	//your code
	float MoveValue = Instance.GetValue().Get<bool>();
	for (int32 ItemIndex = 0; ItemIndex < SelectedActors.Num(); ItemIndex++)
	{

		GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("REMOVING %s"), *FString::FromInt(SelectedActors.Num())));
		if (IInteractable* Interactable = Cast<IInteractable>(SelectedActors[ItemIndex])) {
			Interactable->Deselect();
		}
	}

	SelectedActors.Empty();


}

