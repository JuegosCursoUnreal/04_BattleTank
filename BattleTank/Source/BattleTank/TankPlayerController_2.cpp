// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController_2.h"
#include "DrawDebugHelpers.h"

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
		//Decirle al tanque que apunte a ese punto.
		GetControlledTank()->AimAt(HitLocation);		
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
	FVector WorldDirection = { 0,0,0 };	
	if (GetLookDirection(ScreenLocation, WorldDirection, OutHitLocation))
	{		
		// Line-trace a lo largo de esa dirección y ver que golpeamos (al maximo rango)
		FHitResult OutHit;
		GetLookVectorHitLocation(OutHitLocation,WorldDirection,OutHit);
		if (OutHit.bBlockingHit)
		{
			/// See what we hit
			///UE_LOG(LogTemp, Warning, TEXT("Colision contra: %s %s"), *OutHit.GetActor()->GetName(), *OutHit.ImpactPoint.ToString());
		}
		else
		{
			///UE_LOG(LogTemp, Warning, TEXT("Colision contra: %s"), *(FVector(0)).ToString());
		}
	}	
	return true;
}
bool ATankPlayerController_2::GetLookDirection(FVector2D &ScreenLocation, FVector &WorldDirection, FVector &WorldLocation) const
{	
	//"De-proyectar" la posición de la mira en la pantalla a una posición en el mundo
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		WorldLocation,
		WorldDirection
	);	
}

bool ATankPlayerController_2::GetLookVectorHitLocation(FVector &WorldLocation,FVector &WorldDirection, FHitResult &OutHit) const
{		
	//Defino un vector tomando como referencia la localización de la camara y la dirección de la mira y lo proyectará 10 km hacia esa dirección.
	FVector LineTraceEnd = WorldLocation + WorldDirection * LineTraceRange;

	//DrawDebugLine(GetWorld(), WorldLocation, LineTraceEnd, FColor::Green, false, 1, 0, 1);
	FCollisionQueryParams CollisionParams;
	FCollisionResponseParams Params;
	//ECollisionChannel ECC_Visibility significa que lo puede colisionar si lo ve
	return GetWorld()->LineTraceSingleByChannel(
		OutHit,
		WorldLocation,
		LineTraceEnd,
		ECC_Visibility,
		CollisionParams
	);
}

