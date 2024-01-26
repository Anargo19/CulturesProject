// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SideBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class CULTURESPROJECT_API USideBarWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
		UPROPERTY(EditAnywhere, meta = (BindWidget))
		class UButton* BuildingButton;

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
		void BuildingButtonClicked();
};
