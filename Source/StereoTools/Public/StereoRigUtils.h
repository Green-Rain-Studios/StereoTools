// 2024 Green Rain Studios

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StereoRigUtils.generated.h"

/**
 * 
 */
UCLASS()
class STEREOTOOLS_API UStereoRigUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, Category="Stereo Rig|Utils")
	static void CopyCineCameraSettings(const UCineCameraComponent* Source, UPARAM(ref) UCineCameraComponent* Target);
};
