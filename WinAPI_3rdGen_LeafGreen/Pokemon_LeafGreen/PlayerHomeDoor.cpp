#include "PlayerHomeDoor.h"
#include <EngineCore\EngineCore.h>
#include "Global.h"

APlayerHomeDoor::APlayerHomeDoor()
{
}

APlayerHomeDoor::~APlayerHomeDoor()
{
}

void APlayerHomeDoor::BeginPlay()
{
	HomeDoorCollision = CreateCollision(ECollisionOrder::Door);
	HomeDoorCollision->SetScale({ IGameTileScale, IGameTileScale });
	HomeDoorCollision->SetColType(ECollisionType::Rect);
	HomeDoorCollision->DebugRender(GetWorld()->GetCameraPos());
}

void APlayerHomeDoor::Tick(float _DeltaTime) 
{
	std::vector<UCollision*> Result;
	if (true == HomeDoorCollision->CollisionCheck(ECollisionOrder::Player, Result))
	{
		GEngine->ChangeLevel("WestFieldLevel");
	}
}