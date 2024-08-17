// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

UCLASS()
class ULEA_API AWeaponBase : public AActor
{
	GENERATED_BODY()

	// 武器のメッシュ
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon", meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* Mesh;

public:		// 自クラス	継承したクラス	外部クラスで参照できる

	// Sets default values for this actor's properties
	AWeaponBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 発砲音
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	USoundBase* FireSound;

	// 銃口の位置（マズル）
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FVector MuzzleOffset;

	//======================関数=======================
	// 射撃関数
	UFUNCTION(BlueprintCallable, Category = "Action")
	void Fire();

	// エフェクト
	UFUNCTION(BlueprintCallable, Category = "Action")
	void FireEffect();

	// 射撃イベント
	UFUNCTION(BlueprintImplementableEvent, BulueprintCallable, Category = "Action")
	void FireAction();

	/*
	コンパイラに対してこの関数を「インライン化」するように指示します
	インライン化とは関数呼び出しのオーバーヘッドを省くために、
	関数のコードをその呼び出し元に直接展開することです。
	これによりパフォーマンスが向上する場合があります。
	ただしコンパイラはこの指示を無視することもあります。
	*/
	FORCEINLINE class USkeletalMeshComponent* GetMesh() const { return Mesh; }	// インライン化


	//======================武器のパラメーター=======================
	// セッター
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float MaxAmmo;			// 弾の最大数
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float Ammo;				// 弾数
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float StockAmmo;		// 弾の所持数
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float WeaponDamage;		// 武器のダメージ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float FireRate;			// 射撃速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float FireRange;		// 射程距離
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float FireSpread;		// 弾速？

	// ゲッター(全て純粋関数 BlueprintPure＝純粋)
	UFUNCTION(BlueprintPure, Category = "Weapon")
	float GetMaxAmmo();		// 弾の最大数
	UFUNCTION(BlueprintPure, Category = "Weapon")
	float GetAmmo();		// 弾数
	UFUNCTION(BlueprintPure, Category = "Weapon")
	float GetStockAmmo();	// 弾の所持数
	UFUNCTION(BlueprintPure, Category = "Weapon")
	float GetWeaponDamage();// 武器のダメージ
	UFUNCTION(BlueprintPure, Category = "Weapon")
	float GetFireRate();	// 射撃速度
	UFUNCTION(BlueprintPure, Category = "Weapon")
	float GetFireRange();	// 射程距離
	UFUNCTION(BlueprintPure, Category = "Weapon")
	float GetFireSpread();	// 弾速？


protected:	// 自クラス	継承したクラス	で参照できる
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// 射撃フラグ
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,Category = "Gameplay")
	bool bCanFire;

	// 射撃のセット
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void SetCanFire();

private:	// 自クラス　で参照できる

};
