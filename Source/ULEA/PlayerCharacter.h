// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FriendCharacter.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ULEA_API APlayerCharacter : public AFriendCharacter
{
	GENERATED_BODY()

	// 一人称カメラの実装
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = Camera,meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;

public:
	APlayerCharacter();

	// FPS用の腕
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh)
	class USkeletalMeshComponent* Mesh1P;

public:
	//Mesh1Pの返り値
	FORCEINLINE class USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }

	// 一人称カメラの返り値
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent()const { return FirstPersonCameraComponent; }
	
};
