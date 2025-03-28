// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GAS_CPP_Gemini : ModuleRules
{
	public GAS_CPP_Gemini(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // Added GameplayAbilities, GameplayTags, and GameplayTasks for GAS support
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput",
            "GameplayAbilities",
            "GameplayTags",
            "GameplayTasks"
        });

        PrivateDependencyModuleNames.AddRange(new string[] { });
        PublicIncludePaths.AddRange(new string[] {
            "GAS_CPP_Gemini/UI"
        });
    }
}
