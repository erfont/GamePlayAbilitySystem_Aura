// Copyright Jose Font


#include "AbilitySystem/AuraAbilitySystemComponent.h"

#include "AuraGameplayTags.h"

/* By binding our callbacks below to the corresponding delegates, we can pick any effect application here in the course code */
void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	/* This is binding our method EffectApplied to whenever an Effect is applied to Self */
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);

	/*const FAuraGameplayTags& GameplayTags = FAuraGameplayTags::Get();

	GEngine->AddOnScreenDebugMessage(-1,
		10.f,
		FColor::Orange,
		FString::Printf(TEXT("Tag: %s"), *GameplayTags.Attributes_Secondary_Armor.ToString())
		);*/

	GEngine->AddOnScreenDebugMessage(
	-1,
	5.f,
	FColor::Green,
	FString::Printf(TEXT("Secondary Armor Tag: %s"),
	*AuraGameplayTags::Attributes_Secondary_Armor.GetTag().ToString()));

	GEngine->AddOnScreenDebugMessage(
	-1,
	5.f,
	FColor::Green,
	FString::Printf(TEXT("Secondary Crit Hit Chance Tag: %s"),
	*AuraGameplayTags::Attributes_Secondary_CriticalHitChance.GetTag().ToString()));

	
}

/* This is a callback. Callbacks are to be bound to delegates from the AbilitySystemComponent.h library
 * We make the binding just above, in AbilityActorInfoSet, which is called
 * - by Aura in InitAbilityActorInfo, that's called when possessed
 * - by Enemy in BeginPlay() */
void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTags.Broadcast(TagContainer);
	
	
}
