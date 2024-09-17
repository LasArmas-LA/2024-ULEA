// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "ULEAAttributeSet.generated.h"


// SttributeSet.hへのセッターとゲッター
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

	// ブループリントでアクセスできるMaxSpeedの定義（アクセサー追記）
	UPROPERTY(Category = "Attributes", EditAnywhere, BlueprintReadWrite)
	FGameplayAttributeData MaxSpeed;
	
	ATTRIBUTE_ACCESSORS(UULEAAttributeSet, MaxSpeed);
	FGameplayAttribute MaxSpeedAttribute(); // アトリビュート型所得関数

	/** エフェクトによりアトリビュートが変化した場合のPost処理。主にUE5で直接管理しているメンバへの書き戻しを行う　*/

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)override;
};
