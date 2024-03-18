#pragma once

enum class EType
{
	None,
	노말,
	불꽃,
	물,
	풀,
	전기,
	얼음,
	격투,
	독,
	땅,
	비행,
	에스퍼,
	벌레,
	바위,
	고스트,
	드래곤,
	악,
	강철,
	페어리
};

enum class ENature
{
	Hardy,
	Lonely,
	Adamant,
	Naughty,
	Brave,
	Bold,
	Docile,
	Impish,
	Lax,
	Relaxed,
	Modest,
	Mild,
	Bashful,
	Rash,
	Quiet,
	Calm,
	Gentle,
	Careful,
	Quirky,
	Sassy,
	Timid,
	Hasty,
	Jolly,
	Naive,
	Serious
};

class PokemonHelper
{
public:
	// constrcuter destructer
	PokemonHelper();
	~PokemonHelper();

	// delete Function
	PokemonHelper(const PokemonHelper& _Other) = delete;
	PokemonHelper(PokemonHelper&& _Other) noexcept = delete;
	PokemonHelper& operator=(const PokemonHelper& _Other) = delete;
	PokemonHelper& operator=(PokemonHelper&& _Other) noexcept = delete;

protected:

private:

};

