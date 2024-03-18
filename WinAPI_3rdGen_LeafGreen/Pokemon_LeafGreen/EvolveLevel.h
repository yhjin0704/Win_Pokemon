#pragma once
#include <EngineCore\Level.h>
#include "EvolveBackGround.h"
#include "EvolvePokemon.h"
#include "PokemonInfo.h"

class UEvolveLevel : public ULevel
{
public:
	// constrcuter destructer
	UEvolveLevel();
	~UEvolveLevel();

	// delete Function
	UEvolveLevel(const UEvolveLevel& _Other) = delete;
	UEvolveLevel(UEvolveLevel&& _Other) noexcept = delete;
	UEvolveLevel& operator=(const UEvolveLevel& _Other) = delete;
	UEvolveLevel& operator=(UEvolveLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _PrevLevel) override;
	void LevelEnd(ULevel* _NextLevel) override;

private:
	AEvolveBackGround* BackGround;
	AEvolvePokemon* EvolvePokemonRenderer;

	std::string PrevLevelName = "";

	std::list<PokemonInfo> Entry;
	std::list<PokemonInfo>::iterator EntryIter;

	PokemonInfo MyPokemon;
	PokemonInfo EvolvePokemon;

	int Order = 0;
	int Count = 0;
	float Delay = 0.0f;
};

