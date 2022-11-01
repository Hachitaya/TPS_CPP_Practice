// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class TPS_CPP_PRACTICE_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()


public:	

	UMyAnimInstance();

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;




	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn)
	float CurrentPawnSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn)
	bool IsInAir;
};
