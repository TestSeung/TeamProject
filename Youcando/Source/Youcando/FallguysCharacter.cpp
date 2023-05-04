// Fill out your copyright notice in the Description page of Project Settings.


#include "FallguysCharacter.h"

// Sets default values
AFallguysCharacter::AFallguysCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFallguysCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::
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
	
	

}


