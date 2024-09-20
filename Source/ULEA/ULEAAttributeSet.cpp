#include "ULEAAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "CharacterBase.h"

/** �R���X�g���N�^�ɂ�菉���l�ݒ� */
UULEAAttributeSet::UULEAAttributeSet()
	: MaxSpeed(400.0f)
{
}

// �A�g���r���[�g�^�擾�֐�
FGameplayAttribute UULEAAttributeSet::MaxSpeedAttribute()
{
	static FProperty* Property = FindFieldChecked<FProperty>(UULEAAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UULEAAttributeSet, MaxSpeed));
	return FGameplayAttribute(Property);
}

void UULEAAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	// �󂯎�����f�[�^����e������擾
	FGameplayEffectContextHandle Context = Data.EffectSpec.GetContext();
	UAbilitySystemComponent* Source = Context.GetOriginalInstigaorAbilitySystemComponent();
	const FGameplayTagContainer& SourceTags = *Data.EffectSpec.CapturedSourceTags.GetAggregatedTags();

	// GameplayEffect�ɂ��w�肳�ꂽ�A�g���r���[�g�ω��l���v�Zt
	float DeltaValue = 0;
	if (Data.EvaluatedData.ModifierOp == EGameplayModOp::Type::Additive)
	{
		// If this was additive, store the raw delta value to be passed along later
		DeltaValue = Data.EvaluatedData.Magnitude;
	}

	// �󂯎�����f�[�^����^�[�Q�b�g�A�N�^�[�A�R���g���[���A�L�����N�^�̎擾
	AActor* TargetActor = nullptr;
	AController* TargetController = nullptr;
	ACharacterBase* TargetCharacter = nullptr;
	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		TargetActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		TargetCharacter = Cast<ACharacterBase>(TargetActor);
	}

	// �󂯎�����f�[�^��MaxSpeed�������ꍇ��Character���̍ő�ړ��X�s�[�h�ɔ��f������
	if (Data.EvaluatedData.Attribute == GetMaxSpeedAttribute())
	{
		if (TargetCharacter)
		{
			TargetCharacter->HandleMaxSpeedChanged(DeltaValue, SourceTags);
		}
	}
}
