// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UI_MVVM_Example : ModuleRules
{
	public UI_MVVM_Example(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"CommonUI",
			"CommonInput",
			"Engine", 
			"InputCore", 
			"EnhancedInput", 
			"ModelViewViewModel",
			"UMG",
			"Slate",
			"SlateCore"
		});
	}
}