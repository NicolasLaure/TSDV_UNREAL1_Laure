// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveTask.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "NPC_Controller.h"

EBTNodeResult::Type UMoveTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (ANPC_Controller* controller = Cast<ANPC_Controller>(OwnerComp.GetAIOwner()))
	{
		controller->TickAI();
	}
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}

UMoveTask::UMoveTask(FObjectInitializer const& objInit)
{
}
