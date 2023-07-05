// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "AMainPlayer.generated.h"

UCLASS()
class MALOM_API AMainPlayer : public APawn
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;

public:
	AMainPlayer();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
