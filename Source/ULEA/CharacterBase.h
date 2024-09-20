// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "ULEAAttributeSet.h"
#include "CharacterBase.generated.h"// �����͈�ԉ�����Ȃ��ƃG���[�o�܂�

UCLASS()
class ULEA_API ACharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PossessedBy(AController* NewController) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// �A�r���e�B�V�X�e��
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
	class UAbilitySystemComponent* AbilitySystem;

	// �A�g���r���[�g�Z�b�g
	UPROPERTY()
	UULEAAttributeSet* AttributeSet;

	void HandleMaxSpeedChanged(float DeltaValue, const struct FGameplayTagContainer& EventTags);
	
	UAbilitySystemComponent* GetAbilitySystemComponent() const
	{
		return AbilitySystem;
	};

	// �A�r���e�B���X�g
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
	TArray<TSubclassOf<class UGameplayAbility>> AbilityList;

};
