// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BreakoutGameModeBase.generated.h"

//We need to forward declare these classes to avoid circular dependancy hell.
//However we also need to #include the actual class h files in the GameMode cpp file otherwise Unreal will complain
class APaddlePawn;
class ABallActor;

UCLASS()
class BREAKOUT_API ABreakoutGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	ABreakoutGameModeBase();
	bool bBallInPlay;
	APaddlePawn* PlayerPaddle;
	ABallActor* PlayerBall;
};
