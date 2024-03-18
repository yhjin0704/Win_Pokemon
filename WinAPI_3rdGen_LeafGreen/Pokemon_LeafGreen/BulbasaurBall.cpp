#include "BulbasaurBall.h"
#include "Pokemon3rdGen_Core.h"
#include "Player.h"
#include "FieldLevel.h"
#include "Global.h"
#include "PlayerHelper.h"

ABulbasaurBall::ABulbasaurBall()
{
}

ABulbasaurBall::~ABulbasaurBall()
{
}

void ABulbasaurBall::BeginPlay()
{
	BallRender = CreateImageRenderer(ERenderOrder::Object);
	BallRender->SetImage("Field_Item.png");
	BallRender->SetTransform({ { 0, 0 }, {(BallRender->GetImage()->GetScale()) * FScaleMultiple} });

	SelectImage = CreateImageRenderer(ERenderOrder::Menu);
	SelectImage->SetImage("Select_BBall.png");
	SelectImage->ActiveOff();
	
	BallCollision = CreateCollision(ECollisionOrder::Item);
	BallCollision->SetScale({ IGameTileScale, IGameTileScale });
	BallCollision->SetColType(ECollisionType::Rect);
	BallCollision->DebugRender(GetWorld()->GetCameraPos());
}

void ABulbasaurBall::Tick(float _DeltaTime)
{
	std::vector<UCollision*> Result;
	if (true == BallCollision->CollisionCheck(ECollisionOrder::Player, Result))
	{
		if (false == PlayerHelper::PlayerPause && false == PlayerHelper::IsUseMenu)
		{
			if (true == UEngineInput::IsDown('P'))
			{
				PlayerHelper::PlayerPause = true;
				SelectImage->SetTransform({ { GetWorld()->GetCameraPos().X - 32.0f * FScaleMultiple , GetWorld()->GetCameraPos().Y }, {(SelectImage->GetImage()->GetScale()) * FScaleMultiple} });
				SelectImage->ActiveOn();
			}
		}
		else if (true == PlayerHelper::PlayerPause && false == PlayerHelper::IsUseMenu)
		{
			if (true == UEngineInput::IsDown('P'))
			{
				std::map<int, PokemonInfo> AllInfo = Pokemon3rdGen_Core::GetAllPokemonInfo();

				dynamic_cast<Pokemon3rdGen_Core*>(GEngine)->AddEntry(1, 5);
				PlayerHelper::PlayerPause = false;
				SelectImage->ActiveOff();
				BallRender->ActiveOff();
				BallCollision->ActiveOff();
			}
			else if (true == UEngineInput::IsDown('L'))
			{
				PlayerHelper::PlayerPause = false;
				SelectImage->ActiveOff();
			}
		}
	}
}