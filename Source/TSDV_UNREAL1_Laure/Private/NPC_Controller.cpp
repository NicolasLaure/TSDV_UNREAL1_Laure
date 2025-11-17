// Fill out your copyright notice in the Description page of Project Settings.
#include "NPC_Controller.h"

void ANPC_Controller::Init(USplineComponent* trackRef)
{
	track = trackRef;
	car = Cast<AWheeledVehiclePawn, APawn>(GetPawn());
}

void ANPC_Controller::TickAI(float& accel, float& brake, float& steering)
{
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

	accel = FMath::Clamp((forwardForce - accelThreshold) / (1 - accelThreshold), 0.0f, 1.0f);
	brake = FMath::Clamp(1 - forwardForce / accelThreshold, 0.0f, 1.0f);
}

ANPC_Controller::ANPC_Controller(FObjectInitializer const& ObjectInitializer)
{
}
