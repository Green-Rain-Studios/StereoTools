// 2024 Green Rain Studios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StereoRigActor.generated.h"

class ACineCameraActor;

UCLASS(Blueprintable,ClassGroup="Rendering")
class STEREOTOOLS_API AStereoRigActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AStereoRigActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category="Stereo Rig")
	void ValidateCameraAttachments();
	
	UFUNCTION(BlueprintCallable, Category="Stereo Rig")
    void ProcessSourceCamera();

#if WITH_EDITOR
	virtual void OnConstruction(const FTransform& Transform) override;
#endif

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Distance between two eyes
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Interp, Category="Stereo Rig", meta=(Units="cm", ForceUnits, ClampMin=0.f))
	float InterpupillaryDistance = 6.4f;

	// T
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Interp, Category="Stereo Rig", meta=(Units="deg", ForceUnits))
	float ToeInAngle = 0.f;
	
	// Source camera that the settings will be copied from
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Interp, Category="Stereo Rig|Camera")
	TObjectPtr<ACineCameraActor> SourceCamera;

	// Target left eye
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Interp, Category="Stereo Rig|Camera")
	TObjectPtr<ACineCameraActor> LeftEye;

	// Target right eye
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Interp, Category="Stereo Rig|Camera")
	TObjectPtr<ACineCameraActor> RightEye;

protected:
	UPROPERTY()
	TObjectPtr<UBillboardComponent> Root;
};
