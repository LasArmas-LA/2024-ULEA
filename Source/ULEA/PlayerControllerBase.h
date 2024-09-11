// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class ULEA_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
	
	UPROPERTY(Editanywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

public:
	APlayerControllerBase();

protected:
	virtual void BeginPlay();

};

