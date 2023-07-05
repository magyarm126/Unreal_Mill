#pragma once

#include "CoreMinimal.h"
#include "AGridItem.h"
#include "GameFramework/Actor.h"
#include "AGrid.generated.h"

UCLASS()
class MALOM_API AAGrid : public AActor
{
	GENERATED_BODY()
	
public:
	AAGrid();
	
	TArray<TArray<AGridItem*>> Matrix;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<AGridItem> GridItem;

	UPROPERTY(EditAnywhere)
	FVector2f OffsetVector = {100l, 100l};

protected:
	virtual void BeginPlay() override;
};
