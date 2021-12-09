// Fill out your copyright notice in the Description page of Project Settings.


#include "BallActor.h"
#include "BreakoutGameModeBase.h"
#include "PaddlePawn.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABallActor::ABallActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create dummy root component we can attach things too
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	//Create visible object
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	//Attach our visible object to our root component. Offset and rotate the camera.
	OurVisibleComponent->SetupAttachment(RootComponent);
	this->Tags.AddUnique(TEXT("Ball"));
	BallOverPaddlePos = FVector(0.0f,0.0f,75.0f);
}

// Called when the game starts or when spawned
void ABallActor::BeginPlay()
{
	Super::BeginPlay();
	//Initialize our game mode variable
	GameMode=Cast<ABreakoutGameModeBase>(GetWorld()->GetAuthGameMode());
	CurrentPos=GetActorLocation();
}

// Called every frame
void ABallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if(GameMode->bBallInPlay)
	{
		//FVector NewLocation = CurrentPos + (CurrentVelocity*DeltaTime);
		//SetActorLocation(NewLocation);
		
		UE_LOG(LogTemp, Warning, TEXT("Ball in play"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Ball not in play"));
		//need to check if nullptr, otherwise Unreal will crash
		if(GameMode->PlayerPaddle != nullptr)
		{
			FVector NewLocation = BallOverPaddlePos + GameMode->PlayerPaddle->GetActorLocation();
			SetActorLocation(NewLocation);
			UE_LOG(LogTemp, Warning, TEXT("The float value is: %f"), CurrentPos.X);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Paddle was null"));
		}
	}

}

