#include "EvolveBackGround.h"

AEvolveBackGround::AEvolveBackGround()
{
}

AEvolveBackGround::~AEvolveBackGround()
{
}

void AEvolveBackGround::BeginPlay()
{
	ABackGround::BeginPlay();

	SetBackGroundImage("EvolveBackGround.png");
}

void AEvolveBackGround::Tick(float _DeltaTime)
{
	ABackGround::Tick(_DeltaTime);
}
