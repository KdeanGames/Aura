// Copyright © 2024 Kdean Games. All Rights Reserved.


#include "Character/AuraCharacter_Base.h"
#include "AbilitySystemComponent.h"

// Sets default values
AAuraCharacter_Base::AAuraCharacter_Base()
{
 	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AAuraCharacter_Base::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAuraCharacter_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAuraCharacter_Base::InitAbilityActorInfo()
{
}

void AAuraCharacter_Base::InitializePrimaryAttributes() const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(DefaultPrimaryAttributes);

	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(DefaultPrimaryAttributes, 1.0f, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}
