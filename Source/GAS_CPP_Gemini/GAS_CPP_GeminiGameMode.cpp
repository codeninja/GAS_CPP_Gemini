// Copyright Epic Games, Inc. All Rights Reserved.

#include "GAS_CPP_GeminiGameMode.h"
#include "GAS_CPP_GeminiCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGAS_CPP_GeminiGameMode::AGAS_CPP_GeminiGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
