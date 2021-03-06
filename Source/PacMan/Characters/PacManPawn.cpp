// Fill out your copyright notice in the Description page of Project Settings.


#include "PacManPawn.h"

APacManPawn::APacManPawn() :
   mMoveSpeed(600.0f)
{

}

// Called when the game starts or when spawned
void APacManPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APacManPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
   Move();
}

// Called to bind functionality to input
void APacManPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
   PlayerInputComponent->BindAxis("Move X",  this, &APacManPawn::MoveX);
   PlayerInputComponent->BindAxis("Move Y",  this, &APacManPawn::MoveY);

}

void APacManPawn::MoveX(float value)
{
   // Only calculate Vector if there was a change
   if( (mXDeltaVal == 0.0f && value != 0.0f) || 
       (mXDeltaVal != 0.0f && value == 0.0f) )
   {
      mXDeltaVal = value * mMoveSpeed * GetWorld()->DeltaTimeSeconds;
   }
}

void APacManPawn::MoveY(float value)
{
   // Only calculate Vector if there was a change
   if( (mYDeltaVal == 0.0f && value != 0.0f) || 
       (mYDeltaVal != 0.0f && value == 0.0f) )
   {
      mYDeltaVal = value * mMoveSpeed * GetWorld()->DeltaTimeSeconds;
   }
}

void APacManPawn::Move()
{
   // Get movement vector
   FVector lMovementVector = FVector(mXDeltaVal, mYDeltaVal, 0);
   //UE_LOG(LogTemp, Warning, TEXT("Moving (%f, %f, %f)"), mMoveDirection.X, mMoveDirection.Y, mMoveDirection.Z);

   AddActorLocalOffset(lMovementVector, true);
}