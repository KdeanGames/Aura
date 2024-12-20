// Copyright © 2024 Kdean Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterClassInfo.generated.h"

class UGameplayAbility;
class UGameplayEffect;

UENUM(BlueprintType)
enum class ECharacterClass : uint8
{
	Elementalist,
	Warrior,
	Ranger
};

USTRUCT(BlueprintType)
struct FCharacterClassDefaultInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "Character Class|Primary Class Defaults")
	TSubclassOf<UGameplayEffect> PrimaryAttributes;
};

/**
 * 
 */
UCLASS()
class AURA_API UCharacterClassInfo : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly, Category = "Character Class|Class Defaults")
	TMap<ECharacterClass, FCharacterClassDefaultInfo> CharacterClassInformation;

	UPROPERTY(EditDefaultsOnly, Category = "Character Class|Secondary Class Defaults")
	TSubclassOf<UGameplayEffect> SecondaryAttributes;

	UPROPERTY(EditDefaultsOnly, Category = "Character Class|Vital Class Defaults")
	TSubclassOf<UGameplayEffect> VitalAttributes;

	UPROPERTY(EditDefaultsOnly, Category = "Character Class|Ability Class Defaults")
	TArray<TSubclassOf<UGameplayAbility>> CommonAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "Character Class|Damage")
	TObjectPtr<UCurveTable> DamageCalculationCoefficients;

	FCharacterClassDefaultInfo GetClassDefaultInfo(ECharacterClass CharacterClass);

};
