// Copyright © 2024 Kdean Games. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacter_Base.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacter_Base
{
	GENERATED_BODY()
	
public:
	AAuraCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	/** Combat Interface */
	virtual int32 GetPlayerLevel() override;
	/** End Combat Interface */

private:
	virtual void InitAbilityActorInfo() override;
};
