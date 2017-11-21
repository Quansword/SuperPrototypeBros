// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class SuperPrototypeBrosTarget : TargetRules
{
	public SuperPrototypeBrosTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.Add("SuperPrototypeBros");
	}
}
