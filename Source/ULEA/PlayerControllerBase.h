// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class ULEA_API PlayerControllerBase
{
public:
	PlayerControllerBase();

	~PlayerControllerBase();

	// �Z�b�^�[
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float MaxAmmo;			// �e�̍ő吔

};
