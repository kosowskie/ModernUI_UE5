#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"

#include "HUDViewModel.generated.h"

UENUM(BlueprintType)
enum class EHealthLevel : uint8
{
	Default = 0,
	HalfHealth = 1,
	LowHealth = 2,
	Dead = 3
};

USTRUCT(BlueprintType)
struct FSlotsStates
{
	GENERATED_BODY()

	FSlotsStates()
	{
		this->bLeftSlot = false;
		this->bMiddleSlot = false;
		this->bRightSlot = false;
	}

	FSlotsStates(const bool bNewLeftSlot, const bool bNewMiddleSlot, const bool bNewRightSlot) :
		bLeftSlot(bNewLeftSlot), bMiddleSlot(bNewMiddleSlot), bRightSlot(bNewRightSlot)
	{
	}

	bool operator==(const FSlotsStates& Other) const
	{
		return this->bLeftSlot == Other.bLeftSlot && this->bMiddleSlot == Other.bMiddleSlot &&
			this->bRightSlot == Other.bRightSlot;
	}

	bool IsFull() const
	{
		return this->bLeftSlot == true && this->bMiddleSlot == true && this->bRightSlot == true;
	}

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bLeftSlot = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bMiddleSlot = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bRightSlot = false;
};

UCLASS(Blueprintable)
class UI_MVVM_EXAMPLE_API UHUDViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter)
	void SetHealthValue(float NewValue);

	UFUNCTION(BlueprintSetter)
	void SetHealthLevel(EHealthLevel NewHealthLevel);

	UFUNCTION(BlueprintSetter)
	void SetSlotsStates(const FSlotsStates& NewSlotsStates);

private:
	UPROPERTY(BlueprintReadWrite, FieldNotify, Setter, meta = (AllowPrivateAccess))
	EHealthLevel HealthLevel = EHealthLevel::Default;

	UPROPERTY(BlueprintReadWrite, FieldNotify, Setter, meta = (AllowPrivateAccess))
	float HealthValue = 1.f;

	UPROPERTY(BlueprintReadWrite, FieldNotify, Setter, meta = (AllowPrivateAccess))
	FSlotsStates SlotsStates = {};

	UPROPERTY(BlueprintReadWrite, FieldNotify, meta = (AllowPrivateAccess))
	float SlotProgressValue = 0.f;
};
