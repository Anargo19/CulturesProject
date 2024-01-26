// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "JobSelectionListItem.generated.h"

/**
 * 
 */
UCLASS()
class CULTURESPROJECT_API UJobSelectionListItem : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		class UButton* JobButton;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		class UTextBlock* JobText;

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
		void ButtonClicked();
};
