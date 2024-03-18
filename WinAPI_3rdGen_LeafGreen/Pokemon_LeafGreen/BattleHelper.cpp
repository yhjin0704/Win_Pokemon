#include "BattleHelper.h"
#include <cmath>
#include <EngineBase\EngineRandom.h>

bool BattleHelper::IsSwitch = false;

EUseBall BattleHelper::UseBall = EUseBall::None;

BattleHelper::BattleHelper()
{
}

BattleHelper::~BattleHelper()
{
}

int BattleHelper::CalDamage(EPSMove _Category, bool _AccCheck, int _CriCheck, int _ALevel, int _AAtk, int _ASAtk, EType _AType1, EType _AType2, int _DDef, int _DSDef, EType _DType1, EType _DType2, int _MPower, EType _MType)
{
	float ALevel = static_cast<float>(_ALevel);
	float AAtk = static_cast<float>(_AAtk);
	float ASAtk = static_cast<float>(_ASAtk);
	float DDef = static_cast<float>(_DDef);
	float DSDef = static_cast<float>(_DSDef);
	float MPower = static_cast<float>(_MPower);

	int FinalDmg = 1;
	if (true == _AccCheck)
	{
		float CriDmg = 1.0f;
		if (1 == _CriCheck)
		{
			CriDmg = 2.0f;
		}

		float ATypeDmg = 1.0f;
		if (_AType1 == _MType || _AType2 == _MType)
		{
			ATypeDmg = 1.5f;
		}

		float DTypeDmg1 = 1.0f;
		float DTypeDmg2 = 1.0f;

		if (EPSMove::물리 == _Category)
		{
			FinalDmg = std::lround(std::floor((((std::floor(std::floor((std::floor(ALevel * 2.0f / 5.0f) + 2.0f) * MPower * AAtk / 50.0f) / DDef) + 2.0f) * CriDmg) * ATypeDmg * DTypeDmg1 * DTypeDmg2 * std::floor(UEngineRandom::MainRandom.RandomFloat(217, 255) * 100 / 255)) / 100));
		}
		else if (EPSMove::특수 == _Category)
		{
			FinalDmg = std::lround(std::floor((((std::floor(std::floor((std::floor(ALevel * 2.0f / 5.0f) + 2.0f) * MPower * ASAtk / 50.0f) / DSDef) + 2.0f) * CriDmg) * ATypeDmg * DTypeDmg1 * DTypeDmg2 * std::floor(UEngineRandom::MainRandom.RandomFloat(217, 255) * 100 / 255)) / 100));
		}

		if (FinalDmg <= 0)
		{
			if (0.0f == DTypeDmg1 || 0.0f == DTypeDmg2)
			{
				FinalDmg = 0;
			}
			else
			{
				FinalDmg = 1;
			}
		}
	}
	else
	{
		FinalDmg = 0;
	}
	
	return FinalDmg;
}

int BattleHelper::CalExp(int _EnemyLevel, float _EnemyCategory)
{
	int Level2 = _EnemyLevel * _EnemyLevel;
	return std::ceil(static_cast<float>(Level2) * 2.5f * _EnemyCategory);
}