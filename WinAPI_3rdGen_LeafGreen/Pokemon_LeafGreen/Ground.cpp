#include "Ground.h"

AGround::AGround()
{
}

AGround::~AGround()
{
}

void AGround::SwitchDebug()
{
	if (true == BackGroundRenderer->IsActive())
	{
		BackGroundRenderer->SetActive(false);
		ColMapRenderer->SetActive(true);
		CoverMapRenderer->SetActive(false);
	}
	else
	{
		BackGroundRenderer->SetActive(true);
		ColMapRenderer->SetActive(false);
		CoverMapRenderer->SetActive(true);
	}
}

void AGround::BeginPlay()
{
	ABackGround::BeginPlay();

	ColMapRenderer = CreateImageRenderer(ERenderOrder::ColMap);
	CoverMapRenderer = CreateImageRenderer(ERenderOrder::CoverMap);
	ColMapRenderer->SetActive(false);
}

void AGround::Tick(float _DeltaTime)
{
	ABackGround::Tick(_DeltaTime);

	if (UEngineInput::IsDown('0'))
	{
		SwitchDebug();
	}
}

void AGround::SetColMapImage(std::string_view _MapImageName)
{
	ColMapRenderer->SetImage(_MapImageName);
	ColMapImage = ColMapRenderer->GetImage();
	FVector ImageScale = ColMapImage->GetScale();
	ColMapRenderer->SetTransform({ (ImageScale.Half2D() * FScaleMultiple), (ImageScale * FScaleMultiple) });
}

void AGround::SetCoverMapImage(std::string_view _MapImageName)
{
	CoverMapRenderer->SetImage(_MapImageName);
	UWindowImage* CoverMapImage = CoverMapRenderer->GetImage();
	FVector ImageScale = CoverMapImage->GetScale();
	CoverMapRenderer->SetTransform({ (ImageScale.Half2D() * FScaleMultiple), (ImageScale * FScaleMultiple) });
}