// Copyright © 2024 Kdean Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AuraAbilitySystemComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FEffectsAssetTags, const FGameplayTagContainer& /*AssetTags*/);


/**
 * 
 */
UCLASS()
class AURA_API UAuraAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:

	void AbilityActorInfoSet();

	FEffectsAssetTags EffectAssetTags;

protected:

	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, 
		const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);
};
