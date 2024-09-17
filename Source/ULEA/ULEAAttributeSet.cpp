// Fill out your copyright notice in the Description page of Project Settings.


#include "ULEAAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "CharacterBase.h"

// �R���X�g���N�^ ������
UULEAAttributeSet::UULEAAttributeSet()
{
	MaxSpeed = (400.0f);	//	�ő呬�x
}


// �A�g���r���[�g�֐�
FGameplayAttribute UULEAAttributeSet::MaxSpeedAttribute()
{
	static FProperty* Property = FindFieldChecked<FProperty>(UULEAAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UULEAAttributeSet, MaxSpeed));
	return FGameplayAttribute(Property);
}

// �Q�[���G�t�F�N�g
void UULEAAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExcute(Data);

	// �e������擾
	FGameplayEffectContextHandle Context = Data.EffectSpec.GetContext();
	UAbilitySystemComponent* Source = Context.
}

// 