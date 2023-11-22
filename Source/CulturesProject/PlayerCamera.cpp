// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCamera.h"
#include <EnhancedInputComponent.h>
#include <Kismet/KismetMathLibrary.h>

// Sets default values
APlayerCamera::APlayerCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Camera->SetupAttachment(SpringArm);
	moveSpeed = 10;

}

// Called when the game starts or when spawned
void APlayerCamera::BeginPlay()
{
	Super::BeginPlay();
	TargetLocation = GetActorLocation();
	
}

// Called every frame
void APlayerCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	const FVector InterpolateLocation = UKismetMathLibrary::VInterpTo(GetActorLocation(), TargetLocation, DeltaTime, 2);
	SetActorLocation(InterpolateLocation);

}

void APlayerCamera::MoveForward(const FInputActionInstance& Instance)
{
	//your code
	float MoveValue = Instance.GetValue().Get<float>();
	TargetLocation = FVector(1, 0, 0) * MoveValue * moveSpeed + TargetLocation;
}
void APlayerCamera::MoveRight(const FInputActionInstance& Instance)
{
	//your code
	float MoveValue = Instance.GetValue().Get<float>();
	TargetLocation = FVector(0, 1, 0) * MoveValue * moveSpeed + TargetLocation;
}
void APlayerCamera::LeftClick(const FInputActionInstance& Instance)
{
	//your code
	float MoveValue = Instance.GetValue().Get<bool>();
	FHitResult result;
	if (MoveValue) {
		GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursor(ECollisionChannel::ECC_WorldDynamic, true, result);
		GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("CLICKED ! %s"), result.GetActor()->FindComponentByClass<UStaticMeshComponent>()));
	}
}

// Called to bind functionality to input
void APlayerCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("START")));
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("CHECK PASSED")));
		EnhancedInputComponent->BindAction(MoveF, ETriggerEvent::Triggered, this, &APlayerCamera::MoveForward);
		EnhancedInputComponent->BindAction(MoveR, ETriggerEvent::Triggered, this, &APlayerCamera::MoveRight);
		EnhancedInputComponent->BindAction(LeftC, ETriggerEvent::Triggered, this, &APlayerCamera::LeftClick);

	}

}

