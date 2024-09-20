#include "ULEAAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "CharacterBase.h"

/** コンストラクタにより初期値設定 */
UULEAAttributeSet::UULEAAttributeSet()
	: MaxSpeed(400.0f)
{
}

// アトリビュート型取得関数
FGameplayAttribute UULEAAttributeSet::MaxSpeedAttribute()
{
	static FProperty* Property = FindFieldChecked<FProperty>(UULEAAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UULEAAttributeSet, MaxSpeed));
	return FGameplayAttribute(Property);
}

void UULEAAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	// 受け取ったデータから各種情報を取得
	FGameplayEffectContextHandle Context = Data.EffectSpec.GetContext();
	UAbilitySystemComponent* Source = Context.GetOriginalInstigaorAbilitySystemComponent();
	const FGameplayTagContainer& SourceTags = *Data.EffectSpec.CapturedSourceTags.GetAggregatedTags();

	// GameplayEffectにより指定されたアトリビュート変化値を計算t
	float DeltaValue = 0;
	if (Data.EvaluatedData.ModifierOp == EGameplayModOp::Type::Additive)
	{
		// If this was additive, store the raw delta value to be passed along later
		DeltaValue = Data.EvaluatedData.Magnitude;
	}

	// 受け取ったデータからターゲットアクター、コントローラ、キャラクタの取得
	AActor* TargetActor = nullptr;
	AController* TargetController = nullptr;
	ACharacterBase* TargetCharacter = nullptr;
	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		TargetActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		TargetCharacter = Cast<ACharacterBase>(TargetActor);
	}

	// 受け取ったデータがMaxSpeedだった場合にCharacter側の最大移動スピードに反映させる
	if (Data.EvaluatedData.Attribute == GetMaxSpeedAttribute())
	{
		if (TargetCharacter)
		{
			TargetCharacter->HandleMaxSpeedChanged(DeltaValue, SourceTags);
		}
	}
}
