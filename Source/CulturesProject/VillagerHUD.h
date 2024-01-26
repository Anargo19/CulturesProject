// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Villager.h"
#include "VillagerHUD.generated.h"

/**
 * 
 */
UCLASS()
class CULTURESPROJECT_API AVillagerHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	// Make BlueprintCallable for testing
	UFUNCTION(BlueprintCallable)
	void ShowVillagerMenu(FName VillagerName, int32 Health, int32 Hunger, int32 Sleep, AVillager* Villager);
	UFUNCTION(BlueprintCallable)
	void ShowMainMenu();
	UFUNCTION(BlueprintCallable)
	void ShowSidebar();
	UFUNCTION(BlueprintCallable)
	void ShowJobList(TArray<FName> Jobs);
	UFUNCTION(BlueprintCallable)
	void HideJobList();
	UFUNCTION(BlueprintCallable)
	void ShowBuildingList(TArray<FName> Building);
	UFUNCTION(BlueprintCallable)
	void HideBuildingList();
	UFUNCTION(BlueprintCallable)
	void HideMainMenu();
	UFUNCTION(BlueprintCallable)
	void HideVillagerMenu();
	UFUNCTION(BlueprintCallable)
	void UpdateValues(FName VillagerName, int32 Health, int32 Hunger, int32 Sleep);
	UFUNCTION(BlueprintCallable)
	void SetJob(FName Job);

protected:
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UUserWidget> VillagerPanel;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UUserWidget> Sidebar;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UUserWidget> JobList;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UUserWidget> BuildingList;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UUserWidget> MainMenu;

	// Keep a pointer to be able to hide it
	UPROPERTY()
	class UUserWidget* MainMenuInstance;
	UPROPERTY()
	class UUserWidget* VillagerMenuInstance;
	class UUserWidget* SidebarInstance;
	class UUserWidget* JobListInstance;
	class UUserWidget* BuildingListInstance;
};
