// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Resource.generated.h"

UCLASS()
class CULTURESPROJECT_API AResource : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AResource();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		int32 NbResources;
	UPROPERTY(EditAnywhere)
		FName ResourceItemName;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
	void ChangeResourceAmount(int32 amount);
	UFUNCTION(BlueprintCallable)
	FName GetResourceItemName();

};
