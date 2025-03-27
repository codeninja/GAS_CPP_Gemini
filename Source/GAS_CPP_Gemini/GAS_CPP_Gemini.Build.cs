// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GAS_CPP_Gemini : ModuleRules
{
	public GAS_CPP_Gemini(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
