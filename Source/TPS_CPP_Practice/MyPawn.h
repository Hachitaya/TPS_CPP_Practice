// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

class UCapsuleComponent;
class USkeletalMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UArrowComponent;
class UCharacterMovementComponent;



UCLASS()
class TPS_CPP_PRACTICE_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UCapsuleComponent* Capsule;
	USkeletalMeshComponent* SkeletalMesh;
	USpringArmComponent* SpringArm;
	UCameraComponent* Camera;
	UArrowComponent* Arrow;
	UCharacterMovementComponent* Movement;




};
