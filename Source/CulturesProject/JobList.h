// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ListView.h"
#include <Components/ScrollBox.h>
#include "JobList.generated.h"

/**
 * 
 */
UCLASS()
class CULTURESPROJECT_API UJobList : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetJobList(TArray<FName> JobNames);
protected:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UScrollBox* JobList;
		UPROPERTY(EditDefaultsOnly)
			TSubclassOf<class UUserWidget> JobButton;

		UFUNCTION(BlueprintCallable)
			void JobButtonClicked();
};
