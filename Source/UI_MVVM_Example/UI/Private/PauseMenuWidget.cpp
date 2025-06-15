#include "UI_MVVM_Example/UI/Public/PauseMenuWidget.h"

#include "CommonButtonBase.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

constexpr float HOVER_BUTTON_SPEED = 5.f;

void UPauseMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (this->ReturnToGameButton != nullptr)
	{
		this->ReturnToGameButton->OnClicked().AddUObject(this, &UPauseMenuWidget::OnClickedReturnToGameButton);
		this->ReturnToGameButton->OnHovered().AddUObject(this, &UPauseMenuWidget::OnHoverReturnToGameButton);
		this->ReturnToGameButton->OnUnhovered().AddUObject(this, &UPauseMenuWidget::OnUnhoverReturnToGameButton);
	}

	if (this->QuitButton != nullptr)
	{
		this->QuitButton->OnClicked().AddUObject(this, &UPauseMenuWidget::OnClickedQuitButton);
		this->QuitButton->OnHovered().AddUObject(this, &UPauseMenuWidget::OnHoverQuitButton);
		this->QuitButton->OnUnhovered().AddUObject(this, &UPauseMenuWidget::OnUnhoverQuitButton);
	}
}

void UPauseMenuWidget::NativeDestruct()
{
	Super::NativeDestruct();

	if (this->ReturnToGameButton != nullptr)
	{
		this->ReturnToGameButton->OnClicked().RemoveAll(this);
		this->ReturnToGameButton->OnHovered().RemoveAll(this);
		this->ReturnToGameButton->OnUnhovered().RemoveAll(this);
	}

	if (this->QuitButton != nullptr)
	{
		this->QuitButton->OnClicked().RemoveAll(this);
		this->QuitButton->OnHovered().RemoveAll(this);
		this->QuitButton->OnUnhovered().RemoveAll(this);
	}
}

void UPauseMenuWidget::OnHoverReturnToGameButton()
{
	if (this->ReturnToGameHover != nullptr)
	{
		PlayAnimation(this->ReturnToGameHover, 0, 1, EUMGSequencePlayMode::Forward, HOVER_BUTTON_SPEED);
	}
}

void UPauseMenuWidget::OnHoverQuitButton()
{
	if (this->QuitHover != nullptr)
	{
		PlayAnimation(this->QuitHover, 0, 1, EUMGSequencePlayMode::Forward, HOVER_BUTTON_SPEED);
	}
}

void UPauseMenuWidget::OnUnhoverReturnToGameButton()
{
	if (this->ReturnToGameHover != nullptr)
	{
		PlayAnimation(this->ReturnToGameHover, 0, 1, EUMGSequencePlayMode::Reverse, HOVER_BUTTON_SPEED);
	}
}

void UPauseMenuWidget::OnUnhoverQuitButton()
{
	if (this->QuitHover != nullptr)
	{
		PlayAnimation(this->QuitHover, 0, 1, EUMGSequencePlayMode::Reverse, HOVER_BUTTON_SPEED);
	}
}

void UPauseMenuWidget::OnClickedReturnToGameButton()
{
	DeactivateWidget();
}

void UPauseMenuWidget::OnClickedQuitButton()
{
	UKismetSystemLibrary::QuitGame(this, UGameplayStatics::GetPlayerController(this, 0),
	                               EQuitPreference::Quit, false);
}
