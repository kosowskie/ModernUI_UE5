#include "UI_MVVM_Example/UI/Public/HUDPanel.h"

#include "Components/Image.h"
#include "UI_MVVM_Example/Viewmodel/Public/HUDViewModel.h"

DEFINE_LOG_CATEGORY_STATIC(LogHUD, Log, All);

const FName HEALTH_PERCENT_PARAM = FName("HealthPercent");
constexpr float HEALTH_ANIM_SPEED = 3.f;

void UHUDPanel::NativeOnActivated()
{
	Super::NativeOnActivated();

	if (IsValid(this->CircleMaterial) == false)
	{
		return;
	}

	UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(this->CircleMaterial, this);

	if (IsValid(this->Circle) && IsValid(DynMaterial))
	{
		this->Circle->SetBrushFromMaterial(DynMaterial);
	}
}

void UHUDPanel::UpdateHealthAnim(const float HealthValue, const float DeltaTime)
{
	if (IsValid(this->Circle) == false)
	{
		return;
	}
	UMaterialInstanceDynamic* DynMaterial = this->Circle->GetDynamicMaterial();

	// Getting Actual Percentage from Material to interpolate animation with given Health Value
	const FHashedMaterialParameterInfo ParameterInfo = FHashedMaterialParameterInfo{HEALTH_PERCENT_PARAM};
	float ActualHealthPercent = 0.f;
	if (DynMaterial->GetScalarParameterValue(ParameterInfo, ActualHealthPercent) == false)
	{
		UE_LOG(LogHUD, Warning, TEXT("Can't take Scalar Parameter from Dynamic material"));
		return;
	}

	float NewHealthPercent = FMath::FInterpTo(ActualHealthPercent, HealthValue, DeltaTime, HEALTH_ANIM_SPEED);
	DynMaterial->SetScalarParameterValue(HEALTH_PERCENT_PARAM, NewHealthPercent);
}

void UHUDPanel::ChangeHealthLevel(const EHealthLevel HealthLevel)
{
	if (IsValid(this->Heart) == false)
	{
		return;
	}

	switch (HealthLevel)
	{
	case EHealthLevel::Default:
	case EHealthLevel::HalfHealth:
		this->Heart->SetColorAndOpacity(this->DefaultHeartColor);
		break;
	case EHealthLevel::LowHealth:
		this->Heart->SetColorAndOpacity(this->LowHeartColor);
		break;
	case EHealthLevel::Dead:
		this->Heart->SetColorAndOpacity(this->DeadHeartColor);
		break;
	default:
		break;
	}
}

void UHUDPanel::OnSlotsMaxLevel(const FSlotsStates& SlotsStates)
{
	if (this->MaxSlotsAnim == nullptr)
	{
		return;
	}

	if (SlotsStates.IsFull())
	{
		PlayAnimation(this->MaxSlotsAnim);
	}
	else
	{
		StopAnimation(this->MaxSlotsAnim);
	}
}
