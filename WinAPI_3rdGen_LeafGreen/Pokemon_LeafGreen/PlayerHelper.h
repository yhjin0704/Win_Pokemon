#pragma once
#include <EngineBase/EngineMath.h>
#include <list>
#include "PokemonInfo.h"
#include "Global.h"

class PlayerHelper
{
public:
	// constrcuter destructer
	PlayerHelper();
	~PlayerHelper();

	// delete Function
	PlayerHelper(const PlayerHelper& _Other) = delete;
	PlayerHelper(PlayerHelper&& _Other) noexcept = delete;
	PlayerHelper& operator=(const PlayerHelper& _Other) = delete;
	PlayerHelper& operator=(PlayerHelper&& _Other) noexcept = delete;

	static std::string PlayerName;
	static EMoveType PlayerMoveType;
	static EMoveType PrevMoveType;
	static bool IsUseMenu;
	static bool PlayerPause;
	static inline std::list<PokemonInfo> EntryPokemon = std::list<PokemonInfo>();
	static Color8Bit EncountGround;
	static bool IsWild;
	static bool IsEncount;

protected:

private:

};

