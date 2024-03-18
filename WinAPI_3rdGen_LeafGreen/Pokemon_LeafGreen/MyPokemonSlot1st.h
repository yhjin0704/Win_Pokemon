#pragma once
#include "MyPokemonSlot.h"

class AMyPokemonSlot1st : public AMyPokemonSlot
{
public:
	// constrcuter destructer
	AMyPokemonSlot1st();
	~AMyPokemonSlot1st();

	// delete Function
	AMyPokemonSlot1st(const AMyPokemonSlot1st& _Other) = delete;
	AMyPokemonSlot1st(AMyPokemonSlot1st&& _Other) noexcept = delete;
	AMyPokemonSlot1st& operator=(const AMyPokemonSlot1st& _Other) = delete;
	AMyPokemonSlot1st& operator=(AMyPokemonSlot1st&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

