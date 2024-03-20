#include "BattleLevel.h"
#include <EngineCore\EngineCore.h>
#include "Pokemon3rdGen_Core.h"
#include "PlayerHelper.h"
#include "Player.h"
#include "Global.h"

UBattleLevel::UBattleLevel()
{
}

UBattleLevel::~UBattleLevel()
{
}

void UBattleLevel::BeginPlay()
{
	ULevel::BeginPlay();

	BackGround = SpawnActor<ABattleBackGround>();
	EnemyGround = SpawnActor<ABattleGround>();
	PlayerGround = SpawnActor<ABattleGround>();
	EnemyStatus = SpawnActor<ABattlePokemonStatus>();
	PlayerStatus = SpawnActor<ABattlePokemonStatus>();
	TextBox = SpawnActor<ABattleTextBox>();
	SelectBox = SpawnActor<ABattleSelectBox>();

	EnemyGround->SetGroundRenderer("BattleEnemyGround_Grass.png");
	PlayerGround->SetGroundRenderer("BattlePlayerGround_Grass.png");
	EnemyStatus->SetRenderer("BattleEnemyPokemonStatus.png");
	PlayerStatus->SetRenderer("BattlePlayerPokemonStatus.png");
}

void UBattleLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	EnemyStatus->SetDataRenderers(EnemyPokemon, true,
		19.0f, 25.0f,
		101.0f, 25.0f,
		65.0f, 25.0f,
		77.0f, 34.5f);
	PlayerStatus->SetDataRenderers(MyPokemon, false,
		142.0f, 84.0f,
		224.0f, 84.0f,
		188.0f, 84.0f,
		200.0f, 93.5f);

	EnemyGround->SetPokemonRenderer(EnemyPokemon, true);
	PlayerGround->SetPokemonRenderer(MyPokemon, false);

	if (true == UEngineInput::IsDown('P') && false == IsDelay)
	{
		switch (BattleSequence)
		{
		case EBattleSequence::Start:
			BattleSequence = EBattleSequence::SetPokemon;
			break;
		case EBattleSequence::SetPokemon:
			if (MyPokemon.Spd >= EnemyPokemon.Spd)
			{
				BattleSequence = EBattleSequence::MyTurn;
			}
			else
			{
				BattleSequence = EBattleSequence::EnemyTurn;
			}
			break;
		case EBattleSequence::MyTurn:
			switch (BattleSelectCursor)
			{
			case EBattleSelect::Fight:
				IsPlayerSelect = true;
				break;
			case EBattleSelect::Bag:
				GEngine->ChangeLevel("MyBagLevel");
				break;
			case EBattleSelect::Pokemon:
				GEngine->ChangeLevel("MyPokemonLevel");
				break;
			case EBattleSelect::Run:
				BattleSequence = EBattleSequence::Run;
				break;
			case EBattleSelect::Move1:
				break;
			case EBattleSelect::Move2:
				break;
			case EBattleSelect::Move3:
				break;
			case EBattleSelect::Move4:
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}

	switch (BattleSequence)
	{
	case EBattleSequence::SetPokemon:
		TextBox->TextOff();
		TextBox->SetTextTop("가랏 " + MyPokemon.Name + "!");

		IsDelay = true;
		Delay -= _DeltaTime;
		if (0 >= Delay)
		{
			if (MyPokemon.Spd >= EnemyPokemon.Spd)
			{
				IsDelay = false;
				Delay = 1.5f;
				BattleSequence = EBattleSequence::MyTurn;
			}
			else
			{
				IsDelay = false;
				Delay = 1.5f;
				BattleSequence = EBattleSequence::EnemyTurn;
			}
		}
		break;
	case EBattleSequence::Change:
		IsPlayerSelect = false;
		TextBox->TextOff();
		TextBox->SetTextTop("가랏 " + MyPokemon.Name + "!");

		BattleSelectCursor = EBattleSelect::Fight;

		IsDelay = true;
		Delay -= _DeltaTime;
		if (0 >= Delay)
		{
			//후턴인 경우는 교체밖에 없다
			if (false == FirstTurn)
			{
				IsDelay = false;
				Delay = 1.5f;
				BattleSequence = EBattleSequence::EnemyTurn;
			}
			else
			{
				if (MyPokemon.Spd >= EnemyPokemon.Spd)
				{
					IsDelay = false;
					Delay = 1.5f;
					BattleSequence = EBattleSequence::MyTurn;
				}
				else
				{
					IsDelay = false;
					Delay = 1.5f;
					BattleSequence = EBattleSequence::EnemyTurn;
				}
			}
		}
		break;
	case EBattleSequence::UseItem:
		IsPlayerSelect = false;

		TextBox->TextOff();
		TextBox->SetTextTop(PlayerHelper::PlayerName + "(은)는");
		TextBox->SetTextBottom("마스터볼을 사용했다");

		BattleSelectCursor = EBattleSelect::Fight;

		IsDelay = true;
		Delay -= _DeltaTime;
		if (0 >= Delay)
		{
			if (6 > BattleEntry.size())
			{
				switch (BattleHelper::UseBall)
				{
				case EUseBall::MonsterBall:
					//후턴
					if (false == FirstTurn)
					{
						IsDelay = false;
						Delay = 1.5f;
						BattleSequence = EBattleSequence::EnemyTurn;
					}
					else
					{
						if (MyPokemon.Spd >= EnemyPokemon.Spd)
						{
							IsDelay = false;
							Delay = 1.5f;
							BattleSequence = EBattleSequence::MyTurn;
						}
						else
						{
							IsDelay = false;
							Delay = 1.5f;
							BattleSequence = EBattleSequence::EnemyTurn;
						}
					}
					break;
				case EUseBall::GreatBall:
					break;
				case EUseBall::UltraBall:
					break;
				case EUseBall::MasterBall:
					BattleHelper::UseBall = EUseBall::None;

					IsDelay = false;
					Delay = 1.5f;
					BattleSequence = EBattleSequence::Catch;
					break;
				default:
					break;
				}
			}
			else
			{
				BattleHelper::UseBall = EUseBall::None;
				if (false == FirstTurn)
				{
					IsDelay = false;
					Delay = 1.5f;
					BattleSequence = EBattleSequence::EnemyTurn;
				}
				else
				{
					if (MyPokemon.Spd >= EnemyPokemon.Spd)
					{
						IsDelay = false;
						Delay = 1.5f;
						BattleSequence = EBattleSequence::MyTurn;
					}
					else
					{
						IsDelay = false;
						Delay = 1.5f;
						BattleSequence = EBattleSequence::EnemyTurn;
					}
				}
			}
		}
		break;
	case EBattleSequence::Catch:
		IsPlayerSelect = false;

		EnemyGround->SetPokemonActiveOnOff(false);

		TextBox->TextOff();
		TextBox->SetTextTop(PlayerHelper::PlayerName + "(은)는");
		TextBox->SetTextBottom(EnemyPokemon.Name + "(을)를 잡았다");
		BattleSelectCursor = EBattleSelect::Fight;

		IsDelay = true;
		Delay -= _DeltaTime;
		if (0 >= Delay)
		{
			if (6 > BattleEntry.size())
			{
				EnemyPokemon.PlayerPokemon = true;
				BattleEntry.push_back(EnemyPokemon);
			}
			else
			{
				EnemyPokemon.PlayerPokemon = true;
				dynamic_cast<Pokemon3rdGen_Core*>(GEngine)->GetBox().push_back(EnemyPokemon);

			}

			IsDelay = false;
			Delay = 1.5f;
			GEngine->ChangeLevel(PrevLevelName);
		}
		break;
	case EBattleSequence::MyTurn:
		if (false == IsPlayerSelect)
		{
			TextBox->TextOff();
			TextBox->SetTextTop(MyPokemon.Name + "(은)는");
			TextBox->SetTextBottom("무엇을 할까?");

			SelectBox->SetSelectBoxActive(true);
			SelectBox->SetSelectBoxTextActive(true);
			SelectBox->SetCursorActive(true);

			switch (BattleSelectCursor)
			{
			case EBattleSelect::Fight:
				CursorMovePos(132.0f, 129.0f, EBattleSelect::Pokemon, EBattleSelect::Bag);
				break;
			case EBattleSelect::Bag:
				CursorMovePos(188.0f, 129.0f, EBattleSelect::Run, EBattleSelect::Fight);
				break;
			case EBattleSelect::Pokemon:
				CursorMovePos(132.0f, 145.0f, EBattleSelect::Fight, EBattleSelect::Run);
				break;
			case EBattleSelect::Run:
				CursorMovePos(188.0f, 145.0f, EBattleSelect::Bag, EBattleSelect::Pokemon);
				break;
			default:
				break;
			}

			if (true == BattleHelper::IsSwitch)
			{
				TurnChange();

				TextBox->TextOff();

				SelectBox->SetSelectBoxActive(false);
				SelectBox->SetSelectBoxTextActive(false);
				SelectBox->SetCursorActive(false);

				BattleHelper::IsSwitch = false;
				BattleSequence = EBattleSequence::Change;
			}
			if (EUseBall::None != BattleHelper::UseBall)
			{
				TurnChange();

				TextBox->TextOff();

				SelectBox->SetSelectBoxActive(false);
				SelectBox->SetSelectBoxTextActive(false);
				SelectBox->SetCursorActive(false);

				BattleSequence = EBattleSequence::UseItem;
			}
		}
		else
		{
			FightBattle(_DeltaTime, MyPokemon, EnemyPokemon);
		}
		break;
	case EBattleSequence::EnemyTurn:
		IsPlayerSelect = false;
		FightBattle(_DeltaTime, EnemyPokemon, MyPokemon);
		break;
	case EBattleSequence::Run:
		IsPlayerSelect = false;
		TextBox->TextOff();
		TextBox->SetTextTop("성공적으로 도망쳤다!");

		SelectBox->SetSelectBoxActive(false);
		SelectBox->SetSelectBoxTextActive(false);
		SelectBox->SetCursorActive(false);

		IsDelay = true;
		Delay -= _DeltaTime;
		if (0 >= Delay)
		{
			IsDelay = false;
			Delay = 1.5f;
			BattleSequence = EBattleSequence::End;
		}
		break;
	case EBattleSequence::End:
		IsPlayerSelect = false;
		MyPokemon.LevelUpCheck();
		if (true == MyPokemon.CanEvolve)
		{
			GEngine->ChangeLevel("EvolveLevel");
		}
		else
		{
			GEngine->ChangeLevel(PrevLevelName);
		}
		break;
	default:
		break;
	}
}

void UBattleLevel::LevelStart(ULevel* _PrevLevel)
{
	if (UEngineString::ToUpper("MyPokemonLevel") != _PrevLevel->GetName()
		&& UEngineString::ToUpper("MyBagLevel") != _PrevLevel->GetName()
		&& UEngineString::ToUpper("EvolveLevel") != _PrevLevel->GetName())
	{
		PrevLevelName = _PrevLevel->GetName();
		BattleSequence = EBattleSequence::Start;
		BattleSelectCursor = EBattleSelect::Fight;

		FirstTurn = true;
	}
	else if (UEngineString::ToUpper("EvolveLevel") == _PrevLevel->GetName())
	{
		GEngine->ChangeLevel(PrevLevelName);
	}

	BattleEntry = dynamic_cast<Pokemon3rdGen_Core*>(GEngine)->GetEntry();
	MyPokemon = BattleEntry.front();

	TextBox->TextOff();

	SelectBox->SetSelectBoxActive(false);
	SelectBox->SetSelectBoxTextActive(false);
	SelectBox->SetCursorActive(false);

	EnemyGround->SetPokemonActiveOnOff(true);

	Sequence = 0;
	IsPlayerSelect = false;
	GetExp;

	if (true == PlayerHelper::IsWild)
	{
		if (UEngineString::ToUpper("MyPokemonLevel") != _PrevLevel->GetName()
			&& UEngineString::ToUpper("MyBagLevel") != _PrevLevel->GetName())
		{
			Global::ChangeBGM("Wild_Battle.mp3");
			if (Color8Bit(1, 255, 0, 0) == PlayerHelper::EncountGround)
			{
				int EncountRate = UEngineRandom::MainRandom.RandomInt(1, 2);
				if (1 == EncountRate)
				{
					EnemyPokemon = SpawnWildPokemon(16, UEngineRandom::MainRandom.RandomInt(2, 5));
				}
				else
				{
					EnemyPokemon = SpawnWildPokemon(19, UEngineRandom::MainRandom.RandomInt(2, 4));
				}
			}
			TextBox->SetTextTop("앗! 야생의 " + EnemyPokemon.Name + "(이)가 나타났다");
			Delay = 1.5f;
		}
	}
}

void UBattleLevel::LevelEnd(ULevel* _NextLevel)
{
	PlayerHelper::IsEncount = false;
	if (UEngineString::ToUpper("MyPokemonLevel") == _NextLevel->GetName()
		|| UEngineString::ToUpper("MyBagLevel") == _NextLevel->GetName())
	{
		PlayerHelper::IsWild = true;
	}
	else
	{
		PlayerHelper::IsWild = false;
	}
	BattleEntry.front() = MyPokemon;
	dynamic_cast<Pokemon3rdGen_Core*>(GEngine)->SetEntry(BattleEntry);
}

PokemonInfo UBattleLevel::SpawnWildPokemon(int _DexNo, int _Level)
{
	PokemonInfo info = Pokemon3rdGen_Core::GetAllPokemonInfo()[_DexNo];
	info.PokemonInfo::CalStatus(_Level);
	if (0 == info.MeetLevel)
	{
		info.MeetLevel = _Level;
	}
	return info;
}

void UBattleLevel::TurnChange()
{
	if (true == FirstTurn)
	{
		FirstTurn = false;
	}
	else
	{
		FirstTurn = true;
	}
}

void UBattleLevel::CursorMovePos(float _X, float _Y, EBattleSelect _MoveLength, EBattleSelect _MoveWidth)
{
	SelectBox->SetCursorLocation(_X, _Y);
	if (true == UEngineInput::IsDown('W') || true == UEngineInput::IsDown('S'))
	{
		BattleSelectCursor = _MoveLength;
	}
	else if (true == UEngineInput::IsDown('A') || true == UEngineInput::IsDown('D'))
	{
		BattleSelectCursor = _MoveWidth;
	}
}

void UBattleLevel::FightBattle(float _DeltaTime, PokemonInfo& _Atker, PokemonInfo& _Defder)
{
	switch (Sequence)
	{
	case 0:
		TurnChange();

		TextBox->TextOff();

		SelectBox->SetSelectBoxActive(false);
		SelectBox->SetSelectBoxTextActive(false);
		SelectBox->SetCursorActive(false);

		
		if (95 > UEngineRandom::MainRandom.RandomInt(1, 100))
		{
			AccCheck = true;
		}

		CriCheck = UEngineRandom::MainRandom.RandomInt(1, 16);
		Dmg = BattleHelper::CalDamage(EPSMove::물리, AccCheck, CriCheck, _Atker.Level, _Atker.Atk, _Atker.SAtk, _Atker.Type1, _Atker.Type2, _Defder.Def, _Defder.SDef, _Defder.Type1, _Defder.Type2, 35, EType::노말);

		_Defder.Hp -= Dmg;
		++Sequence;
		break;
	case 1:
		TextBox->TextOff();
		TextBox->SetTextTop(_Atker.Name + "의");
		TextBox->SetTextBottom("몸통박치기!");

		SelectBox->SetSelectBoxActive(false);
		SelectBox->SetSelectBoxTextActive(false);
		SelectBox->SetCursorActive(false);

		IsDelay = true;
		Delay -= _DeltaTime;
		if (0 >= Delay)
		{
			IsDelay = false;
			Delay = 1.5f;
			++Sequence;
		}
		break;
	case 2:
		if (false == AccCheck)
		{

			TextBox->TextOff();
			TextBox->SetTextTop("그러나 " + _Atker.Name + "의");
			TextBox->SetTextBottom("공격은 빗나갔다!");

			SelectBox->SetSelectBoxActive(false);
			SelectBox->SetSelectBoxTextActive(false);
			SelectBox->SetCursorActive(false);

			IsDelay = true;
			Delay -= _DeltaTime;
			if (0 >= Delay)
			{
				IsDelay = false;
				Delay = 1.5f;
				++Sequence;
			}
		}
		else
		{
			AccCheck = false;
			++Sequence;
		}
		break;
	case 3:
		if (1 == CriCheck && Dmg != 0)
		{
			TextBox->TextOff();
			TextBox->SetTextTop("급소에 맞았다!");

			IsDelay = true;
			Delay -= _DeltaTime;
			if (0 >= Delay)
			{
				IsDelay = false;
				Delay = 1.5f;
				++Sequence;
			}
		}
		else
		{
			++Sequence;
		}
		break;
	case 4:
		if (0 >= _Defder.Hp)
		{
			TextBox->TextOff();
			TextBox->SetTextTop(_Defder.Name + "(은)는");
			TextBox->SetTextBottom("쓰러졌다");

			if (true == _Atker.PlayerPokemon)
			{
				IsDelay = true;
				Delay -= _DeltaTime;
				if (0 >= Delay)
				{
					IsDelay = false;
					Delay = 1.5f;
					++Sequence;
				}
			}

			IsDelay = true;
			Delay -= _DeltaTime;
			if (0 >= Delay)
			{
				IsDelay = false;
				Delay = 1.5f;
				BattleSequence = EBattleSequence::End;
			}
		}
		else
		{
			Sequence = 0;
			if (EBattleSequence::EnemyTurn == BattleSequence)
			{
				BattleSequence = EBattleSequence::MyTurn;
			}
			else if (EBattleSequence::MyTurn == BattleSequence)
			{
				BattleSequence = EBattleSequence::EnemyTurn;
			}
		}
		break;
	case 5:
		if (true == PlayerHelper::IsWild)
		{
			Global::ChangeBGM("Victory_Wild.mp3");
			GetExp = BattleHelper::CalExp(_Defder.Level, 1.0f);
			GetExp += 20000;
			_Atker.Exp += GetExp;
		}
		++Sequence;
		break;
	case 6:
		TextBox->TextOff();
		TextBox->SetTextTop(_Atker.Name + "(은)는");
		TextBox->SetTextBottom(std::to_string(GetExp) + "경험치를 받았다!");

		IsDelay = true;
		Delay -= _DeltaTime;
		if (0 >= Delay)
		{
			IsDelay = false;
			Delay = 1.5f;
			BattleSequence = EBattleSequence::End;
		}
		break;
	default:
		break;
	}
}