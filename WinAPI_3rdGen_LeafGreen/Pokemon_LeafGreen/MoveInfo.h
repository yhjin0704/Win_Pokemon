#pragma once
#include <string>
#include "PokemonHelper.h"
#include "BattleHelper.h"

class MoveInfo
{
public:
	// constrcuter destructer
	MoveInfo();
	~MoveInfo();

	std::string Name = "";
	EType Type = EType::None;
	EPSMove Caterory = EPSMove::º¯È­;
	int Power = 0;
	int Acc = 0;
	int MaxPP = 0;
	int PP = 0;

protected:

private:

};

