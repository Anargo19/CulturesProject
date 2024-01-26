// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Villager.h"
#include "VillagerWidget.generated.h"

/**
 * 
 */
UCLASS()
class CULTURESPROJECT_API UVillagerWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
		void SetVillager(AVillager* Villager);
	UFUNCTION(BlueprintCallable)
		void SetValues(FName VillagerName, int32 Health, int32 Hunger, int32 Sleep);
	UFUNCTION(BlueprintCallable)
		void SetJob(FName Job);


	UPROPERTY(EditAnywhere, meta = (BindWidget))
		class UEditableText* VillagerNameText;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		class UProgressBar* HealthBar;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		class UImage* HealthSprite;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* HungerBar;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		class UImage* HungerSprite;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* SleepBar;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		class UImage* SleepSprite;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		class UButton* JobButton;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		class UTextBlock* JobText;

protected:

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere)
	AVillager* CurrentVillager;

	UFUNCTION(BlueprintCallable)
		void JobButtonClicked();
};
