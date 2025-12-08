// Copyright Jose Font


#include "AI/AuraAIController.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

AAuraAIController::AAuraAIController()
{
	Blackboard = CreateDefaultSubobject<UBlackboardComponent>("Blackboard Component"); // Blackboard exists already in the parent class AIController
	
	BehaviorTreeComp = CreateDefaultSubobject<UBehaviorTreeComponent>("Behavior Tree");
	check(BehaviorTreeComp);

	
}
