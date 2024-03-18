#pragma once
#include <EngineCore\Level.h>
#include "PokemonInfo.h"
#include "BattleBackGround.h"
#include "BattleGround.h"
#include "BattlePokemonStatus.h"
#include "BattleTextBox.h"
#include "BattleSelectBox.h"
#include "BattleHelper.h"

class UBattleLevel : public ULevel
{
public:
	// constrcuter destructer
	UBattleLevel();
	~UBattleLevel();

	// delete Function
	UBattleLevel(const UBattleLevel& _Other) = delete;
	UBattleLevel(UBattleLevel&& _Other) noexcept = delete;
	UBattleLevel& operator=(const UBattleLevel& _Other) = delete;
	UBattleLevel& operator=(UBattleLevel&& _Other) noexcept = delete;

	std::string GetPrevLevelName()
	{
		return PrevLevelName;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _PrevLevel) override;
	void LevelEnd(ULevel* _NextLevel) override;

private:
	ABattleBackGround* BackGround;
	ABattleGround* EnemyGround;
	ABattleGround* PlayerGround;
	ABattlePokemonStatus* EnemyStatus;
	ABattlePokemonStatus* PlayerStatus;
	ABattleTextBox* TextBox;
	ABattleSelectBox* SelectBox;

	std::list<PokemonInfo> BattleEntry;
	PokemonInfo MyPokemon;

	PokemonInfo EnemyPokemon;

	std::string PrevLevelName = "";

	EBattleSequence BattleSequence = EBattleSequence::Start;
	EBattleSelect BattleSelectCursor = EBattleSelect::Fight;

	//1~16중 1이면 급소
	bool AccCheck = false;
	int CriCheck = 0;
	int Dmg = 0;

	int GetExp = 0;

	bool FirstTurn = true;
	bool IsDelay = false;
	float Delay = 1.5f;

	int Sequence = 0;
	bool IsPlayerSelect = false;

	PokemonInfo SpawnWildPokemon(int _DexNo, int _Level);
	void TurnChange();
	void CursorMovePos(float _X, float _Y, EBattleSelect _MoveLength, EBattleSelect _MoveWidth);
	void FightBattle(float _DeltaTime, PokemonInfo& _Atker, PokemonInfo& _Defder);
};

