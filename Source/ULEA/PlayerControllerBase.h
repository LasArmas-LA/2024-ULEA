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

	// セッター
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float MaxAmmo;			// 弾の最大数

};
