// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
// コンストラクタ
AWeaponBase::AWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
	
	// 武器のメッシュ
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	RootComponent = Mesh;

	bCanFire = true;	// 射撃フラグ

	MuzzleOffset = FVector(100.0f, 0.0f, 10.0f);	// 銃口の位置

	bIsFullAuto = true;	//

	MaxAmmo			= 30.0f;	// 弾の最大数
	Ammo			= 30.0f;	// 弾数
	StockAmmo		= 300.0f;	// 弾の所持数
	WeaponDamage	= 15.0f;	// 武器のダメージ
	FireRate		= 0.5f;		// 射撃速度
	FireRange		= 3000.0f;	// 射程距離
	FireSpeed		= 2.5f;		// 弾速？

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

// 射撃関数
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

// エフェクト
void AWeaponBase::FireEffect()
{
	if (FireSound != nullptr)
	{
		UGameplayStatics::PlaySound2D(this, FireSound);
	}
}

// 射撃イベント
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