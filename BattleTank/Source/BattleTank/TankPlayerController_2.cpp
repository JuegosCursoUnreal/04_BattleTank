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
	if (!GetControlledTank()) { return; }
	FVector HitLocation = { 0,0,0 };
	if(GetSightRayHitLocation(HitLocation))	
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
		//TODO Decirle al tanque que apunte a ese punto.
	}
}
//Obtener la localización del mundo donde el linetrace atraviese la crosshair e intersecte con el mundo
bool ATankPlayerController_2::GetSightRayHitLocation(FVector &OutHitLocation) const
{	
	//encontrar la posición del crosshair	
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = { 
		ViewportSizeX*CrossHairXLocation , 
		ViewportSizeY*CrossHairYLocation 
	};
	//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());
	//"De-proyectar" la posición de la mira en la pantalla a una posición en el mundo
	// Line-trace a lo largo de esa dirección y ver que golpeamos (al maximo rango)
	return true;
}

