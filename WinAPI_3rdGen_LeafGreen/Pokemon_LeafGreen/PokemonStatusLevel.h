#pragma once
class UPokemonStatusLevel
{
public:
	// constrcuter destructer
	UPokemonStatusLevel();
	~UPokemonStatusLevel();

	// delete Function
	UPokemonStatusLevel(const UPokemonStatusLevel& _Other) = delete;
	UPokemonStatusLevel(UPokemonStatusLevel&& _Other) noexcept = delete;
	UPokemonStatusLevel& operator=(const UPokemonStatusLevel& _Other) = delete;
	UPokemonStatusLevel& operator=(UPokemonStatusLevel&& _Other) noexcept = delete;

protected:

private:

};

