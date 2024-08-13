// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

UCLASS()
class ULEA_API AWeaponBase : public AActor
{
	GENERATED_BODY()

	// ����̃��b�V��
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon", meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* Mesh;

public:		// ���N���X	�p�������N���X	�O���N���X�ŎQ�Ƃł���

	// Sets default values for this actor's properties
	AWeaponBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// ���C��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	USoundBase* FireSound;

	// �e���̈ʒu�i�}�Y���j
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FVector MuzzleOffset;

	//======================�֐�=======================
	// �ˌ��֐�
	UFUNCTION(BlueprintCallable, Category = "Action")
	void Fire();

	// �G�t�F�N�g
	UFUNCTION(BlueprintCallable, Category = "Action")
	void FireEffect();

	// �ˌ��C�x���g
	UFUNCTION(BlueprintImplementableEvent, BulueprintCallable, Category = "Action")
	void FireAction();

	/*
	�R���p�C���ɑ΂��Ă��̊֐����u�C�����C�����v����悤�Ɏw�����܂�
	�C�����C�����Ƃ͊֐��Ăяo���̃I�[�o�[�w�b�h���Ȃ����߂ɁA
	�֐��̃R�[�h�����̌Ăяo�����ɒ��ړW�J���邱�Ƃł��B
	����ɂ��p�t�H�[�}���X�����シ��ꍇ������܂��B
	�������R���p�C���͂��̎w���𖳎����邱�Ƃ�����܂��B
	*/
	FORCEINLINE class USkeletalMeshComponent* GetMesh() const { return Mesh; }	// �C�����C����


	//======================����̃p�����[�^�[=======================
	// �Z�b�^�[
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float MaxAmmo;			// �e�̍ő吔
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float Ammo;				// �e��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float StockAmmo;		// �e�̏�����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float WeaponDamage;		// ����̃_���[�W
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float FireRate;			// �ˌ����x
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float FireRange;		// �˒�����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float FireSpread;		// �e���H

	// �Q�b�^�[(�S�ď����֐� BlueprintPure������)
	UFUNCTION(BlueprintPure, Category = "Weapon")
	float GetMaxAmmo();		// �e�̍ő吔
	UFUNCTION(BlueprintPure, Category = "Weapon")
	float GetAmmo();		// �e��
	UFUNCTION(BlueprintPure, Category = "Weapon")
	float GetStockAmmo();	// �e�̏�����
	UFUNCTION(BlueprintPure, Category = "Weapon")
	float GetWeaponDamage();// ����̃_���[�W
	UFUNCTION(BlueprintPure, Category = "Weapon")
	float GetFireRate();	// �ˌ����x
	UFUNCTION(BlueprintPure, Category = "Weapon")
	float GetFireRange();	// �˒�����
	UFUNCTION(BlueprintPure, Category = "Weapon")
	float GetFireSpread();	// �e���H


protected:	// ���N���X	�p�������N���X	�ŎQ�Ƃł���
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// �ˌ��t���O
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,Category = "Gameplay")
	bool bCanFire;

	// �ˌ��̃Z�b�g
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void SetCanFire();

private:	// ���N���X�@�ŎQ�Ƃł���

};
