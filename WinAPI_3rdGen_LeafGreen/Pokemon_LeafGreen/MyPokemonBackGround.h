#pragma once
#include "BackGround.h"

class AMyPokemonBackGround : public ABackGround
{
public:
	// constrcuter destructer
	AMyPokemonBackGround();
	~AMyPokemonBackGround();

	// delete Function
	AMyPokemonBackGround(const AMyPokemonBackGround& _Other) = delete;
	AMyPokemonBackGround(AMyPokemonBackGround&& _Other) noexcept = delete;
	AMyPokemonBackGround& operator=(const AMyPokemonBackGround& _Other) = delete;
	AMyPokemonBackGround& operator=(AMyPokemonBackGround&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

