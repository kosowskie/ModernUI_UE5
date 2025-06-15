#pragma once

#include "CoreMinimal.h"

#include "CommonActivatableWidget.h"

#include "PauseMenuWidget.generated.h"

class UCommonButtonBase;

UCLASS()
class UI_MVVM_EXAMPLE_API UPauseMenuWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	void OnHoverReturnToGameButton();
	void OnHoverQuitButton();
	
	void OnUnhoverReturnToGameButton();
	void OnUnhoverQuitButton();
	
	void OnClickedReturnToGameButton();
	void OnClickedQuitButton();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UCommonButtonBase> ReturnToGameButton = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UCommonButtonBase> QuitButton = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidgetAnim), Transient)
	TObjectPtr<UWidgetAnimation> ReturnToGameHover = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidgetAnim), Transient)
	TObjectPtr<UWidgetAnimation> QuitHover = nullptr;
};
