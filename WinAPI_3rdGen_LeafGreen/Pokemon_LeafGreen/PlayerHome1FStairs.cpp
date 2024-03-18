#include "PlayerHome1FStairs.h"
#include <EngineCore\EngineCore.h>
#include "Global.h"

APlayerHome1FStairs::APlayerHome1FStairs()
{
}

APlayerHome1FStairs::~APlayerHome1FStairs()
{
}

void APlayerHome1FStairs::BeginPlay()
{
	HomeStairsCollision = CreateCollision(ECollisionOrder::Door);
	HomeStairsCollision->SetScale({ IGameTileScale, IGameTileScale });
	HomeStairsCollision->SetColType(ECollisionType::Rect);
	HomeStairsCollision->DebugRender(GetWorld()->GetCameraPos());
}

void APlayerHome1FStairs::Tick(float _DeltaTime)
{
	std::vector<UCollision*> Result;
	if (true == HomeStairsCollision->CollisionCheck(ECollisionOrder::Player, Result))
	{
		GEngine->ChangeLevel("PlayerHome2FLevel");
	}

}