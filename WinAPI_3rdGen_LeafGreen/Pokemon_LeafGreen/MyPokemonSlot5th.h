#pragma once
class AMyPokemonSlot5th
{
public:
	// constrcuter destructer
	AMyPokemonSlot5th();
	~AMyPokemonSlot5th();

	// delete Function
	AMyPokemonSlot5th(const AMyPokemonSlot5th& _Other) = delete;
	AMyPokemonSlot5th(AMyPokemonSlot5th&& _Other) noexcept = delete;
	AMyPokemonSlot5th& operator=(const AMyPokemonSlot5th& _Other) = delete;
	AMyPokemonSlot5th& operator=(AMyPokemonSlot5th&& _Other) noexcept = delete;

protected:

private:

};

