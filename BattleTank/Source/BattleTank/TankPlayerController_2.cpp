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

void ATankPlayerController_2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();	
}

ATank* ATankPlayerController_2::GetControlledTank() const
{	
	return Cast<ATank>(GetPawn());	
}

void ATankPlayerController_2::AimTowardsCrosshair()
{
	if (!GetControlledTank) { return; }
	//Obtener la localización del mundo donde el linetrace atraviese la crosshair e intersecte con el mundo
		// Si golpea al mundo
		// Decirle al tanque que apunte a ese punto.
}


