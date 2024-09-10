// 2024 Green Rain Studios

#include "StereoRigUtils.h"
#include "CineCameraComponent.h"

void UStereoRigUtils::CopyCineCameraSettings(const UCineCameraComponent* Source, UCineCameraComponent* Target)
{
	if (!Source || !Target)
		return;

	// Cine camera settings
	Target->SetCurrentFocalLength(Source->CurrentFocalLength);
	Target->SetCurrentAperture(Source->CurrentAperture);
	Target->SetLensSettings(Source->LensSettings);
	Target->SetFocusSettings(Source->FocusSettings);
	Target->SetAspectRatio(Source->AspectRatio);
	Target->SetFilmback(Source->Filmback);
	Target->CurrentFocusDistance = Source->CurrentFocusDistance;
	Target->bOverride_CustomNearClippingPlane = Source->bOverride_CustomNearClippingPlane;
	Target->CustomNearClippingPlane = Source->CustomNearClippingPlane;
	Target->PostProcessSettings = Source->PostProcessSettings;
	Target->PostProcessBlendWeight = Source->PostProcessBlendWeight;

	// Base camera settings
	Target->FieldOfView = Source->FieldOfView;
	Target->bConstrainAspectRatio = Source->bConstrainAspectRatio;
	Target->bUseFieldOfViewForLOD = Source->bUseFieldOfViewForLOD;
	Target->ProjectionMode = Source->ProjectionMode;

	// Mark render dirty
	Target->MarkRenderStateDirty();
}
