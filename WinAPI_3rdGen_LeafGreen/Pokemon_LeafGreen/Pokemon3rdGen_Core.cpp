#include "Pokemon3rdGen_Core.h"
#include "TitleLevel1.h"
#include "TitleLevel2.h"
#include "TitleLevel3.h"
#include "TitleLevel4.h"
#include "BattleLevel.h"
#include "EvolveLevel.h"
#include "WestFieldLevel.h"
#include "PlayerHome1FLevel.h"
#include "PlayerHome2FLevel.h"
#include "RivalHomeLevel.h"
#include "OaksLabLevel.h"
#include "MyPokemonLevel.h"
#include "MyBagLevel.h"
#include "MyTrainerCardLevel.h"

//std::map<int, PokemonInfo> Pokemon3rdGen_Core::AllPokemonInfo;

Pokemon3rdGen_Core::Pokemon3rdGen_Core()
	: UEngineCore()
{
}

Pokemon3rdGen_Core::~Pokemon3rdGen_Core()
{
}

// °ÔÀÓ½ÃÀÛ
void Pokemon3rdGen_Core::BeginPlay()
{
	MainWindow.SetWindowScale({ FScreen_X, FScreen_Y });
	MainWindow.SetClearColor(Color8Bit::BlackA);
	SetFrame(60);

	//AddFontResourceExA("PokemonGSK2.ttf", FR_PRIVATE, 0);

	{
		FieldPath.MoveParent();
		FieldPath.Move("Resources");

		std::list<UEngineFile> NewSoundsList = FieldPath.AllFile({ ".wav", ".mp3" }, true);

		for (UEngineFile& File : NewSoundsList)
		{
			UEngineSound::Load(File.GetFullPath());
		}
	}

	{
		FieldPath.Move("Field");

		std::list<UEngineFile> AllFieldGraphicList = FieldPath.AllFile({ ".png", ".bmp" }, true);

		for (UEngineFile& File : AllFieldGraphicList)
		{
			UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
		}
	}

	{
		FieldPath.MoveParent();
		FieldPath.Move("UI");

		std::list<UEngineFile> AllUIGraphicList = FieldPath.AllFile({ ".png", ".bmp" }, true);

		for (UEngineFile& File : AllUIGraphicList)
		{
			UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
		}
	}

	{
		FieldPath.MoveParent();
		FieldPath.Move("Pokemon");

		std::list<UEngineFile> AllUIGraphicList = FieldPath.AllFile({ ".png", ".bmp" }, true);

		for (UEngineFile& File : AllUIGraphicList)
		{
			UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
		}

		UEngineResourcesManager::GetInst().CuttingImage("1st_Gen_Front_Back_1.png", 12, 17);
		UEngineResourcesManager::GetInst().CuttingImage("1st_Gen_Front_Back_2.png", 12, 17);
		UEngineResourcesManager::GetInst().CuttingImage("1st_Gen_Front_Back_3.png", 12, 17);
		UEngineResourcesManager::GetInst().CuttingImage("1st_Gen_Dot.png", 20, 16);
	}

	{
		FieldPath.MoveParent();
		FieldPath.Move("Battle");

		std::list<UEngineFile> AllUIGraphicList = FieldPath.AllFile({ ".png", ".bmp" }, true);

		for (UEngineFile& File : AllUIGraphicList)
		{
			UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
		}
	}

	{
		{
			PokemonInfo Info;
			Info.DexNo = 1;
			Info.Tribe = "ÀÌ»óÇØ¾¾";
			Info.Type1 = EType::Ç®;
			Info.Type2 = EType::µ¶;
			Info.BHp = 45.0f;
			Info.BAtk = 49.0f;
			Info.BDef = 49.0f;
			Info.BSAtk = 65.0f;
			Info.BSDef = 65.0f;
			Info.BSpd = 45.0f;
			Info.Ability1 = "½É·Ï";
			Info.Genderper = 875;
			Info.EvolveLevel = 16;
			Info.NextEvolveDexNo = 2;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		{
			PokemonInfo Info;
			Info.DexNo = 2;
			Info.Tribe = "ÀÌ»óÇØÇ®";
			Info.Type1 = EType::Ç®;
			Info.Type2 = EType::µ¶;
			Info.BHp = 60.0f;
			Info.BAtk = 62.0f;
			Info.BDef = 63.0f;
			Info.BSAtk = 80.0f;
			Info.BSDef = 80.0f;
			Info.BSpd = 60.0f;
			Info.Ability1 = "½É·Ï";
			Info.Genderper = 875;
			Info.EvolveLevel = 32;
			Info.NextEvolveDexNo = 3;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		{
			PokemonInfo Info;
			Info.DexNo = 3;
			Info.Tribe = "ÀÌ»óÇØ²É";
			Info.Type1 = EType::Ç®;
			Info.Type2 = EType::µ¶;
			Info.BHp = 80.0f;
			Info.BAtk = 82.0f;
			Info.BDef = 83.0f;
			Info.BSAtk = 100.0f;
			Info.BSDef = 100.0f;
			Info.BSpd = 80.0f;
			Info.Ability1 = "½É·Ï";
			Info.Genderper = 875;
			Info.EvolveLevel = 101;
			Info.NextEvolveDexNo = 0;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		{
			PokemonInfo Info;
			Info.DexNo = 4;
			Info.Tribe = "ÆÄÀÌ¸®";
			Info.Type1 = EType::ºÒ²É;
			Info.BHp = 39.0f;
			Info.BAtk = 52.0f;
			Info.BDef = 43.0f;
			Info.BSAtk = 60.0f;
			Info.BSDef = 50.0f;
			Info.BSpd = 65.0f;
			Info.Ability1 = "¸ÍÈ­";
			Info.Genderper = 875;
			Info.EvolveLevel = 16;
			Info.NextEvolveDexNo = 5;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		{
			PokemonInfo Info;
			Info.DexNo = 5;
			Info.Tribe = "¸®ÀÚµå";
			Info.Type1 = EType::ºÒ²É;
			Info.BHp = 58.0f;
			Info.BAtk = 64.0f;
			Info.BDef = 58.0f;
			Info.BSAtk = 80.0f;
			Info.BSDef = 65.0f;
			Info.BSpd = 80.0f;
			Info.Ability1 = "¸ÍÈ­";
			Info.Genderper = 875;
			Info.EvolveLevel = 36;
			Info.NextEvolveDexNo = 6;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		{
			PokemonInfo Info;
			Info.DexNo = 6;
			Info.Tribe = "¸®ÀÚ¸ù";
			Info.Type1 = EType::ºÒ²É;
			Info.Type2 = EType::ºñÇà;
			Info.BHp = 78.0f;
			Info.BAtk = 84.0f;
			Info.BDef = 78.0f;
			Info.BSAtk = 109.0f;
			Info.BSDef = 85.0f;
			Info.BSpd = 100.0f;
			Info.Ability1 = "¸ÍÈ­";
			Info.Genderper = 875;
			Info.EvolveLevel = 101;
			Info.NextEvolveDexNo = 0;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		{
			PokemonInfo Info;
			Info.DexNo = 7;
			Info.Tribe = "²¿ºÎ±â";
			Info.Type1 = EType::¹°;
			Info.BHp = 44.0f;
			Info.BAtk = 48.0f;
			Info.BDef = 65.0f;
			Info.BSAtk = 50.0f;
			Info.BSDef = 64.0f;
			Info.BSpd = 43.0f;
			Info.Ability1 = "±Þ·ù";
			Info.Genderper = 875;
			Info.EvolveLevel = 16;
			Info.NextEvolveDexNo = 8;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		{
			PokemonInfo Info;
			Info.DexNo = 8;
			Info.Tribe = "¾î´ÏºÎ±â";
			Info.Type1 = EType::¹°;
			Info.BHp = 59.0f;
			Info.BAtk = 63.0f;
			Info.BDef = 80.0f;
			Info.BSAtk = 65.0f;
			Info.BSDef = 80.0f;
			Info.BSpd = 58.0f;
			Info.Ability1 = "±Þ·ù";
			Info.Genderper = 875;
			Info.EvolveLevel = 36;
			Info.NextEvolveDexNo = 9;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		{
			PokemonInfo Info;
			Info.DexNo = 9;
			Info.Tribe = "°ÅºÏ¿Õ";
			Info.Type1 = EType::¹°;
			Info.BHp = 79.0f;
			Info.BAtk = 83.0f;
			Info.BDef = 100.0f;
			Info.BSAtk = 85.0f;
			Info.BSDef = 105.0f;
			Info.BSpd = 78.0f;
			Info.Ability1 = "±Þ·ù";
			Info.Genderper = 875;
			Info.EvolveLevel = 101;
			Info.NextEvolveDexNo = 0;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		{
			PokemonInfo Info;
			Info.DexNo = 16;
			Info.Tribe = "±¸±¸";
			Info.Type1 = EType::³ë¸»;
			Info.Type2 = EType::ºñÇà;
			Info.BHp = 40.0f;
			Info.BAtk = 45.0f;
			Info.BDef = 40.0f;
			Info.BSAtk = 35.0f;
			Info.BSDef = 35.0f;
			Info.BSpd = 56.0f;
			Info.Ability1 = "³¯Ä«·Î¿î ´«";
			Info.Genderper = 500;
			Info.EvolveLevel = 18;
			Info.NextEvolveDexNo = 17;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		{
			PokemonInfo Info;
			Info.DexNo = 17;
			Info.Tribe = "ÇÇÁÔ";
			Info.Type1 = EType::³ë¸»;
			Info.Type2 = EType::ºñÇà;
			Info.BHp = 63.0f;
			Info.BAtk = 60.0f;
			Info.BDef = 55.0f;
			Info.BSAtk = 50.0f;
			Info.BSDef = 50.0f;
			Info.BSpd = 71.0f;
			Info.Ability1 = "³¯Ä«·Î¿î ´«";
			Info.Genderper = 500;
			Info.EvolveLevel = 36;
			Info.NextEvolveDexNo = 18;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		{
			PokemonInfo Info;
			Info.DexNo = 18;
			Info.Tribe = "ÇÇÁÔÅõ";
			Info.Type1 = EType::³ë¸»;
			Info.Type2 = EType::ºñÇà;
			Info.BHp = 83.0f;
			Info.BAtk = 80.0f;
			Info.BDef = 75.0f;
			Info.BSAtk = 70.0f;
			Info.BSDef = 70.0f;
			Info.BSpd = 91.0f;
			Info.Ability1 = "³¯Ä«·Î¿î ´«";
			Info.Genderper = 500;
			Info.EvolveLevel = 101;
			Info.NextEvolveDexNo = 0;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		{
			PokemonInfo Info;
			Info.DexNo = 19;
			Info.Tribe = "²¿·¿";
			Info.Type1 = EType::³ë¸»;
			Info.BHp = 30.0f;
			Info.BAtk = 56.0f;
			Info.BDef = 35.0f;
			Info.BSAtk = 25.0f;
			Info.BSDef = 35.0f;
			Info.BSpd = 72.0f;
			Info.Ability1 = "µµÁÖ";
			Info.Ability2 = "±Ù¼º";
			Info.Genderper = 500;
			Info.EvolveLevel = 20;
			Info.NextEvolveDexNo = 20;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		{
			PokemonInfo Info;
			Info.DexNo = 20;
			Info.Tribe = "·¹Æ®¶ó";
			Info.Type1 = EType::³ë¸»;
			Info.BHp = 55.0f;
			Info.BAtk = 81.0f;
			Info.BDef = 60.0f;
			Info.BSAtk = 50.0f;
			Info.BSDef = 70.0f;
			Info.BSpd = 97.0f;
			Info.Ability1 = "µµÁÖ";
			Info.Ability2 = "±Ù¼º";
			Info.Genderper = 500;
			Info.EvolveLevel = 101;
			Info.NextEvolveDexNo = 0;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		{
			PokemonInfo Info;
			Info.DexNo = 74;
			Info.Tribe = "²¿¸¶µ¹";
			Info.Type1 = EType::¹ÙÀ§;
			Info.Type1 = EType::¶¥;
			Info.BHp = 40.0f;
			Info.BAtk = 80.0f;
			Info.BDef = 100.0f;
			Info.BSAtk = 30.0f;
			Info.BSDef = 30.0f;
			Info.BSpd = 20.0f;
			Info.Ability1 = "µ¹¸Ó¸®";
			Info.Ability2 = "¿Ë°ñÂü";
			Info.Genderper = 500;
			Info.EvolveLevel = 25;
			Info.NextEvolveDexNo = 75;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		{
			PokemonInfo Info;
			Info.DexNo = 75;
			Info.Tribe = "µ¥±¸¸®";
			Info.Type1 = EType::¹ÙÀ§;
			Info.Type1 = EType::¶¥;
			Info.BHp = 55.0f;
			Info.BAtk = 95.0f;
			Info.BDef = 115.0f;
			Info.BSAtk = 45.0f;
			Info.BSDef = 45.0f;
			Info.BSpd = 35.0f;
			Info.Ability1 = "µ¹¸Ó¸®";
			Info.Ability2 = "¿Ë°ñÂü";
			Info.Genderper = 500;
			Info.EvolveLevel = 101;
			Info.NextEvolveDexNo = 76;
			Info.UseItemEvolve = true;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		{
			PokemonInfo Info;
			Info.DexNo = 76;
			Info.Tribe = "µü±¸¸®";
			Info.Type1 = EType::¹ÙÀ§;
			Info.Type1 = EType::¶¥;
			Info.BHp = 80.0f;
			Info.BAtk = 110.0f;
			Info.BDef = 130.0f;
			Info.BSAtk = 55.0f;
			Info.BSDef = 65.0f;
			Info.BSpd = 45.0f;
			Info.Ability1 = "µ¹¸Ó¸®";
			Info.Ability2 = "¿Ë°ñÂü";
			Info.Genderper = 500;
			Info.EvolveLevel = 101;
			Info.NextEvolveDexNo = 0;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}

		{
			PokemonInfo Info;
			Info.DexNo = 95;
			Info.Tribe = "·Õ½ºÅæ";
			Info.Type1 = EType::¹ÙÀ§;
			Info.Type1 = EType::¶¥;
			Info.BHp = 35.0f;
			Info.BAtk = 45.0f;
			Info.BDef = 160.0f;
			Info.BSAtk = 30.0f;
			Info.BSDef = 45.0f;
			Info.BSpd = 70.0f;
			Info.Ability1 = "µ¹¸Ó¸®";
			Info.Ability2 = "¿Ë°ñÂü";
			Info.Genderper = 500;
			Info.EvolveLevel = 101;
			Info.NextEvolveDexNo = 208;
			Info.UseItemEvolve = true;
			Info.CalImageNo(Info.DexNo);

			AllPokemonInfo[Info.DexNo] = Info;
		}
	}

	{
		CreateLevel<UTitleLevel1>("TitleLevel1");
		CreateLevel<UTitleLevel2>("TitleLevel2");
		CreateLevel<UTitleLevel3>("TitleLevel3");
		CreateLevel<UTitleLevel4>("TitleLevel4");

		CreateLevel<UBattleLevel>("BattleLevel");
		CreateLevel<UEvolveLevel>("EvolveLevel");

		CreateLevel<UWestFieldLevel>("WestFieldLevel");
		CreateLevel<UPlayerHome1FLevel>("PlayerHome1FLevel");
		CreateLevel<UPlayerHome2FLevel>("PlayerHome2FLevel");
		CreateLevel<URivalHomeLevel>("RivalHomeLevel");
		CreateLevel<UOaksLabLevel>("OaksLabLevel");

		CreateLevel<UMyPokemonLevel>("MyPokemonLevel");
		CreateLevel<UMyBagLevel>("MyBagLevel");
		CreateLevel<UMyTrainerCardLevel>("MyTrainerCardLevel");
	}

	ChangeLevel("TitleLevel1");
}

void Pokemon3rdGen_Core::Tick(float _DeltaTime)
{
	UEngineCore::Tick(_DeltaTime);

	if (true == UEngineInput::IsDown('9'))
	{
		GEngine->EngineDebugSwitch();
	}
}

void Pokemon3rdGen_Core::End()
{
}

void Pokemon3rdGen_Core::AddEntry(int _DexNo, int _Level)
{
	if (6 > Entry.size())
	{
		PokemonInfo info = AllPokemonInfo[_DexNo];
		info.PokemonInfo::CalStatus(_Level);
		info.PlayerPokemon = true;
		if (0 == info.MeetLevel)
		{
			info.MeetLevel = _Level;
		}
		Entry.push_back(info);
	}
}
