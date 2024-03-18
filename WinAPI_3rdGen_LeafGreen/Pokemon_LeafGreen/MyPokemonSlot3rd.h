#pragma once
class AMyPokemonSlot3rd
{
public:
	// constrcuter destructer
	AMyPokemonSlot3rd();
	~AMyPokemonSlot3rd();

	// delete Function
	AMyPokemonSlot3rd(const AMyPokemonSlot3rd& _Other) = delete;
	AMyPokemonSlot3rd(AMyPokemonSlot3rd&& _Other) noexcept = delete;
	AMyPokemonSlot3rd& operator=(const AMyPokemonSlot3rd& _Other) = delete;
	AMyPokemonSlot3rd& operator=(AMyPokemonSlot3rd&& _Other) noexcept = delete;

protected:

private:

};

