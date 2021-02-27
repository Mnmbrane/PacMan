// Fill out your copyright notice in the Description page of Project Settings.


#include "PacManPawn.h"

APacManPawn::APacManPawn() :
   mMoveSpeed(500.0f)
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
   PlayerInputComponent->BindAction("Move Up",     IE_Pressed, this, &APacManPawn::MoveUp);
   PlayerInputComponent->BindAction("Move Down",   IE_Pressed, this, &APacManPawn::MoveDown);
   PlayerInputComponent->BindAction("Move Left",   IE_Pressed, this, &APacManPawn::MoveLeft);
   PlayerInputComponent->BindAction("Move Right",  IE_Pressed, this, &APacManPawn::MoveRight);

   PlayerInputComponent->BindAction("Move Up",     IE_Released, this, &APacManPawn::MoveUpStop);
   PlayerInputComponent->BindAction("Move Down",   IE_Released, this, &APacManPawn::MoveDownStop);
   PlayerInputComponent->BindAction("Move Left",   IE_Released, this, &APacManPawn::MoveLeftStop);
   PlayerInputComponent->BindAction("Move Right",  IE_Released, this, &APacManPawn::MoveRightStop);

}

void APacManPawn::MoveUp()
{
   mMoveDirection.X += (mMoveSpeed * GetWorld()->DeltaTimeSeconds);
}

void APacManPawn::MoveDown() 
{
   mMoveDirection.X -= (mMoveSpeed * GetWorld()->DeltaTimeSeconds);
}

void APacManPawn::MoveLeft() 
{
   mMoveDirection.Y -= (mMoveSpeed * GetWorld()->DeltaTimeSeconds);
}

void APacManPawn::MoveRight() 
{
   mMoveDirection.Y += (mMoveSpeed * GetWorld()->DeltaTimeSeconds);
}

void APacManPawn::MoveUpStop() 
{
   mMoveDirection.X -= (mMoveSpeed * GetWorld()->DeltaTimeSeconds);
}

void APacManPawn::MoveDownStop() 
{
   mMoveDirection.X += (mMoveSpeed * GetWorld()->DeltaTimeSeconds);
}

void APacManPawn::MoveLeftStop() 
{
   mMoveDirection.Y += (mMoveSpeed * GetWorld()->DeltaTimeSeconds);
}

void APacManPawn::MoveRightStop() 
{
   mMoveDirection.Y -= (mMoveSpeed * GetWorld()->DeltaTimeSeconds);
}



void APacManPawn::Move()
{
   
   //UE_LOG(LogTemp, Warning, TEXT("Moving (%f, %f, %f)"), mMoveDirection.X, mMoveDirection.Y, mMoveDirection.Z);
   AddActorLocalOffset(mMoveDirection, true);
}