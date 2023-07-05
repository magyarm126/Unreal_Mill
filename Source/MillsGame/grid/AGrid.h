#pragma once

#include "CoreMinimal.h"
#include "AGridItem.h"
#include "GameFramework/Actor.h"
#include "AGrid.generated.h"

UCLASS()
class MILLSGAME_API AAGrid : public AActor
{
	GENERATED_BODY()

public:
	AAGrid();

	UPROPERTY(EditAnywhere)
	TSubclassOf<AGridItem> GridItem;

	UPROPERTY(EditAnywhere)
	FVector2f OffsetVector = {150l, 150l};

	UPROPERTY(EditAnywhere)
	int RowCount = 3;

	UPROPERTY(EditAnywhere)
	int ColumnCount = 3;

protected:
	virtual void BeginPlay() override;

	TArray<TArray<AGridItem*>> Matrix;
};
