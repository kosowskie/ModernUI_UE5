#pragma once

#include "CoreMinimal.h"

#include "CommonActivatableWidget.h"

#include "HUDPanel.generated.h"

struct FSlotsStates;
enum class EHealthLevel : uint8;
class UImage;

UCLASS()
class UI_MVVM_EXAMPLE_API UHUDPanel : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void UpdateHealthAnim(const float HealthValue, const float DeltaTime);

	UFUNCTION(BlueprintCallable)
	void ChangeHealthLevel(const EHealthLevel HealthLevel);
	
	UFUNCTION(BlueprintCallable)
	void OnSlotsMaxLevel(const FSlotsStates& SlotsStates);

protected:
	virtual void NativeOnActivated() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UImage> Circle = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UImage> Heart = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidgetAnim), Transient)
	TObjectPtr<UWidgetAnimation> MaxSlotsAnim = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UMaterialInstance> CircleMaterial = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Heart Color")
	FLinearColor DefaultHeartColor = FLinearColor(0.854993, 0.715693, 0.304987);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Heart Color")
	FLinearColor LowHeartColor = FLinearColor(0.467784, 0.147027, 0.049707);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Heart Color")
	FLinearColor DeadHeartColor = FLinearColor(0.006512, 0.014444, 0.026241);
};
