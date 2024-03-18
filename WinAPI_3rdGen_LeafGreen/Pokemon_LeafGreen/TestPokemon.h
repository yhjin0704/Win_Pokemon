#pragma once
#include "Pokemon.h"

class ATestPokemon : public APokemon
{
public:
	// constrcuter destructer
	ATestPokemon();
	~ATestPokemon();

	// delete Function
	ATestPokemon(const ATestPokemon& _Other) = delete;
	ATestPokemon(ATestPokemon&& _Other) noexcept = delete;
	ATestPokemon& operator=(const ATestPokemon& _Other) = delete;
	ATestPokemon& operator=(ATestPokemon&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

