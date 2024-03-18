#pragma once
class AMyPokemonSlot4th
{
public:
	// constrcuter destructer
	AMyPokemonSlot4th();
	~AMyPokemonSlot4th();

	// delete Function
	AMyPokemonSlot4th(const AMyPokemonSlot4th& _Other) = delete;
	AMyPokemonSlot4th(AMyPokemonSlot4th&& _Other) noexcept = delete;
	AMyPokemonSlot4th& operator=(const AMyPokemonSlot4th& _Other) = delete;
	AMyPokemonSlot4th& operator=(AMyPokemonSlot4th&& _Other) noexcept = delete;

protected:

private:

};

