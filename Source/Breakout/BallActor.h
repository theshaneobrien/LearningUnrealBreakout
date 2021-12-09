// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BreakoutGameModeBase.h"
#include "GameFramework/Actor.h"
#include "BallActor.generated.h"

UCLASS()
class BREAKOUT_API ABallActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY (EditAnywhere)
	USceneComponent* OurVisibleComponent;

private:
	ABreakoutGameModeBase* GameMode;
	FVector BallOverPaddlePos;
	FVector CurrentVelocity;
	FVector CurrentPos;
};
