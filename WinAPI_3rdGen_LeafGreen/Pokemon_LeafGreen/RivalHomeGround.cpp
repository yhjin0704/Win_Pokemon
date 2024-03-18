#include "RivalHomeGround.h"

ARivalHomeGround::ARivalHomeGround()
{
}

ARivalHomeGround::~ARivalHomeGround()
{
}

void ARivalHomeGround::BeginPlay()
{
	AGround::BeginPlay();

	SetBackGroundImage("Rival_Home.png");
	SetColMapImage("Col_Rival_Home.png");
	SetCoverMapImage("Cover_Rival_Home.png");
}

void ARivalHomeGround::Tick(float _DeltaTime)
{
	AGround::Tick(_DeltaTime);
}