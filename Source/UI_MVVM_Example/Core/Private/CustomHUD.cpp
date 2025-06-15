#include "UI_MVVM_Example/Core/Public/CustomHUD.h"

#include "Blueprint/UserWidget.h"
#include "CommonUI/Public/CommonActivatableWidget.h"
#include "Kismet/GameplayStatics.h"
#include "ModelViewViewModel/Public/MVVMGameSubsystem.h"
#include "UI_MVVM_Example/Viewmodel/Public/HUDViewModel.h"

void ACustomHUD::BeginPlay()
{
	Super::BeginPlay();

	this->HUDPanelWidget = CreateWidget<UCommonActivatableWidget>(UGameplayStatics::GetPlayerController(this, 0),
	                                                              this->HUDPanelClass);
	if (IsValid(this->HUDPanelWidget))
	{
		this->HUDPanelWidget->AddToViewport();
	}

	UHUDViewModel* HUDViewModel = NewObject<UHUDViewModel>();
	if (IsValid(HUDViewModel) == false)
	{
		return;
	}
	const UGameInstance* GameInstance = GetGameInstance();
	if (IsValid(GameInstance) == false)
	{
		return;
	}
	const UMVVMGameSubsystem* MVVMSubsystem = GameInstance->GetSubsystem<UMVVMGameSubsystem>();
	if (IsValid(MVVMSubsystem) == false)
	{
		return;
	}
	UMVVMViewModelCollectionObject* ViewModelCollection = MVVMSubsystem->GetViewModelCollection();
	if (IsValid(ViewModelCollection))
	{
		ViewModelCollection->AddViewModelInstance(
			FMVVMViewModelContext(UHUDViewModel::StaticClass(), FName("HudViewModel")), HUDViewModel);
	}
}

void ACustomHUD::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (IsValid(this->PauseMenuWidget))
	{
		this->PauseMenuWidget->OnDeactivated().RemoveAll(this);
	}
}

void ACustomHUD::ShowPauseMenu()
{
	// To get inputs from Enhanced Input mapping in Common UI we remove and add to viewport specific widgets.
	if (IsValid(this->HUDPanelWidget) == false)
	{
		return;
	}
	this->HUDPanelWidget->RemoveFromParent();
	this->HUDPanelWidget = nullptr;

	this->PauseMenuWidget = CreateWidget<UCommonActivatableWidget>(UGameplayStatics::GetPlayerController(this, 0),
	                                                               this->PauseMenuClass);
	if (IsValid(this->PauseMenuWidget) == false)
	{
		return;
	}

	this->PauseMenuWidget->AddToViewport(1);
	this->PauseMenuWidget->OnDeactivated().AddWeakLambda(this, [&]
	{
		if (IsValid(this->PauseMenuWidget) == false)
		{
			return;
		}
		this->PauseMenuWidget->RemoveFromParent();

		this->HUDPanelWidget = CreateWidget<UCommonActivatableWidget>(UGameplayStatics::GetPlayerController(this, 0),
		                                                              this->HUDPanelClass);
		if (IsValid(this->HUDPanelWidget))
		{
			this->HUDPanelWidget->AddToViewport();
		}
	});
}
