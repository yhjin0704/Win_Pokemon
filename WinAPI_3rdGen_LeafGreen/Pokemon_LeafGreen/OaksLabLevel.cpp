#include "OaksLabLevel.h"

UOaksLabLevel::UOaksLabLevel()
{
}

UOaksLabLevel::~UOaksLabLevel()
{
}

void UOaksLabLevel::BeginPlay()
{
	UFieldLevel::BeginPlay();

	IsOutside = false;

	Ground = SpawnActor<AOaksLabGround>();
	Door = SpawnActor<AOaksLabDoor>();
	BBall = SpawnActor<ABulbasaurBall>();
	CBall = SpawnActor<ACharmanderBall>();
	SBall = SpawnActor<ASquirtleBall>();

	Door->SetActorLocation({ (112 + (FTileScale / 2)) * FScaleMultiple , (224 + (FTileScale / 2)) * FScaleMultiple });
	BBall->SetActorLocation({ (144 + (FTileScale / 2)) * FScaleMultiple , (64 + (FTileScale / 2)) * FScaleMultiple });
	CBall->SetActorLocation({ (160 + (FTileScale / 2)) * FScaleMultiple , (64 + (FTileScale / 2)) * FScaleMultiple });
	SBall->SetActorLocation({ (176 + (FTileScale / 2)) * FScaleMultiple , (64 + (FTileScale / 2)) * FScaleMultiple });

	Player->SetActorLocation({ (112 + (FTileScale / 2)) * FScaleMultiple , (192) * FScaleMultiple });
}

void UOaksLabLevel::Tick(float _DeltaTime)
{
}

void UOaksLabLevel::LevelStart(ULevel* _PrevLevel)
{
	Global::GColMapImage = Ground->GetColMapImage();
	GetPlayer()->SetMoveType(PlayerHelper::PlayerMoveType);
	if (EMoveType::Bike == GetPlayer()->GetMoveType())
	{
		Global::ChangeBGM("Oaks_Lab.mp3");
		GetPlayer()->SetMoveType(PlayerHelper::PrevMoveType);
	}

	UFieldLevel* Field = dynamic_cast<UFieldLevel*>(_PrevLevel);
	if (nullptr != Field && UEngineString::ToUpper("TitleLevel4") != Field->GetName())
	{
		if (UEngineString::ToUpper("WestFieldLevel") == Field->GetName())
		{
			GetPlayer()->SetCharacterDir(EDirState::Up);
			GetPlayer()->SetActorLocation({ (112 + (FTileScale / 2)) * FScaleMultiple , (192) * FScaleMultiple });
			Global::ChangeBGM("Oaks_Lab.mp3");
		}
	}
	else
	{
		if ("Oaks_Lab.mp3" != Global::PrevBGM)
		{
			Global::ChangeBGM("Oaks_Lab.mp3");
		}
	}
}

void UOaksLabLevel::LevelEnd(ULevel* _NextLevel)
{
	if (nullptr != _NextLevel)
	{
		PlayerHelper::PlayerMoveType = GetPlayer()->GetMoveType();
	}
}