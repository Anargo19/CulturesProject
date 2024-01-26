// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BuildingSelectionListItem.generated.h"

/**
 * 
 */
UCLASS()
class CULTURESPROJECT_API UBuildingSelectionListItem : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* BuildingButton;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* BuildingText;

	UPROPERTY(EditAnywhere)
	UDataTable* BuildingDatatable;
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void ButtonClicked();
};
