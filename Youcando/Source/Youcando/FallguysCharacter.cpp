// Fill out your copyright notice in the Description page of Project Settings.


#include "FallguysCharacter.h"
#include "MyPlayerController.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"



// Sets default values
AFallguysCharacter::AFallguysCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.0f, 42.0f);
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 300.f;
	SpringArm->bUsePawnControlRotation = true;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

}

void AFallguysCharacter::Jump()
{
	bPressedJump = true;
	JumpKeyHoldTime = 0.0f;
}


// Called when the game starts or when spawned
void AFallguysCharacter::BeginPlay()
{
	Super::BeginPlay();
	//EnhancedInput 관련
	if (AMyPlayerController* PlayerController = Cast<AMyPlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(ControllMappingContext, 0);
		}
	}
}
//move 입력값 받는곳
void AFallguysCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector= Value.Get<FVector2D>();
	
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDicrection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(ForwardDicrection, MovementVector.Y);
	const FVector RightDicrection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(RightDicrection, MovementVector.X);

}
//Look 입력값 받는곳
void AFallguysCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisValue= Value.Get<FVector2D>();
	if (GetController())
	{
		AddControllerYawInput(LookAxisValue.X);
		AddControllerPitchInput(LookAxisValue.Y);
	}
}


// Called every frame
void AFallguysCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}	

// Called to bind functionality to input
void AFallguysCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//Action 트리거 형식 
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AFallguysCharacter::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AFallguysCharacter::Look);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AFallguysCharacter::Jump);
	}

}


