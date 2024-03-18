#include "OaksLabDoorOut.h"

AOaksLabDoorOut::AOaksLabDoorOut()
{
}

AOaksLabDoorOut::~AOaksLabDoorOut()
{
}

void AOaksLabDoorOut::BeginPlay()
{
	LabDoorCollision = CreateCollision(ECollisionOrder::Door);
	LabDoorCollision->SetScale({ IGameTileScale, IGameTileScale });
	LabDoorCollision->SetColType(ECollisionType::Rect);
}

void AOaksLabDoorOut::Tick(float _DeltaTime)
{
	std::vector<UCollision*> Result;
	if (true == LabDoorCollision->CollisionCheck(ECollisionOrder::Player, Result))
	{
		GEngine->ChangeLevel("OaksLabLevel");
	}

}