// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GridItem.h"
#include "GameFramework/Actor.h"
#include "AGrid.generated.h"

UCLASS()
class MALOM_API AAGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAGrid();
	
	TArray<TArray<AGridItem>> Matrix;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<AGridItem> GridItem;

	UPROPERTY(EditAnywhere)
	FVector2f OffsetVector = {100l, 100l};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
