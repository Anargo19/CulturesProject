// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingUI.h"

#include "Components/ProgressBar.h"


void UBuildingUI::SetHealth(int32 amount)
{
	HealthBar->SetPercent(float(amount) / 100.0f);
}

void UBuildingUI::SetBuilding(ABuilding* Building)
{
	CurrentBuilding = Building;
}

void UBuildingUI::NativeConstruct()
{
	
}
