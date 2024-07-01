// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BuildingUI.generated.h"

/**
 * 
 */
UCLASS()
class CULTURESPROJECT_API UBuildingUI : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetHealth(int32 amount);
	UFUNCTION(BlueprintCallable)
	void SetBuilding(ABuilding* Building);
private :
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UEditableText* BuildingNameText;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* HealthBar;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UImage* HealthSprite;

	
protected:

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere)
	ABuilding* CurrentBuilding;
};
