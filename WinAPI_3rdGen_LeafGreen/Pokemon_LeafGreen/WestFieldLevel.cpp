#include "WestFieldLevel.h"
#include "Player.h"
#include "WestFieldGround.h"
#include "PlayerHomeDoorOut.h"
#include <EngineCore\EngineResourcesManager.h>
#include <EngineBase\EngineFile.h>
#include "Global.h"
#include "PlayerHelper.h"

UWestFieldLevel::UWestFieldLevel()
{
}

UWestFieldLevel::~UWestFieldLevel()
{
}

void UWestFieldLevel::BeginPlay()
{
	UFieldLevel::BeginPlay();

	Ground = SpawnActor<AWestFieldGround>();
	PlayerHomeDoor = SpawnActor<APlayerHomeDoorOut>();
	RivalHomeDoor = SpawnActor<ARivalHomeDoorOut>();
	OaksLabDoor = SpawnActor<AOaksLabDoorOut>();

	PlayerHomeDoor->SetActorLocation({ (1136 + (FTileScale / 2)) * FScaleMultiple , (2000 + (FTileScale / 2)) * FScaleMultiple });
	RivalHomeDoor->SetActorLocation({ (1280 + (FTileScale / 2)) * FScaleMultiple , (2000 + (FTileScale / 2)) * FScaleMultiple });
	OaksLabDoor->SetActorLocation({ (1296 + (FTileScale / 2)) * FScaleMultiple , (2096 + (FTileScale / 2)) * FScaleMultiple });

	Player->SetActorLocation({ (1136 + (FTileScale / 2)) * FScaleMultiple , (2032) * FScaleMultiple });
}

void UWestFieldLevel::Tick(float _DeltaTime)
{
	if (GetPlayer()->GetActorLocation().iY() == (1888 * IScaleMultiple))
	{
		if ("Route_1.mp3" != Global::PrevBGM)
		{
			Global::ChangeBGM("Route_1.mp3");
		}
	}
	if (GetPlayer()->GetActorLocation().iY() == (1904 * IScaleMultiple))
	{
		if ("Pallet_Town.mp3" != Global::PrevBGM)
		{
			Global::ChangeBGM("Pallet_Town.mp3");
		}
	}
}

void UWestFieldLevel::LevelStart(ULevel* _PrevLevel)
{
	Global::GColMapImage = Ground->GetColMapImage();
	GetPlayer()->SetMoveType(PlayerHelper::PlayerMoveType);

	UFieldLevel* Field = dynamic_cast<UFieldLevel*>(_PrevLevel);
	if (nullptr != Field && UEngineString::ToUpper("TitleLevel4") != Field->GetName())
	{
		if (UEngineString::ToUpper("PlayerHome1FLevel") == Field->GetName())
		{
			GetPlayer()->SetCharacterDir(EDirState::Down);
			GetPlayer()->SetActorLocation({ (1136 + (FTileScale / 2)) * FScaleMultiple , (2032) * FScaleMultiple });
		}
		else if (UEngineString::ToUpper("RivalHomeLevel") == Field->GetName())
		{
			GetPlayer()->SetCharacterDir(EDirState::Down);
			GetPlayer()->SetActorLocation({ (1280 + (FTileScale / 2)) * FScaleMultiple , (2032) * FScaleMultiple });
		}
		else if (UEngineString::ToUpper("OaksLabLevel") == Field->GetName())
		{
			GetPlayer()->SetCharacterDir(EDirState::Down);
			GetPlayer()->SetActorLocation({ (1296 + (FTileScale / 2)) * FScaleMultiple , (2128) * FScaleMultiple });
			Global::ChangeBGM("Pallet_Town.mp3");
		}
		else if (UEngineString::ToUpper("BattleLevel") == Field->GetName() || UEngineString::ToUpper("EvolveLevel") == Field->GetName())
		{
			if (GetPlayer()->GetActorLocation().iY() <= (1888 * IScaleMultiple))
			{
				if ("Route_1.mp3" != Global::PrevBGM)
				{
					Global::ChangeBGM("Route_1.mp3");
				}
			}
			if (GetPlayer()->GetActorLocation().iY() >= (1904 * IScaleMultiple))
			{
				if ("Pallet_Town.mp3" != Global::PrevBGM)
				{
					Global::ChangeBGM("Pallet_Town.mp3");
				}
			}
		}
	}
	else
	{
		if (GetPlayer()->GetActorLocation().iY() <= (1888 * IScaleMultiple))
		{
			if ("Route_1.mp3" != Global::PrevBGM)
			{
				Global::ChangeBGM("Route_1.mp3");
			}
		}
		if (GetPlayer()->GetActorLocation().iY() >= (1904 * IScaleMultiple))
		{
			if ("Pallet_Town.mp3" != Global::PrevBGM)
			{
				Global::ChangeBGM("Pallet_Town.mp3");
			}
		}
	}
}

void UWestFieldLevel::LevelEnd(ULevel* _NextLevel)
{
	if (nullptr != _NextLevel)
	{
		PlayerHelper::PlayerMoveType = GetPlayer()->GetMoveType();
	}
}