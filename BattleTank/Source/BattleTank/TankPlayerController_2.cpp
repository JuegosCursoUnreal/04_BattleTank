// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController_2.h"

void ATankPlayerController_2::BeginPlay() 
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play"));
	auto TanquePoseido = GetControlledTank()->GetName();
	if (GetPawn())
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Pawn Obtenido: %s"), *TanquePoseido);
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Player Pawn NO Obtenido"));
}

ATank* ATankPlayerController_2::GetControlledTank() const
{	
	return Cast<ATank>(GetPawn());	
}


