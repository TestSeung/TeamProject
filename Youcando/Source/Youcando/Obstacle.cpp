// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"

// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	Box->InitBoxExtent(FVector(32.f, 32.f, 32.f));
	RootComponent = Box;

	Cylinder = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hub"));

}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();
	Cylinder->OnComponentHit.AddDynamic(this, &AObstacle::PlayerTouch);
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



