#include "PlayerHome1FLevel.h"
#include "Player.h"
#include "PlayerHome1FGround.h"
#include "PlayerHomeDoor.h"
#include "PlayerHome1FStairs.h"
#include "WestFieldLevel.h"
#include "PlayerHome2FLevel.h"
#include "global.h"
#include "PlayerHelper.h"

UPlayerHome1FLevel::UPlayerHome1FLevel()
{
}

UPlayerHome1FLevel::~UPlayerHome1FLevel()
{
}

void UPlayerHome1FLevel::BeginPlay()
{
	UFieldLevel::BeginPlay();

	IsOutside = false;

	Ground = SpawnActor<APlayerHome1FGround>();
	Door = SpawnActor<APlayerHomeDoor>();
	Stairs = SpawnActor<APlayerHome1FStairs>();

	Mom = SpawnActor<AMom>();

	Door->SetActorLocation({ (64 + (FTileScale / 2)) * FScaleMultiple , (160 + (FTileScale / 2)) * FScaleMultiple });
	Stairs->SetActorLocation({ (192 + (FTileScale / 2)) * FScaleMultiple , (32 + (FTileScale / 2)) * FScaleMultiple });
	Mom->SetActorLocation({ (128 + (FTileScale / 2)) * FScaleMultiple , (64) * FScaleMultiple });
}

void UPlayerHome1FLevel::Tick(float _DeltaTime)
{
	UFieldLevel::Tick(_DeltaTime);

	Mom->SetActiveUpDownRenderer(Player->GetActorLocation());
	Mom->SetMsgBoxLocation(Player->GetActorLocation());
}

void UPlayerHome1FLevel::LevelStart(ULevel* _PrevLevel)
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
			GetPlayer()->SetActorLocation({ (64 + (FTileScale / 2)) * FScaleMultiple , (128) * FScaleMultiple });
		}
		else if (UEngineString::ToUpper("PlayerHome2FLevel") == Field->GetName())
		{
			GetPlayer()->SetCharacterDir(EDirState::Left);
			GetPlayer()->SetActorLocation({ (160 + (FTileScale / 2)) * FScaleMultiple , (32) * FScaleMultiple });
		}

		if (UEngineString::ToUpper("WestFieldLevel") != Field->GetName() && UEngineString::ToUpper("PlayerHome2FLevel") != Field->GetName())
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

void UPlayerHome1FLevel::LevelEnd(ULevel* _NextLevel)
{
	if (nullptr != _NextLevel)
	{
		PlayerHelper::PlayerMoveType = GetPlayer()->GetMoveType();
	}
}