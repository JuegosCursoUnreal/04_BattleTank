// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController_2.h"

ATank* ATankPlayerController_2::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


