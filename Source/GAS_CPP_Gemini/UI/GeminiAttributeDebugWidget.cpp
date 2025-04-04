#include "GeminiAttributeDebugWidget.h"
#include "GAS_CPP_Gemini/GAS_CPP_GeminiCharacter.h"
#include "../Attributes/GeminiAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Blueprint/WidgetTree.h"

void UGeminiAttributeDebugWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UE_LOG(LogTemp, Warning, TEXT("UGeminiAttributeDebugWidget::NativeConstruct called"));

	UVerticalBox* RootBox = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("RootBox"));
	WidgetTree->RootWidget = RootBox;

	HealthText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("HealthText"));
	HealthText->SetText(FText::FromString(GetHealth()));
	HealthText->SetColorAndOpacity(FSlateColor(FLinearColor::Red));
	HealthText->Font.Size = 24;
	RootBox->AddChildToVerticalBox(HealthText);

	PowerText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("PowerText"));
	PowerText->SetText(FText::FromString(GetPower()));
	PowerText->SetColorAndOpacity(FSlateColor(FLinearColor::Blue));
	PowerText->Font.Size = 24;
	RootBox->AddChildToVerticalBox(PowerText);
}

AGAS_CPP_GeminiCharacter* UGeminiAttributeDebugWidget::GetGeminiCharacter() const
{
	return Cast<AGAS_CPP_GeminiCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

FString UGeminiAttributeDebugWidget::GetHealth() const
{
	if (const AGAS_CPP_GeminiCharacter* Char = GetGeminiCharacter())
	{
		if (const UGeminiAttributeSet* Attr = Char->GetAttributeSet())
		{
			return FString::Printf(TEXT("Health: %.1f"), Attr->GetHealth());
		}
	}
	return TEXT("Health: N/A");
}

FString UGeminiAttributeDebugWidget::GetPower() const
{
	if (const AGAS_CPP_GeminiCharacter* Char = GetGeminiCharacter())
	{
		if (const UGeminiAttributeSet* Attr = Char->GetAttributeSet())
		{
			return FString::Printf(TEXT("Power: %.1f"), Attr->GetPower());
		}
	}
	return TEXT("Power: N/A");
}

FString UGeminiAttributeDebugWidget::GetSpirit() const
{
	if (const AGAS_CPP_GeminiCharacter* Char = GetGeminiCharacter())
	{
		if (const UGeminiAttributeSet* Attr = Char->GetAttributeSet())
		{
			return FString::Printf(TEXT("Spirit: %.1f"), Attr->GetSpirit());
		}
	}
	return TEXT("Spirit: N/A");
}
