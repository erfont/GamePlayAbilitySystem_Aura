// Copyright Jose Font


#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

namespace AuraGameplayTags
{
	// Primary
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Primary_Strength, "Attributes.Primary.Strength", "Increases Physical Damage");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Primary_Intelligence, "Attributes.Primary.Intelligence", "Increases Magical Damage");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Primary_Resilience, "Attributes.Primary.Resilience", "Increases Armor and Armor Penetration");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Primary_Vigor, "Attributes.Primary.Vigor", "Increases Health");
 
	// Secondary
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Secondary_Armor, "Attributes.Secondary.Armor", "Reduces damage taken, improves Block Chance");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Secondary_ArmorPenetration, "Attributes.Secondary.ArmorPenetration", "");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Secondary_BlockChance, "Attributes.Secondary.BlockChance", "");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Secondary_CriticalHitChance, "Attributes.Secondary.CriticalHitChance", "");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Secondary_CriticalHitDamage, "Attributes.Secondary.CriticalHitDamage", "");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Secondary_CriticalHitResistance, "Attributes.Secondary.CriticalHitResistance", "");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Secondary_HealthRegeneration, "Attributes.Secondary.HealthRegeneration", "");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Secondary_ManaRegeneration, "Attributes.Secondary.ManaRegeneration", "");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Secondary_MaxHealth, "Attributes.Secondary.MaxHealth", "");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Secondary_MaxMana, "Attributes.Secondary.MaxMana", "");
 
	// Vitals
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Vitals_Health, "Attributes.Vitals.Health", "Actual Health Points");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Attributes_Vitals_Mana, "Attributes.Vitals.Mana", "Actual Mana Points");

	// Input Tags
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_LMB, "InputTag.LMB", "Left Mouse Button");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_RMB, "InputTag.RMB", "Right Mouse Button");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_1, "InputTag.1", "1");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_2, "InputTag.2", "2");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_3, "InputTag.3", "3");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(InputTag_4, "InputTag.4", "4");

	// Damage Tags
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Damage, "Damage", "Damage");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Damage_Fire, "Damage.Fire", "Fire Damage Type");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Effect_HitReact, "Effects.Hit React", "Hit React");

}


