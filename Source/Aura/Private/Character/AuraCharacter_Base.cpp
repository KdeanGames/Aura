// Copyright © 2024 Kdean Games. All Rights Reserved.


#include "Character/AuraCharacter_Base.h"

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
