#pragma once
#include <EngineCore/Actor.h>
#include "PokemonInfo.h"

class AEvolvePokemon : public AActor
{
public:
	// constrcuter destructer
	AEvolvePokemon();
	~AEvolvePokemon();

	// delete Function
	AEvolvePokemon(const AEvolvePokemon& _Other) = delete;
	AEvolvePokemon(AEvolvePokemon&& _Other) noexcept = delete;
	AEvolvePokemon& operator=(const AEvolvePokemon& _Other) = delete;
	AEvolvePokemon& operator=(AEvolvePokemon&& _Other) noexcept = delete;

	void SetPokemonRenderer(PokemonInfo _Pokemon);
	void SetENextPokemonRenderer(PokemonInfo _Pokemon);


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* EvolvePokemon = nullptr;
};

