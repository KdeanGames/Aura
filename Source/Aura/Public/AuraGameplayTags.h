// Copyright © 2024 Kdean Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 *	AuraGameplayTags
 * 
 *	Singleton containing native Gameplay tags
 */
struct FAuraGameplayTags
{

public:

	static const FAuraGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeGameplayTags();

	// Gameplay Tags
	FGameplayTag Attributes_Secondary_Armor;

protected:


private:

	static FAuraGameplayTags GameplayTags;
};