// Fill out your copyright notice in the Description page of Project Settings.


#include "AGrid.h"

#include <string>

AAGrid::AAGrid()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAGrid::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < RowCount; ++i)
	{
		TArray<AGridItem*> TempArray = TArray<AGridItem*>();
		for (int j = 0; j < ColumnCount; ++j)
		{
			FTransform ActorTransform = GetActorTransform();
			ActorTransform.SetTranslation({
				(RowCount / 2 - i) * OffsetVector.X, (ColumnCount / 2 - j) * -OffsetVector.Y, 0
			});
			AGridItem* NewGridItem = GetWorld()->SpawnActor<AGridItem>(GridItem, ActorTransform);

			auto IndexString = "[" + std::to_string(i) + "," + std::to_string(j) + "]";
			NewGridItem->SetActorLabel(NewGridItem->GetActorLabel() + IndexString.c_str());
			
			TempArray.Add(std::move(NewGridItem));
		}
		Matrix.Add(std::move(TempArray));
	}

	for (int i = 0; i < Matrix.Num(); ++i)
	{
		for (int j = 0; j < Matrix[i].Num(); ++j)
		{
			Matrix[i][j]->ChangeState(static_cast<EMillNodeState>((i + j) % 2 + 1));
		}
	}
}
