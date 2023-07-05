#include "AGridItem.h"

AGridItem::AGridItem()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGridItem::ChangeState(const EMillNodeState NewState)
{
	InternalState = NewState;
	UpdateColor();
}

void AGridItem::UpdateColor()
{
	FLinearColor NewColor = FLinearColor::Yellow;
	switch (InternalState)
	{
	case Neutral:
		NewColor = FLinearColor::White;
	case P1:
		NewColor = FLinearColor::Red;
	case P2:
		NewColor = FLinearColor::Green;
	}

	TSet<UActorComponent*> Components = GetComponents();
	for (UActorComponent* const Component : Components)
	{
		if (Component->GetClass() == UStaticMeshComponent::StaticClass())
		{
			UStaticMeshComponent* StaticMeshComponent = dynamic_cast<UStaticMeshComponent*>(Component);
			UMaterialInterface* MaterialInterface = StaticMeshComponent->GetMaterial(0);

			UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(MaterialInterface, this);
			DynamicMaterial->SetVectorParameterValue(FName(TEXT("Color")), NewColor);

			StaticMeshComponent->SetMaterial(0, DynamicMaterial);
		}
	}
}
