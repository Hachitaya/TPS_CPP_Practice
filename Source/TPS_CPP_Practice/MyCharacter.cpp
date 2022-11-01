// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include <Camera/CameraComponent.h>
#include <Kismet/KismetMathLibrary.h>
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimClassData.h"
#include "UObject/Class.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = GetMesh();
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM_Body(TEXT("SkeletalMesh'/Game/Mannequin/Character/Mesh/SK_Mannequin_Female.SK_Mannequin_Female'"));
	if (SM_Body.Succeeded())
	{
		Mesh->SetSkeletalMesh(SM_Body.Object);
	}
	//static ConstructorHelpers::FObjectFinder<>


	Mesh->AddLocalRotation(FRotator(0, -90,0));
	Mesh->AddLocalOffset(FVector(0, 0, -90));
	//static ConstructorHelpers::FObjectFinder<UAnimBlueprint> Anim(TEXT("AnimBlueprint'/Game/Mannequin/Animations/ThirdPerson_AnimBP.ThirdPerson_AnimBP'"));
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> Anim(TEXT("AnimBlueprint'/Game/MyFolder/Animation/NewAnimBlueprint.NewAnimBlueprint'"));

	Mesh->SetAnimInstanceClass(Anim.Object->GeneratedClass);


	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->AttachTo(GetRootComponent());
	SpringArm->TargetArmLength = 300;
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->AttachTo(SpringArm);

	GetCharacterMovement()->bOrientRotationToMovement = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &AMyCharacter::MyJump);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Released, this, &AMyCharacter::MyJumpEnd);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AMyCharacter::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMyCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyCharacter::MoveRight);
	
}

void AMyCharacter::Turn(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}

void AMyCharacter::LookUp(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
}

void AMyCharacter::MyJump()
{
	Jump();
}

void AMyCharacter::MyJumpEnd()
{
	StopJumping();
}

void AMyCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(UKismetMathLibrary::GetForwardVector(FRotator(0, GetControlRotation().Yaw, 0)),AxisValue);
}

void AMyCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(UKismetMathLibrary::GetRightVector(FRotator(0, GetControlRotation().Yaw, 0)), AxisValue);
}

