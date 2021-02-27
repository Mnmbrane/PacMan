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
   PlayerInputComponent->BindAxis("Move Up",    this, &APacManPawn::MoveUp);
   PlayerInputComponent->BindAxis("Move Down",  this, &APacManPawn::MoveDown);
   PlayerInputComponent->BindAxis("Move Left",  this, &APacManPawn::MoveLeft);
   PlayerInputComponent->BindAxis("Move Right", this, &APacManPawn::MoveRight);

}

void APacManPawn::MoveUp(float value)
{
   // if value is not 0, then start moving up
   mMoveUpVector = FVector(value * mMoveSpeed * GetWorld()->DeltaTimeSeconds, 0, 0);
}

void APacManPawn::MoveDown(float value) 
{
   mMoveDownVector = FVector(-1.0 * value * mMoveSpeed * GetWorld()->DeltaTimeSeconds, 0, 0);
}

void APacManPawn::MoveLeft(float value) 
{
   mMoveLeftVector = FVector(0, -1.0 * value * mMoveSpeed * GetWorld()->DeltaTimeSeconds, 0);
}

void APacManPawn::MoveRight(float value) 
{
   mMoveRightVector = FVector(0, value * mMoveSpeed * GetWorld()->DeltaTimeSeconds, 0);
}

void APacManPawn::Move()
{
   // Add all vectors togehter
   FVector lMovement = mMoveUpVector + mMoveDownVector + mMoveLeftVector + mMoveRightVector;
   //UE_LOG(LogTemp, Warning, TEXT("Moving (%f, %f, %f)"), mMoveDirection.X, mMoveDirection.Y, mMoveDirection.Z);

   AddActorLocalOffset(lMovement, true);
}