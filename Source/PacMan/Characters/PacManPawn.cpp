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
   // if value is not 0, then start moving up
   mMoveXVector = FVector(value * mMoveSpeed * GetWorld()->DeltaTimeSeconds, 0, 0);
}

void APacManPawn::MoveY(float value)
{
   mMoveYVector = FVector(0, value * mMoveSpeed * GetWorld()->DeltaTimeSeconds, 0);
}

void APacManPawn::Move()
{
   // Add all vectors togehter
   FVector lMovement = mMoveXVector + mMoveYVector;
   //UE_LOG(LogTemp, Warning, TEXT("Moving (%f, %f, %f)"), mMoveDirection.X, mMoveDirection.Y, mMoveDirection.Z);

   AddActorLocalOffset(lMovement, true);
}