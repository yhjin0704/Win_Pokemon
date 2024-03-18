#include "OaksLabGround.h"

AOaksLabGround::AOaksLabGround()
{
}

AOaksLabGround::~AOaksLabGround()
{
}

void AOaksLabGround::BeginPlay()
{
	AGround::BeginPlay();

	SetBackGroundImage("Oaks_Lab.png");
	SetColMapImage("Col_Oaks_Lab.png");
	SetCoverMapImage("Cover_Oaks_Lab.png");
}

void AOaksLabGround::Tick(float _DeltaTime)
{
	AGround::Tick(_DeltaTime);
}