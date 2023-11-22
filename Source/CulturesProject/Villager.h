// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Villager.generated.h"

UCLASS()
class CULTURESPROJECT_API AVillager : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVillager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void NeedDecreaseFunction();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere)
	int _health;
	UPROPERTY(EditAnywhere)
	int _hunger;
	UPROPERTY(EditAnywhere)
	int _sleep;

	FTimerHandle NeedTimer;

};
