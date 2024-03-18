#pragma once
class AMyPokemonMsgBox
{
public:
	// constrcuter destructer
	AMyPokemonMsgBox();
	~AMyPokemonMsgBox();

	// delete Function
	AMyPokemonMsgBox(const AMyPokemonMsgBox& _Other) = delete;
	AMyPokemonMsgBox(AMyPokemonMsgBox&& _Other) noexcept = delete;
	AMyPokemonMsgBox& operator=(const AMyPokemonMsgBox& _Other) = delete;
	AMyPokemonMsgBox& operator=(AMyPokemonMsgBox&& _Other) noexcept = delete;

protected:

private:

};
