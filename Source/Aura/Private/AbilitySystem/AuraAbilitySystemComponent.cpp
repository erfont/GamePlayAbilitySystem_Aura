// Copyright Jose Font


#include "AbilitySystem/AuraAbilitySystemComponent.h"

#include "AuraGameplayTags.h"
#include "AbilitySystem/Abilities/AuraGameplayAbility.h"

/* By binding our callbacks below to the corresponding delegates, we can pick any effect application here in the course code */
void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	/* This is binding our method EffectApplied to whenever an Effect is applied to Self */
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::ClientEffectApplied);

	/*const FAuraGameplayTags& GameplayTags = FAuraGameplayTags::Get();

	GEngine->AddOnScreenDebugMessage(-1,
		10.f,
		FColor::Orange,
		FString::Printf(TEXT("Tag: %s"), *GameplayTags.Attributes_Secondary_Armor.ToString())
		);*/

	/*GEngine->AddOnScreenDebugMessage(
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
	*AuraGameplayTags::Attributes_Secondary_CriticalHitChance.GetTag().ToString()));*/

	
}

void UAuraAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
{
	for (const TSubclassOf<UGameplayAbility> AbilityClass : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
		if (const UAuraGameplayAbility* AuraAbility = Cast<UAuraGameplayAbility>(AbilitySpec.Ability))
		{
			// AbilitySpec.DynamicAbilityTags.AddTag(AuraAbility->StartupInputTag); // DEPRECATED VERSION: 

			 // Not deprecated version
			FGameplayTagContainer& DynamicTags = AbilitySpec.GetDynamicSpecSourceTags();
			DynamicTags.AddTag(AuraAbility->StartupInputTag);
			
			GiveAbility(AbilitySpec);
		}


	}
}

void UAuraAbilitySystemComponent::AbilityInputTagHeld(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid()) return;

	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		// Not deprecated version
		FGameplayTagContainer& DynamicTags = AbilitySpec.GetDynamicSpecSourceTags();
		if (DynamicTags.HasTagExact(InputTag))
		// if (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag)) // Deprecated version
		{
			AbilitySpecInputPressed(AbilitySpec); // This tells the ability that the input is being pressed
			if (!AbilitySpec.IsActive())
			{
				TryActivateAbility(AbilitySpec.Handle);
			}
		}
	}
}

void UAuraAbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid()) return;

	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		// Not deprecated version
		FGameplayTagContainer& DynamicTags = AbilitySpec.GetDynamicSpecSourceTags();
		if (DynamicTags.HasTagExact(InputTag))
		// if (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag)) // Deprecated version
		{
			AbilitySpecInputReleased(AbilitySpec); // This tells the ability that the input is being released

		}
	}
}

/* This is a callback. Callbacks are to be bound to delegates from the AbilitySystemComponent.h library
 * We make the binding just above, in AbilityActorInfoSet, which is called
 * - by Aura in InitAbilityActorInfo, that's called when possessed
 * - by Enemy in BeginPlay() */
void UAuraAbilitySystemComponent::ClientEffectApplied_Implementation(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTags.Broadcast(TagContainer);
	
	
}
