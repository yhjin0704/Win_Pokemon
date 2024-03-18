#include "PlayerHomeDoorOut.h"
#include <EngineCore\EngineCore.h>
#include "Global.h"

APlayerHomeDoorOut::APlayerHomeDoorOut()
{
}

APlayerHomeDoorOut::~APlayerHomeDoorOut()
{
}

void APlayerHomeDoorOut::BeginPlay()
{
	HomeDoorCollision = CreateCollision(ECollisionOrder::Door);
	HomeDoorCollision->SetScale({ IGameTileScale, IGameTileScale });
	HomeDoorCollision->SetColType(ECollisionType::Rect);
}

void APlayerHomeDoorOut::Tick(float _DeltaTime)
{
	std::vector<UCollision*> Result;
	if (true == HomeDoorCollision->CollisionCheck(ECollisionOrder::Player, Result))
	{
		GEngine->ChangeLevel("PlayerHome1FLevel");
	}

}