#pragma once
class AMyPokemonSlot2nd
{
public:
	// constrcuter destructer
	AMyPokemonSlot2nd();
	~AMyPokemonSlot2nd();

	// delete Function
	AMyPokemonSlot2nd(const AMyPokemonSlot2nd& _Other) = delete;
	AMyPokemonSlot2nd(AMyPokemonSlot2nd&& _Other) noexcept = delete;
	AMyPokemonSlot2nd& operator=(const AMyPokemonSlot2nd& _Other) = delete;
	AMyPokemonSlot2nd& operator=(AMyPokemonSlot2nd&& _Other) noexcept = delete;

protected:

private:

};

