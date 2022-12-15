// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryCharacter.h"

// Sets default values
AInventoryCharacter::AInventoryCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	InventoryComponent =
		CreateDefaultSubobject<UInventoryComponent>("Inventory");
	InventoryManagerComponent =
		CreateDefaultSubobject<UInventoryManagerComponent>("InventoryManager");
}
void AInventoryCharacter::BeginPlay()
{
	Super::BeginPlay();
	InventoryManagerComponent->Init(InventoryComponent);
}

// Called every frame
void AInventoryCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AInventoryCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

