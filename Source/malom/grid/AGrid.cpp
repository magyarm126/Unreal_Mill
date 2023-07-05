// Fill out your copyright notice in the Description page of Project Settings.


#include "AGrid.h"

AAGrid::AAGrid()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAGrid::BeginPlay()
{
	Super::BeginPlay();

	int RowCount = 3;
	int ColumnCount = 3;

	AGridItem* Baller = nullptr;
	for (int i = 0; i < RowCount; ++i)
	{
		for (int j = 0; j < ColumnCount; ++j)
		{
			FTransform ActorTransform = GetActorTransform();
			ActorTransform.SetTranslation({(RowCount/2 - i) * OffsetVector.X, (ColumnCount/2 - j) * OffsetVector.Y, 0});
			Baller = GetWorld()->SpawnActor<AGridItem>(GridItem, ActorTransform);
		}
	}
	Baller->ChangeState(P1);
}
	