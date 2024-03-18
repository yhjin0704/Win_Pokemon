#include "PlayerHome2FLevel.h"
#include "Player.h"
#include "PlayerHome2FGround.h"
#include "PlayerHome2FStairs.h"
#include "PlayerHome1FLevel.h"
#include "global.h"
#include "PlayerHelper.h"

UPlayerHome2FLevel::UPlayerHome2FLevel()
{
}

UPlayerHome2FLevel::~UPlayerHome2FLevel()
{
}

void UPlayerHome2FLevel::BeginPlay()
{
	UFieldLevel::BeginPlay();

	IsOutside = false;

	Ground = SpawnActor<APlayerHome2FGround>();
	Stairs = SpawnActor<APlayerHome2FStairs>();

	Stairs->SetActorLocation({ (128 + (FTileScale / 2)) * FScaleMultiple , (48 + (FTileScale / 2)) * FScaleMultiple });

	Player->SetActorLocation({ (96 + (FTileScale / 2)) * FScaleMultiple , (112) * FScaleMultiple });
}

void UPlayerHome2FLevel::Tick(float _DeltaTime)
{
}

void UPlayerHome2FLevel::LevelStart(ULevel* _PrevLevel)
{
	Global::GColMapImage = Ground->GetColMapImage();
	GetPlayer()->SetMoveType(PlayerHelper::PlayerMoveType);

	UFieldLevel* Field = dynamic_cast<UFieldLevel*>(_PrevLevel);
	if (nullptr != Field && UEngineString::ToUpper("TitleLevel4") != Field->GetName())
	{
		if (UEngineString::ToUpper("PlayerHome1FLevel") == Field->GetName())
		{
			GetPlayer()->SetCharacterDir(EDirState::Right);
			GetPlayer()->SetActorLocation({ (160 + (FTileScale / 2)) * FScaleMultiple , (48) * FScaleMultiple });
		}

		if (UEngineString::ToUpper("PlayerHome1FLevel") != Field->GetName())
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

void UPlayerHome2FLevel::LevelEnd(ULevel* _NextLevel)
{
	if (nullptr != _NextLevel)
	{
		PlayerHelper::PlayerMoveType = GetPlayer()->GetMoveType();
	}
}