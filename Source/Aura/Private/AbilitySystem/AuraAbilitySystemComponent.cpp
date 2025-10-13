// Copyright Jose Font


#include "AbilitySystem/AuraAbilitySystemComponent.h"

/* By binding our callbacks below to the corresponding delegates, we can pick any effect application here in the course code */
void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	/* This is binding our method EffectApplied to whenever an Effect is applied to Self */
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
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
	for (const FGameplayTag& Tag : TagContainer)
	{
		//TODO broadcast the tag to the widget controller
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString(Tag.ToString()));
	}
}
