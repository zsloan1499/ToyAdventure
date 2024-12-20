

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class TOYADVENTURE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	//can be called outside the player class
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	//Only the player needs the camera component
protected: 
	// class and asterisks mean it is a component
	// makes a camera for the player to be able to access in the cpp file
	// basically just says that camera exists
	//allows the thing under to be edited anywhere
	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera;


	void MoveForward(float InputValue);
	void MoveRight(float InputValue);
};
