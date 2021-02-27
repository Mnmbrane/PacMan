// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PacManPawn.generated.h"

/**
 * 
 */
UCLASS()
class PACMAN_API APacManPawn : public APawnBase
{
	GENERATED_BODY()

public:
	// Constructor
	APacManPawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	void MoveX(float value);
	void MoveY(float value);

	void Move();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float mMoveSpeed;

	float mXDeltaVal;
	float mYDeltaVal;
};
