#include "RivalHomeLevel.h"

URivalHomeLevel::URivalHomeLevel()
{
}

URivalHomeLevel::~URivalHomeLevel()
{
}

void URivalHomeLevel::BeginPlay()
{
	UFieldLevel::BeginPlay();

	IsOutside = false;

	Ground = SpawnActor<ARivalHomeGround>();
	Door = SpawnActor<ARivalHomeDoor>();

	Door->SetActorLocation({ (80 + (FTileScale / 2)) * FScaleMultiple , (160 + (FTileScale / 2)) * FScaleMultiple });
}

void URivalHomeLevel::Tick(float _DeltaTime)
{
}

void URivalHomeLevel::LevelStart(ULevel* _PrevLevel)
{
	Global::GColMapImage = Ground->GetColMapImage();
	GetPlayer()->SetMoveType(PlayerHelper::PlayerMoveType);
	if (EMoveType::Bike == GetPlayer()->GetMoveType())
	{
		Global::ChangeBGM("Pallet_Town.mp3");
		GetPlayer()->SetMoveType(PlayerHelper::PrevMoveType);
	}

	UFieldLevel* Field = dynamic_cast<UFieldLevel*>(_PrevLevel);
	if (nullptr != Field && UEngineString::ToUpper("TitleLevel4") != Field->GetName())
	{
		if (UEngineString::ToUpper("WestFieldLevel") == Field->GetName())
		{
			GetPlayer()->SetCharacterDir(EDirState::Up);
			GetPlayer()->SetActorLocation({ (80 + (FTileScale / 2)) * FScaleMultiple , (128) * FScaleMultiple });
		}

		if (UEngineString::ToUpper("WestFieldLevel") != Field->GetName())
		{
			Global::ChangeBGM("Pallet_Town.mp3");
		}
	}
	else
	{
		if ("Pallet_Town.mp3" != Global::PrevBGM)
		{
			Global::ChangeBGM("Pallet_Town.mp3");
		}
	}
}

void URivalHomeLevel::LevelEnd(ULevel* _NextLevel)
{
	if (nullptr != _NextLevel)
	{
		PlayerHelper::PlayerMoveType = GetPlayer()->GetMoveType();
	}
}