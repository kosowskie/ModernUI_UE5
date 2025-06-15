#include "UI_MVVM_Example/Viewmodel/Public/HUDViewModel.h"

void UHUDViewModel::SetHealthValue(float NewValue)
{
	UE_MVVM_SET_PROPERTY_VALUE(HealthValue, NewValue);
}

void UHUDViewModel::SetHealthLevel(EHealthLevel NewHealthLevel)
{
	switch (NewHealthLevel)
	{
	case EHealthLevel::Default:
		SetHealthValue(1.f);
		break;
	case EHealthLevel::HalfHealth:
		SetHealthValue(0.5f);
		break;
	case EHealthLevel::LowHealth:
		SetHealthValue(0.2f);
		break;
	case EHealthLevel::Dead:
		SetHealthValue(0.f);
		break;
	}

	UE_MVVM_SET_PROPERTY_VALUE(HealthLevel, NewHealthLevel);
}

void UHUDViewModel::SetSlotsStates(const FSlotsStates& NewSlotsStates)
{
	UE_MVVM_SET_PROPERTY_VALUE(SlotsStates, NewSlotsStates);

	float NewSlotProgress = 0.f;
	if (this->SlotsStates.bLeftSlot == true)
	{
		NewSlotProgress += 1.f / 3.f;
	}
	if (this->SlotsStates.bMiddleSlot == true)
	{
		NewSlotProgress += 1.f / 3.f;
	}
	if (this->SlotsStates.bRightSlot == true)
	{
		NewSlotProgress += 1.f / 3.f;
	}

	UE_MVVM_SET_PROPERTY_VALUE(SlotProgressValue, NewSlotProgress);
}
