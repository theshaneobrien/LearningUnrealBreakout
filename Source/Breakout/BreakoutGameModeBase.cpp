// Copyright Epic Games, Inc. All Rights Reserved.


#include "BreakoutGameModeBase.h"

#include "EngineUtils.h"
#include "PaddlePawn.h"
#include "BallActor.h"
#include "Kismet/GameplayStatics.h"

ABreakoutGameModeBase::ABreakoutGameModeBase()
{
	bBallInPlay = false;
}

void ABreakoutGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	//We iterate through all actors of a type in the scene to find our tagged objects... there has to be a better way.
	for (TActorIterator<APaddlePawn> It(GetWorld()); It; ++It)
	{
		APaddlePawn* Actor = *It;
		if (Actor!=nullptr)
		{
			//Once we've found our matching Actor we cast it's type and store the reference
			PlayerPaddle = Actor;
			UE_LOG(LogTemp, Warning, TEXT("Found Paddle"));
		}
	}
	for (TActorIterator<ABallActor> It(GetWorld()); It; ++It)
	{
		ABallActor* Actor = *It;
		if (Actor!=nullptr)
		{
			//Once we've found our matching Actor we cast it's type and store the reference
			PlayerBall = Actor;
			UE_LOG(LogTemp, Warning, TEXT("Found Ball"));
		}
	}
}
