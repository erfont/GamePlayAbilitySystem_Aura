// Copyright Jose Font

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "NativeGameplayTags.h"
#include "AuraGameplayTags.generated.h"


/**
 * AuraGameplayTags
 *
 * Discarded course's Singleton implementation and used recommended by comments using UE's macros with functionality to declare GP tags
 */

namespace AuraGameplayTags

{
	// Primary
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attributes_Primary_Strength);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attributes_Primary_Intelligence);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attributes_Primary_Resilience);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attributes_Primary_Vigor);
 
	// Secondary
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attributes_Secondary_Armor);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attributes_Secondary_ArmorPenetration);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attributes_Secondary_BlockChance);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attributes_Secondary_CriticalHitChance);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attributes_Secondary_CriticalHitDamage);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attributes_Secondary_CriticalHitResistance);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attributes_Secondary_HealthRegeneration);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attributes_Secondary_ManaRegeneration);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attributes_Secondary_MaxHealth);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attributes_Secondary_MaxMana);
 
	// Vitals
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attributes_Vitals_Health);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attributes_Vitals_Mana);

	// Resistances
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attributes_Resistance);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attributes_Resistance_Fire);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attributes_Resistance_Lightning);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attributes_Resistance_Arcane);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attributes_Resistance_Physical);

	// Inputs
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_LMB);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_RMB);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_1);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_2);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_3);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_4);

	// Damage
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Damage);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Damage_Fire);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Damage_Lightning);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Damage_Arcane);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Damage_Physical);
	
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Effect_HitReact);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Montage_Attack_Weapon);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Montage_Attack_RightHand);
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Montage_Attack_LeftHand);


	// Abilities
	UE_DECLARE_GAMEPLAY_TAG_EXTERN(Abilities_Attack);

}

UCLASS()
class AURA_API UAuraGameplayTags : public UGameInstanceSubsystem 
{
	GENERATED_BODY()
public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;
	
	TMap<FGameplayTag, FGameplayTag> DamageTypesToResistance;
 
	void InitializeDamageTypeMappings();
 
private:
	
};
