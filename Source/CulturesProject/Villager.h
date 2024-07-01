// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interactable.h"
#include "Components/DecalComponent.h"
#include "JobComponent.h"
#include "Villager.generated.h"

UCLASS()
class CULTURESPROJECT_API AVillager : public ACharacter, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVillager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void NeedDecreaseFunction();
	UPROPERTY(EditAnywhere)
	UDecalComponent* Decal;
	UPROPERTY(EditAnywhere)
	UJobComponent* JobComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(Blueprintable)
	virtual void Interact() override;
	UFUNCTION(BlueprintCallable)
	bool NeedsLow() const;
	UFUNCTION(BlueprintCallable)
	void ChangeHunger(int64 amount);
	UFUNCTION(Blueprintable)
	virtual void Deselect() override;
	UFUNCTION(BlueprintCallable)
	virtual float TakeDamage(float DamageAmount,
	struct FDamageEvent const & DamageEvent,
	class AController * EventInstigator,
	AActor * DamageCauser
) override;
	UPROPERTY(EditAnywhere)
	FName VillagerName;

private:
	UPROPERTY(EditAnywhere)
	int64 _health;
	UPROPERTY(EditAnywhere)
	int64 _hunger;
	UPROPERTY(EditAnywhere)
	int64 _sleep;

	FTimerHandle NeedTimer;

};
