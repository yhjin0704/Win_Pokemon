#pragma once
class AMyPokemonSlot6th
{
public:
	// constrcuter destructer
	AMyPokemonSlot6th();
	~AMyPokemonSlot6th();

	// delete Function
	AMyPokemonSlot6th(const AMyPokemonSlot6th& _Other) = delete;
	AMyPokemonSlot6th(AMyPokemonSlot6th&& _Other) noexcept = delete;
	AMyPokemonSlot6th& operator=(const AMyPokemonSlot6th& _Other) = delete;
	AMyPokemonSlot6th& operator=(AMyPokemonSlot6th&& _Other) noexcept = delete;

protected:

private:

};

