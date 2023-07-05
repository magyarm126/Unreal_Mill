// Fill out your copyright notice in the Description page of Project Settings.


#include "AMainPlayer.h"

AMainPlayer::AMainPlayer()
{
	PrimaryActorTick.bCanEverTick = true;
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("MyCamera"));
}

void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
