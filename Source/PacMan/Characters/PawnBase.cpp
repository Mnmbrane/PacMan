// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBase.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create capsule component for the collision
	mCapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Colider"));
	// Set it as the root component
	RootComponent = mCapsuleComp;

	
	mBaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	mBaseMesh->SetupAttachment(mCapsuleComp);
}