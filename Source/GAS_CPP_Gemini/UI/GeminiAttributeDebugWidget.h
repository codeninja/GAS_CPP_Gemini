#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GeminiAttributeDebugWidget.generated.h"

class AGAS_CPP_GeminiCharacter;

UCLASS()
class GAS_CPP_GEMINI_API UGeminiAttributeDebugWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	FString GetHealth() const;

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	FString GetPower() const;

protected:
	AGAS_CPP_GeminiCharacter* GetGeminiCharacter() const;
};
