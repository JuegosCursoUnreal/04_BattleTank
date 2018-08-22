// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto TanquePoseido = GetControlledTank()->GetName();
	if (GetPawn())
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Pawn Obtenido: %s"), *TanquePoseido);
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("AI Pawn NO Obtenido"));
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


