#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GeminiAttributeDebugWidget.generated.h"

class AGAS_CPP_GeminiCharacter;

UCLASS(BlueprintType, Blueprintable)
class GAS_CPP_GEMINI_API UGeminiAttributeDebugWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Attributes")
	FString GetHealth() const;

	UFUNCTION(BlueprintPure, Category = "Attributes")
	FString GetPower() const;

protected:
	virtual void NativeConstruct() override;
	AGAS_CPP_GeminiCharacter* GetGeminiCharacter() const;
};
