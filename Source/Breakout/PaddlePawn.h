// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BreakoutGameModeBase.h"
#include "GameFramework/Pawn.h"
#include "PaddlePawn.generated.h"

UCLASS()
class BREAKOUT_API APaddlePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APaddlePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY (EditAnywhere)
	USceneComponent* OurVisibleComponent;

	//Input Functions
	void MoveXAxis(float AxisValue);
	void SpawnBall();
	void Shoot();

	//Input Variables
	FVector CurrentVelocity;

	//Position Variables
	float HeightPos;
	float MinXPos;
	float MaxXPos;
	FVector CurrentPos;
private:
	//ABreakoutGameModeBase* GameMode;

};
