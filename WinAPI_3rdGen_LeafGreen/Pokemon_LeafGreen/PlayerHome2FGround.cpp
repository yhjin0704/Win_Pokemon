#include "PlayerHome2FGround.h"
#include <EngineCore\EngineResourcesManager.h>
#include <EngineBase\EngineFile.h>

APlayerHome2FGround::APlayerHome2FGround()
{
}

APlayerHome2FGround::~APlayerHome2FGround()
{
}

void APlayerHome2FGround::BeginPlay()
{
	AGround::BeginPlay();

	SetBackGroundImage("Player_Home_2F.png");
	SetColMapImage("Col_Player_Home_2F.png");
	SetCoverMapImage("Cover_Player_Home_2F.png");
}

void APlayerHome2FGround::Tick(float _DeltaTime)
{
	AGround::Tick(_DeltaTime);
}
