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

	// ��l�̃J�����̎���
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = Camera,meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;

public:
	APlayerCharacter();

	// FPS�p�̘r
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh)
	class USkeletalMeshComponent* Mesh1P;

public:
	//Mesh1P�̕Ԃ�l
	FORCEINLINE class USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }

	// ��l�̃J�����̕Ԃ�l
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent()const { return FirstPersonCameraComponent; }
	
};
