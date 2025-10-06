// Copyright Jose Font


#include "Character/AuraEnemy.h"

void AAuraEnemy::HighlightActor()
{
	bHighlighted = true;
	UE_LOG(LogTemp, Warning, TEXT("Highlighted"));

}

void AAuraEnemy::UnHighlightActor()
{
	bHighlighted = false;
	UE_LOG(LogTemp, Warning, TEXT("UNHighlighted"));

}
