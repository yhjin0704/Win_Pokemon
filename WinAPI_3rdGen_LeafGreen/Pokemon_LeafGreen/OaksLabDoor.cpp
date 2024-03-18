#include "OaksLabDoor.h"

AOaksLabDoor::AOaksLabDoor()
{
}

AOaksLabDoor::~AOaksLabDoor()
{
}

void AOaksLabDoor::BeginPlay()
{
	LabDoorCollision = CreateCollision(ECollisionOrder::Door);
	LabDoorCollision->SetScale({ IGameTileScale, IGameTileScale });
	LabDoorCollision->SetColType(ECollisionType::Rect);
	LabDoorCollision->DebugRender(GetWorld()->GetCameraPos());
}

void AOaksLabDoor::Tick(float _DeltaTime)
{
	std::vector<UCollision*> Result;
	if (true == LabDoorCollision->CollisionCheck(ECollisionOrder::Player, Result))
	{
		GEngine->ChangeLevel("WestFieldLevel");
	}
}