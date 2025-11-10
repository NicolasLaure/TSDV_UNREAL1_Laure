// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class TSDV_UNREAL1_LaureTarget : TargetRules
{
	public TSDV_UNREAL1_LaureTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "TSDV_UNREAL1_Laure" } );
	}
}
