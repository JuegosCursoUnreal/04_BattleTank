// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController_2.generated.h" //must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController_2 : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	//función encargada de apuntar el cañon del tanque hacia donde apunte el crosshair
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector&) const;

};
