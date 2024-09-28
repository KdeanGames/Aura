// Copyright © 2024 Kdean Games. All Rights Reserved.


#include "Actors/AuraEffectActor.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

// Sets default values
AAuraEffectActor::AAuraEffectActor()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateOptionalDefaultSubobject<USceneComponent>("SceneRoot"));

}

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
	

}

void AAuraEffectActor::ApplyEffectToTaget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);

	if (TargetASC == nullptr) return;

	check(GameplayEffectClass);
	
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	
	const FGameplayEffectSpecHandle EffectSpecHandle = 
		TargetASC->MakeOutgoingSpec(GameplayEffectClass, 1.0f, EffectContextHandle);

	TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}
