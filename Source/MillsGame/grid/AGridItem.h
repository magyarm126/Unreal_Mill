#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MillsGame/model/MillNodeState.h"
#include "AGridItem.generated.h"

UCLASS()
class MILLSGAME_API AGridItem : public AActor
{
	GENERATED_BODY()

public:
	AGridItem();

	void ChangeState(EMillNodeState NewState);

	EMillNodeState GetState() const;

protected:
	EMillNodeState InternalState = Neutral;

	void UpdateColor();
};
