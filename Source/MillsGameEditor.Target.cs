// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class MillsGameEditorTarget : TargetRules
{
	public MillsGameEditorTarget( TargetInfo targetInfo) : base(targetInfo)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V3;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;
		ExtraModuleNames.Add("MillsGame");
	}
}
