#include "BackGround.h"

ABackGround::ABackGround()
{
}

ABackGround::~ABackGround()
{
}

void ABackGround::BeginPlay()
{
	AActor::BeginPlay();
	BackGroundRenderer = CreateImageRenderer(ERenderOrder::BackGround);
}

void ABackGround::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void ABackGround::SetBackGroundImage(std::string_view _BackGroundImage)
{
	BackGroundRenderer->SetImage(_BackGroundImage);
	UWindowImage* BackGroundImage = BackGroundRenderer->GetImage();
	FVector ImageScale = BackGroundImage->GetScale();
	BackGroundRenderer->SetTransform({ (ImageScale.Half2D() * FScaleMultiple), (ImageScale * FScaleMultiple) });
}