// Copyright Jose Font


#include "AbilitySystem/Abilities/AuraProjectileSpell.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "Actor/AuraProjectile.h"
#include "Interaction/CombatInterface.h"
#include "Aura/Public/AuraGameplayTags.h"
#include "Kismet/GameplayStatics.h"
#include "Player/AuraPlayerState.h"

void UAuraProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                           const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                           const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);


	
	
	
}

void UAuraProjectileSpell::SpawnProjectile(const FVector& ProjectileTargetlocation)
{
	
	const bool bIsServer = GetAvatarActorFromActorInfo()->HasAuthority();

	if (!bIsServer) return;

	const FVector SocketLocation = ICombatInterface::Execute_GetCombatSocketLocation(GetAvatarActorFromActorInfo());

	FRotator Rotation = (ProjectileTargetlocation - SocketLocation).Rotation();
	Rotation.Pitch = 0.0f; // Fly straight, no gravity for now

	FTransform SpawnTransform;
	SpawnTransform.SetLocation(SocketLocation);
	SpawnTransform.SetRotation(Rotation.Quaternion());

	// TODO set the projectile rotation
	
	AAuraProjectile* Projectile = GetWorld()->SpawnActorDeferred<AAuraProjectile>(
		ProjectileClass,
		SpawnTransform,
		GetOwningActorFromActorInfo(),
		Cast<APawn>(GetOwningActorFromActorInfo()),
		ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
	
	// Setting a Damage SpecHandle out of a GameplayEffect class created for Damage
	UAbilitySystemComponent* SourceASC =  UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetAvatarActorFromActorInfo());

	// Adding the below to the EffectContextHandle to show what you can fill it in with
	FGameplayEffectContextHandle EffectContextHandle = SourceASC->MakeEffectContext();
	EffectContextHandle.SetAbility(this);
	EffectContextHandle.AddSourceObject(Projectile);
	TArray<TWeakObjectPtr<AActor>> Actors;
	Actors.Add(Projectile);
	EffectContextHandle.AddActors(Actors);
	FHitResult HitResult;
	HitResult.Location = ProjectileTargetlocation;
	EffectContextHandle.AddHitResult(HitResult);

	// Setting the EffectContextHandle to the DamageEffectClass
	FGameplayEffectSpecHandle SpecHandle = SourceASC->MakeOutgoingSpec(DamageEffectClass, GetAbilityLevel(), EffectContextHandle);

	for (auto& Pair : DamageTypes)
	{
		const float ScaledDamage = Pair.Value.GetValueAtLevel(GetAbilityLevel());
		UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(SpecHandle, Pair.Key, ScaledDamage); // This line assigns GE_Damage to the Magnitude for that damage, and to the SpecHandle that packs the whole GE
	}

	// Setting the actual damage value based on Aura's player level (custom José)
	/*APlayerController* PlayerController = UGameplayStatics::GetPlayerController(SourceASC->GetAvatarActor(), 0);
	const int AuraPlayerLevel = PlayerController->GetPlayerState<AAuraPlayerState>()->GetPlayerLevel();
	const float ScaledDamage = Damage.GetValueAtLevel(AuraPlayerLevel);*/
	
	Projectile->DamageEffectSpecHandle = SpecHandle;
	
	Projectile->FinishSpawning(SpawnTransform);
	
	/*if (ICombatInterface* CombatInterface = Cast<ICombatInterface>(GetAvatarActorFromActorInfo()))
	{
		const FVector SocketLocation = CombatInterface->GetCombatSocketLocation_Implementation(); // Also works but not the solution shown
	}*/
}
