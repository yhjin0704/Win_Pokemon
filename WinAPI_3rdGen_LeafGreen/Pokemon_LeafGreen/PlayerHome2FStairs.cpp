#include "PlayerHome2FStairs.h"
#include <EngineCore\EngineCore.h>
#include "Global.h"

APlayerHome2FStairs::APlayerHome2FStairs()
{
}

APlayerHome2FStairs::~APlayerHome2FStairs()
{
}

void APlayerHome2FStairs::BeginPlay()
{
	HomeStairsCollision = CreateCollision(ECollisionOrder::Door);
	HomeStairsCollision->SetScale({ IGameTileScale, IGameTileScale });
	HomeStairsCollision->SetColType(ECollisionType::Rect);
	HomeStairsCollision->DebugRender(GetWorld()->GetCameraPos());
}

void APlayerHome2FStairs::Tick(float _DeltaTime)
{
	std::vector<UCollision*> Result;
	if (true == HomeStairsCollision->CollisionCheck(ECollisionOrder::Player, Result))
	{
		GEngine->ChangeLevel("PlayerHome1FLevel");
	}

}