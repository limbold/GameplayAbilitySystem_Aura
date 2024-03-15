// Copyright limbold

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuraEffectActor.generated.h"

class USphereComponent;
class UStaticMeshComponent;
UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()

public:
	AAuraEffectActor();

	// 当有角色进入范围时
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	               int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// 当有角色离开范围时
	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                  int32 OtherBodyIndex);
protected:
	virtual void BeginPlay() override;

private:
	// Sphere组件
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;

	// Mesh组件
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;
};
