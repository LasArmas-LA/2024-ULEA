// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
// �R���X�g���N�^
AWeaponBase::AWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
	
	// ����̃��b�V��
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	RootComponent = Mesh;

	bCanFire = true;	// �ˌ��t���O

	MuzzleOffset = FVector(100.0f, 0.0f, 10.0f);	// �e���̈ʒu

	bIsFullAuto = true;	//

	MaxAmmo			= 30.0f;	// �e�̍ő吔
	Ammo			= 30.0f;	// �e��
	StockAmmo		= 300.0f;	// �e�̏�����
	WeaponDamage	= 15.0f;	// ����̃_���[�W
	FireRate		= 0.5f;		// �ˌ����x
	FireRange		= 3000.0f;	// �˒�����
	FireSpeed		= 2.5f;		// �e���H

}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// �ˌ��֐�
void AWeaponBase::Fire()
{
	if (bCanFire == true)
	{
		if (GetAmmo() > 0.0f)
		{
		/*	FireAction();*/

			FireEffect();

			Ammo = FMath::Clamp(GetAmmo() - 1.0f, 0.0f, GetMaxAmmo());

			bCanFire = false;

			FTimerManager& timerManager = GetWorldTimerManager();
			FTimerHandle _TimerHandle;
			GetWorldTimerManager().SetTimer(_TimerHandle, this, &AWeaponBase::SetCanFire, AWeaponBase::GetFireRate(), false);
		}
	}
}

void AWeaponBase::SetCanFire()
{
	bCanFire = true;
}

// �G�t�F�N�g
void AWeaponBase::FireEffect()
{
	if (FireSound != nullptr)
	{
		UGameplayStatics::PlaySound2D(this, FireSound);
	}
}

// �ˌ��C�x���g
//void AWeaponBase::FireAction()
//{
//
//}

float AWeaponBase::GetMaxAmmo()
{
	return MaxAmmo;
}

float AWeaponBase::GetAmmo()
{
	return Ammo;
}

float AWeaponBase::GetStockAmmo()
{
	return StockAmmo;
}

float AWeaponBase::GetWeaponDamage()
{
	return WeaponDamage;
}

float AWeaponBase::GetFireRate()
{
	return FireRate;
}

float AWeaponBase::GetFireRange()
{
	return FireRange;
}

float AWeaponBase::GetFireSpeed()
{
	return FireSpeed;
}