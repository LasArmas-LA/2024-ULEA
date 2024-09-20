// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "ULEAAttributeSet.generated.h"


// AttributeSet.hへのセッターとゲッター
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName)
#define	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, ProprtyName)
#define	GAMEPLAYATTRIBUTE_VALUE_GETTER(ProprtyName)
#define	GAMEPLAYATTRIBUTE_VALUE_SETTER(ProprtyName)
#define	GAMEPLAYATTRIBUTE_VALUE_INITTER(ProprtyName)

UCLASS()
class ULEA_API UULEAAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UULEAAttributeSet();

	// Blueprintアクセス可能としたMaxSpeed定義、ATTRIBUTE_ACCESSORSによるアクセサ追記
	UPROPERTY(Category = "Attributes", EditAnywhere, BlueprintReadWrite)
	FGameplayAttributeData MaxSpeed;
	ATTRIBUTE_ACCESSORS(UULEAAttributeSet, MaxSpeed);
	FGameplayAttribute MaxSpeedAttribute();// アトリビュート型取得関数

	/** エフェクトによりアトリビュートが変化した場合のPost処理。主にUE5で直接管理しているメンバへの書き戻しを行う　*/
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};
