// Fill out your copyright notice in the Description page of Project Settings.


#include "APlayer.h"

// Sets default values
AAPlayer::AAPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("MyCamera"));
}

// Called when the game starts or when spawned
void AAPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

