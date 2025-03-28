#include "UI/GeminiAttributeDebugWidget.h"
#include "GAS_CPP_GeminiCharacter.h"
#include "Attributes/GeminiAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Kismet/GameplayStatics.h"

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
