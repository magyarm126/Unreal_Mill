// Fill out your copyright notice in the Description page of Project Settings.


#include "AGrid.h"

// Sets default values
AAGrid::AAGrid()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//AddComponentByClass(AGridItem::StaticClass(), false, FTransform(), false);

	//const AGridItem* Instance = CreateDefaultSubobject<AGridItem>(TEXT("Grid Item #1"))
	//TArray<AGridItem> TempArray;
	//TempArray.Push(*Instance);
	//Matrix.Append(&TempArray, 1);
}

// Called when the game starts or when spawned
void AAGrid::BeginPlay()
{
	Super::BeginPlay();

	int RowCount = 3;
	int ColumnCount = 3;
	
	for (int i = 0; i < RowCount; ++i)
	{
		for (int j = 0; j < ColumnCount; ++j)
		{
			FTransform ActorTransform = GetActorTransform();
			ActorTransform.SetTranslation({(RowCount/2 - i) * OffsetVector.X, (ColumnCount/2 - j) * OffsetVector.Y, 0});
			GetWorld()->SpawnActor<AGridItem>(GridItem, ActorTransform);	
		}
	}
}

// Called every frame
void AAGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
