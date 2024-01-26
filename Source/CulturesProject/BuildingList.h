// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ScrollBox.h"
#include "BuildingList.generated.h"

/**
 * 
 */
UCLASS()
class CULTURESPROJECT_API UBuildingList : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetBuildingList(TArray<FName> BuildingNames);
protected:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UScrollBox* BuildingList;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UUserWidget> BuildingButton;

};
