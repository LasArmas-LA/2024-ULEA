// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerBase.h"
#include "EnhancedInputSubsystems.h"

APlayerControllerBase::APlayerControllerBase()
{

}

void APlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();
	
	// �}�b�s���O�R���e�L�X�g�̒ǉ�
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}

}
