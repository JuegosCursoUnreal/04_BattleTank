// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "TankPlayerController_2.generated.h" //must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController_2 : public APlayerController
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.f;
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;	

	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	//función encargada de apuntar el cañon del tanque hacia donde apunte el crosshair
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector&) const;

	bool GetLookDirection(FVector2D & ScreenLocation, FVector & WorldDirection, FVector &WorldLocation) const;
	
	bool GetLookVectorHitLocation(FVector &WorldLocation, FVector &WorldDirection, FHitResult &OutHit) const;
};


