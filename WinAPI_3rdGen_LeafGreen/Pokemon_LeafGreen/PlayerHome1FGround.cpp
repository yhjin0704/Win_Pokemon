#include "PlayerHome1FGround.h"
#include <EngineCore\EngineResourcesManager.h>
#include <EngineBase\EngineFile.h>

APlayerHome1FGround::APlayerHome1FGround()
{
}

APlayerHome1FGround::~APlayerHome1FGround()
{
}

void APlayerHome1FGround::BeginPlay()
{
	AGround::BeginPlay();

	SetBackGroundImage("Player_Home_1F.png");
	SetColMapImage("Col_Player_Home_1F.png");
	SetCoverMapImage("Cover_Player_Home_1F.png");
}

void APlayerHome1FGround::Tick(float _DeltaTime)
{
	AGround::Tick(_DeltaTime);
}

