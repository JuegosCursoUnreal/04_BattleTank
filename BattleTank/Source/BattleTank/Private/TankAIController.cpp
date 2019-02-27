// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();	
	
	if (GetPlayerTank() && GetPawn())
	{
		auto TanquePoseido = GetControlledTank()->GetName();
		auto TanqueJugador = GetPlayerTank()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("AI %s encontro al jugador: %s"), *TanquePoseido, *TanqueJugador);
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("AI no encontro al jugador o AI Pawn NO Obtenido"));
}

ATank* ATankAIController::GetPlayerTank() const
{
	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; } else
	return Cast<ATank>(PlayerPawn);
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::Tick(float DeltaTime)
{
	GetControlledTank()->AimAt(GetPlayerTank()->GetTargetLocation());
}

