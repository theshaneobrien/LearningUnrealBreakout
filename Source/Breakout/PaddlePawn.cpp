// Fill out your copyright notice in the Description page of Project Settings.


#include "PaddlePawn.h"
#include "Camera/CameraComponent.h"

// Sets default values (Not Awake)
APaddlePawn::APaddlePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set this pawn to be controlled by the lowest number player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	//Create dummy root component we can attach things to.
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	//Create a visible object
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	//Attach our visible object to our root component. Offset and rotate the camera.
	OurVisibleComponent->SetupAttachment(RootComponent);
	this->Tags.AddUnique("PaddlePawn");
}

// Called when the game starts or when spawned (Start)
void APaddlePawn::BeginPlay()
{
	Super::BeginPlay();
	//GameMode=Cast<ABreakoutGameModeBase>(GetWorld()->GetAuthGameMode());
}

// Called every frame (Update)
void APaddlePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentPos = GetActorLocation();
	//UE_LOG(LogTemp, Warning, TEXT("The float value is: %f"), CurrentPos.X);

	if(!CurrentVelocity.IsZero())
	{
		FVector NewLocation = CurrentPos + (CurrentVelocity*DeltaTime);
		SetActorLocation(NewLocation);
	}
}

// Called to bind functionality to input
void APaddlePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//Bind our axis inputs
	InputComponent->BindAxis("MoveX", this, &APaddlePawn::MoveXAxis);
	//Bind our action controls
	InputComponent->BindAction("ReleaseBall", IE_Pressed, this, &APaddlePawn::SpawnBall);
	//InputComponent->BindAction("Shoot", IE_Pressed, this, &APaddlePawn::Shoot);
}

void APaddlePawn::MoveXAxis(float AxisValue)
{
	CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 1000.0f;
}

void APaddlePawn::SpawnBall()
{
	
}

void APaddlePawn::Shoot()
{
	//Shoot if we have the appropriate power-up
}


