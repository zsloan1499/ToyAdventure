


#include "ToyAdventure/Player/PlayerCharacter.h"
#include "Camera/CameraComponent.h"

// Sets default values
//Called when unreal engine starts
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Makes the player camera and names it
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));

	//sets up the camera to be attached to the root component(player = root component)
	Camera->SetupAttachment(RootComponent);

	Camera->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
// Called when the game starts
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
//Update() in other engines
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//we dont need to jump but still here just in case we ever want it
	//PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);

	//when pressed will call move forward function

	PlayerInputComponent->BindAxis("Move_Forward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Move_Right", this, &APlayerCharacter::MoveRight);
}

void APlayerCharacter::MoveForward(float InputValue)
{
	FVector ForwardDirection = GetActorForwardVector();
	AddMovementInput(ForwardDirection, InputValue);

}

void APlayerCharacter::MoveRight(float InputValue)
{
	FVector RightDirection = GetActorRightVector();
	AddMovementInput(RightDirection, InputValue);


}

