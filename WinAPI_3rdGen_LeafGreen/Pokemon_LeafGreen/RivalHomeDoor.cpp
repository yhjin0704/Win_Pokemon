#include "RivalHomeDoor.h"

ARivalHomeDoor::ARivalHomeDoor()
{
}

ARivalHomeDoor::~ARivalHomeDoor()
{
}

void ARivalHomeDoor::BeginPlay()
{
	HomeDoorCollision = CreateCollision(ECollisionOrder::Door);
	HomeDoorCollision->SetScale({ IGameTileScale, IGameTileScale });
	HomeDoorCollision->SetColType(ECollisionType::Rect);
	HomeDoorCollision->DebugRender(GetWorld()->GetCameraPos());
}

void ARivalHomeDoor::Tick(float _DeltaTime)
{
	std::vector<UCollision*> Result;
	if (true == HomeDoorCollision->CollisionCheck(ECollisionOrder::Player, Result))
	{
		GEngine->ChangeLevel("WestFieldLevel");
	}
}