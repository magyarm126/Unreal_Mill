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

EMillNodeState AGridItem::GetState() const
{
	return InternalState;
}

void AGridItem::UpdateColor()
{
	FLinearColor NewColor = FLinearColor::Yellow;
	switch (InternalState)
	{
	case Neutral:
		NewColor = FLinearColor::White;
		break;
	case P1:
		NewColor = FLinearColor::Red;
		break;
	case P2:
		NewColor = FLinearColor::Green;
		break;
	}

	TSet<UActorComponent*> Components = GetComponents();
	for (UActorComponent* const Component : Components)
	{
		if (Component->GetClass() == UStaticMeshComponent::StaticClass())
		{
			UStaticMeshComponent* StaticMeshComponent = dynamic_cast<UStaticMeshComponent*>(Component);
			UMaterialInterface* MaterialInterface = StaticMeshComponent->GetMaterial(0);

			if (MaterialInterface->GetClass() == UMaterialInstanceDynamic::StaticClass())
			{
				UMaterialInstanceDynamic* DynamicMaterial = dynamic_cast<UMaterialInstanceDynamic*>(MaterialInterface);
				DynamicMaterial->SetVectorParameterValue(FName(TEXT("Color")), NewColor);
			}
			else
			{
				UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(MaterialInterface, this);
				DynamicMaterial->SetVectorParameterValue(FName(TEXT("Color")), NewColor);
				StaticMeshComponent->SetMaterial(0, DynamicMaterial);
			}
		}
	}
}
