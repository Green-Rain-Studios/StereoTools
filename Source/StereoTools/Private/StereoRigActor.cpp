// 2024 Green Rain Studios

#include "StereoRigActor.h"

#include "CineCameraActor.h"
#include "StereoRigUtils.h"
#include "Components/BillboardComponent.h"

// Sets default values
AStereoRigActor::AStereoRigActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Scene component
	static ConstructorHelpers::FObjectFinder<UTexture2D> TexRef(TEXT("/Engine/EditorResources/EmptyActor.EmptyActor"));
	Root = CreateDefaultSubobject<UBillboardComponent>(TEXT("Root"));
	Root->SetSprite(TexRef.Object);
	RootComponent = Root;
}

// Called when the game starts or when spawned
void AStereoRigActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStereoRigActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	ValidateCameraAttachments();
	ProcessSourceCamera();
}

#if WITH_EDITOR
void AStereoRigActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	ValidateCameraAttachments();
	ProcessSourceCamera();
}
#endif

void AStereoRigActor::ValidateCameraAttachments()
{
	if(!SourceCamera || !LeftEye || !RightEye)
		return;
	
	// Attach the two camera actors to this rig if not attached
	if(!LeftEye->GetAttachParentActor())
		LeftEye->AttachToComponent(SourceCamera->GetRootComponent(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false));

	if(!RightEye->GetAttachParentActor())
		RightEye->AttachToComponent(SourceCamera->GetRootComponent(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false));

	// Relative location set
	LeftEye->SetActorRelativeLocation(FVector(0.f, -InterpupillaryDistance/2, 0.f));
	RightEye->SetActorRelativeLocation(FVector(0.f, InterpupillaryDistance/2, 0.f));

	// Toe in
	LeftEye->SetActorRelativeRotation(FRotator(0, ToeInAngle, 0));
	RightEye->SetActorRelativeRotation(FRotator(0, -ToeInAngle, 0));
}

void AStereoRigActor::ProcessSourceCamera()
{
	if(!SourceCamera)
		return;

	if(LeftEye)
		UStereoRigUtils::CopyCineCameraSettings(SourceCamera->GetCineCameraComponent(), LeftEye->GetCineCameraComponent());
	if(RightEye)
		UStereoRigUtils::CopyCineCameraSettings(SourceCamera->GetCineCameraComponent(), RightEye->GetCineCameraComponent());	
}

