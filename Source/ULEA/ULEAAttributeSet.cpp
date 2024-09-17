// Fill out your copyright notice in the Description page of Project Settings.


#include "ULEAAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "CharacterBase.h"

// コンストラクタ 初期化
UULEAAttributeSet::UULEAAttributeSet()
{
	MaxSpeed = (400.0f);	//	最大速度
}


// アトリビュート関数
FGameplayAttribute UULEAAttributeSet::MaxSpeedAttribute()
{
	static FProperty* Property = FindFieldChecked<FProperty>(UULEAAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UULEAAttributeSet, MaxSpeed));
	return FGameplayAttribute(Property);
}

// ゲームエフェクト
void UULEAAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExcute(Data);

	// 各種情報を取得
	FGameplayEffectContextHandle Context = Data.EffectSpec.GetContext();
	UAbilitySystemComponent* Source = Context.
}

// 