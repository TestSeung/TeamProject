// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "FallguysCharacter.generated.h"


class UInputMappingContext;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;


UCLASS()
class YOUCANDO_API AFallguysCharacter : public ACharacter
{
	GENERATED_BODY()

	
	
public:
	// Sets default values for this character's properties


	AFallguysCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = Input)
	UInputMappingContext* ControllMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
	UCameraComponent* Camera;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:


};
