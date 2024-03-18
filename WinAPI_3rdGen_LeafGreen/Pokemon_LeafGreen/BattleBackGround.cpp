#include "BattleBackGround.h"

ABattleBackGround::ABattleBackGround()
{
}

ABattleBackGround::~ABattleBackGround()
{
}

void ABattleBackGround::BeginPlay()
{
	ABackGround::BeginPlay();

	SetBackGroundImage("BattleBackGround_Grass.png");
}

void ABattleBackGround::Tick(float _DeltaTime)
{
	ABackGround::Tick(_DeltaTime);
}
