#pragma once
#include "PokemonHelper.h"

enum class EBattleSequence
{
	Start,
	SetPokemon,
	Change,
	UseItem,
	Catch,
	MyTurn,
	EnemyTurn,
	Run,
	End
};

enum class EBattleSelect
{
	Fight,
	Bag,
	Pokemon,
	Run,
	Move1,
	Move2,
	Move3,
	Move4
};

enum class EPSMove
{
	물리,
	특수,
	변화
};

enum class EUseBall
{
	None,
	MonsterBall,
	GreatBall,
	UltraBall,
	MasterBall
};

class BattleHelper
{
public:
	// constrcuter destructer
	BattleHelper();
	~BattleHelper();

	// delete Function
	BattleHelper(const BattleHelper& _Other) = delete;
	BattleHelper(BattleHelper&& _Other) noexcept = delete;
	BattleHelper& operator=(const BattleHelper& _Other) = delete;
	BattleHelper& operator=(BattleHelper&& _Other) noexcept = delete;

	static int CalDamage(EPSMove _Category, bool _AccCheck, int _CriCheck, int _ALevel, int _AAtk, int _ASAtk, EType _AType1, EType _AType2, int _DDef, int _DSDef, EType _DType1, EType _DType2, int _MPower, EType _MType);
	//_EnemyCategory 야생 = 1 트레이너 = 1.5
	static int CalExp(int _EnemyLevel, float _EnemyCategory);

	static bool IsSwitch;

	static EUseBall UseBall;

protected:

private:

};

