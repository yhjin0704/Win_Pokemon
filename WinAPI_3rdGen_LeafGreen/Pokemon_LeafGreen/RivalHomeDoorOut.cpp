#include "RivalHomeDoorOut.h"

ARivalHomeDoorOut::ARivalHomeDoorOut()
{
}

ARivalHomeDoorOut::~ARivalHomeDoorOut()
{
}

void ARivalHomeDoorOut::BeginPlay()
{
	HomeDoorCollision = CreateCollision(ECollisionOrder::Door);
	HomeDoorCollision->SetScale({ IGameTileScale, IGameTileScale });
	HomeDoorCollision->SetColType(ECollisionType::Rect);
}

void ARivalHomeDoorOut::Tick(float _DeltaTime)
{
	std::vector<UCollision*> Result;
	if (true == HomeDoorCollision->CollisionCheck(ECollisionOrder::Player, Result))
	{
		GEngine->ChangeLevel("RivalHomeLevel");
	}

}