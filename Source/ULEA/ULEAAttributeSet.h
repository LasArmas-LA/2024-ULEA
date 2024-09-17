// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "ULEAAttributeSet.generated.h"


// SttributeSet.h�ւ̃Z�b�^�[�ƃQ�b�^�[
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName)\
		GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, ProprtyName)\
		GAMEPLAYATTRIBUTE_VALUE_GETTER(ProprtyName)\
		GAMEPLAYATTRIBUTE_VALUE_SETTER(ProprtyName)\
		GAMEPLAYATTRIBUTE_VALUE_INITTER(ProprtyName)

UCLASS()
class ULEA_API UULEAAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UULEAAttributeSet();

	// �u���[�v�����g�ŃA�N�Z�X�ł���MaxSpeed�̒�`�i�A�N�Z�T�[�ǋL�j
	UPROPERTY(Category = "Attributes", EditAnywhere, BlueprintReadWrite)
	FGameplayAttributeData MaxSpeed;
	
	ATTRIBUTE_ACCESSORS(UULEAAttributeSet, MaxSpeed);
	FGameplayAttribute MaxSpeedAttribute(); // �A�g���r���[�g�^�����֐�

	/** �G�t�F�N�g�ɂ��A�g���r���[�g���ω������ꍇ��Post�����B���UE5�Œ��ڊǗ����Ă��郁���o�ւ̏����߂����s���@*/

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)override;
};
