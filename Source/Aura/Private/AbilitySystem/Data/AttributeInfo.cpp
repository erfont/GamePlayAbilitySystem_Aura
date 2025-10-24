// Copyright Jose Font


#include "AbilitySystem/Data/AttributeInfo.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& Tag, bool bLogNotFound) const
{
	for (const FAuraAttributeInfo& AttributeInfo : AttributeInformation)
	{
		if (AttributeInfo.AttributeTag.MatchesTagExact(Tag))
		{
			return AttributeInfo;
		}
		
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Attribute Tag [%s] not found on AttributeInfo [%s]"), *Tag.ToString(), *GetNameSafe(this));		
	}

	return FAuraAttributeInfo();
}
