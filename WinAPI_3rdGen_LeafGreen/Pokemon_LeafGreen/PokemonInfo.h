#pragma once
#include <EngineCore/Actor.h>
#include <EngineBase\EngineRandom.h>
#include "PokemonHelper.h"

class PokemonInfo 
{
public:
	// constrcuter destructer
	PokemonInfo();
	~PokemonInfo();

	void SetName(std::string _Name)
	{
		Name = _Name;
	}

	void CalStatus(int _Level);
	void CalImageNo(int _DexNo);

	void SetLevel(int _Level);
	void SetMeetLevel(int _Level)
	{
		MeetLevel = _Level;
	}
	void LevelUp();
	void LevelUpCheck();

	void Evolve();
	bool EvolveCheck();

	int DexNo = 0;
	std::string Tribe = "";
	EType Type1 = EType::None;
	EType Type2 = EType::None;
	float BHp = 1;
	float BAtk = 1;
	float BDef = 1;
	float BSAtk = 1;
	float BSDef = 1;
	float BSpd = 1;
	std::string Ability1 = "";
	std::string Ability2 = "";
	int Genderper = 1000;
	int EvolveLevel = 101;
	int NextEvolveDexNo = 0;
	bool UseItemEvolve = false;
	std::string EvolveItem = "";

	int FrontImage;
	int BackImage;
	int DotAnimationStart;
	int DotAnimationEnd;

	bool PlayerPokemon = false;
	std::string Name = "";
	int Level = 1;
	int MeetLevel = 0;
	int Exp = 0;
	int MaxExp = Level * Level * Level;
	bool NowLevelUp = false;
	bool CanEvolve = false;
	//true -> male, false -> female
	bool Gender = true;
	ENature Nature = ENature::Hardy;
	std::string KNature = "노력하는";
	std::string Ability = Ability1;

	float IVHp = 0;
	float IVAtk = 0;
	float IVDef = 0;
	float IVSAtk = 0;
	float IVSDef = 0;
	float IVSpd = 0;

	float EVHp = 0;
	float EVAtk = 0;
	float EVDef = 0;
	float EVSAtk = 0;
	float EVSDef = 0;
	float EVSpd = 0;

	int MaxHp = 1;
	int Hp = MaxHp;
	int Atk = 1;
	int Def = 1;
	int SAtk = 1;
	int SDef = 1;
	int Spd = 1;

	float NAtk = 1.0f;
	float NDef = 1.0f;
	float NSAtk = 1.0f;
	float NSDef = 1.0f;
	float NSpd = 1.0f;

private:
};

