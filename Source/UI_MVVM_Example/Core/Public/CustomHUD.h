#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CustomHUD.generated.h"

class UHUDViewModel;
class UCommonActivatableWidget;

UCLASS()
class UI_MVVM_EXAMPLE_API ACustomHUD : public AHUD
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ShowPauseMenu();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UCommonActivatableWidget> HUDPanelClass = {};
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UCommonActivatableWidget> PauseMenuClass = {};
	
protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	UPROPERTY()
	TObjectPtr<UCommonActivatableWidget> HUDPanelWidget = nullptr;
	
	UPROPERTY()
	TObjectPtr<UCommonActivatableWidget> PauseMenuWidget = nullptr;
};
