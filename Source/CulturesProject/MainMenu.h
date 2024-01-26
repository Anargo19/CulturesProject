// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class CULTURESPROJECT_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton* PlayButton;
	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	UButton* QuitButton;

	
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void PlayGame();
	UFUNCTION(BlueprintCallable)
	void QuitGame();
};
