// Copyright Jose Font


#include "Player/AuraPlayerState.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"


/*AAuraPlayerState is typically instantiated in the game mode or player controller. 

In the GameMode: You would typically set the PlayerState class in your custom game mode, usually in the constructor, with a line like PlayerStateClass = AAuraPlayerState::StaticClass();.
Possession: When a player controller possesses a pawn, the PlayerController will automatically create an instance of the PlayerState if it's not already available.*/

AAuraPlayerState::AAuraPlayerState()
{
	SetNetUpdateFrequency(100.f); // How often the server will try to update changes

	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystem_Component");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed); //Mixed for main character in multiplayer

	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
