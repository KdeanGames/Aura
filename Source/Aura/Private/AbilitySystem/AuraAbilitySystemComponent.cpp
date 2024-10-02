// Copyright © 2024 Kdean Games. All Rights Reserved.


#include "AbilitySystem/AuraAbilitySystemComponent.h"

void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagCpntainer;
	EffectSpec.GetAllAssetTags(TagCpntainer);
	for (const FGameplayTag& Tag : TagCpntainer)
	{
		// TODO: Broadcast tag to Widget Controller
		const FString Msg = FString::Printf(TEXT("GE Tag : %s"), *Tag.ToString());
		GEngine->AddOnScreenDebugMessage(-1, 8.0f, FColor::Blue, Msg);
	}
}
