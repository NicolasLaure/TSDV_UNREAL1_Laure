// Fill out your copyright notice in the Description page of Project Settings.
#include "NPC_Controller.h"

#include "BehaviorTree/BehaviorTree.h"

void ANPC_Controller::Init(USplineComponent* trackRef)
{
	track = trackRef;
	car = Cast<AWheeledVehiclePawn, APawn>(GetPawn());
	RunBehaviorTree(behaviourTree);
}

void ANPC_Controller::TickAI()
{
	float steering= 0.0f;


	FVector carFwd = car->GetActorForwardVector();
	FVector carRight = car->GetActorRightVector();
	carRight.Normalize();

	FVector carRightSide = car->GetActorLocation() + (carRight * (carWidth / 2));
	FVector carLeftSide = car->GetActorLocation() - (carRight * (carWidth / 2));
	FVector trackPosition = track->FindLocationClosestToWorldLocation(car->GetActorLocation(), ESplineCoordinateSpace::World);
	FVector trackDir = track->FindDirectionClosestToWorldLocation(car->GetActorLocation(), ESplineCoordinateSpace::World);

	float leftDistance = FVector::Dist(trackPosition, carLeftSide);
	float rightDistance = FVector::Dist(trackPosition, carRightSide);

	float straigthness = abs(rightDistance - leftDistance);
	float distanceBetweenSides = FVector::Dist(carRightSide, carLeftSide);
	if (straigthness > minDistance)
		steering = (straigthness / distanceBetweenSides) * steeringForce;
	if (FVector::DotProduct(carFwd, trackPosition - car->GetActorLocation()) < 0)
		steering = 1;

	if (leftDistance < rightDistance)
		steering *= -1;

	float forwardForce = abs(FVector::DotProduct(trackDir, carFwd));

	float accel = FMath::Clamp((forwardForce - accelThreshold) / (1 - accelThreshold), 0.0f, 1.0f);
	float brake = FMath::Clamp(1 - forwardForce / accelThreshold, 0.0f, 1.0f);

	onTick.Broadcast(steering, accel, brake);
}

ANPC_Controller::ANPC_Controller(FObjectInitializer const& ObjectInitializer)
{
}
