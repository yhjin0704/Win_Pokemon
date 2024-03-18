#pragma once
#include <EngineCore\Actor.h>
#include "PokemonInfo.h"

class ABattlePokemonStatus : public AActor
{
public:
	// constrcuter destructer
	ABattlePokemonStatus();
	~ABattlePokemonStatus();

	// delete Function
	ABattlePokemonStatus(const ABattlePokemonStatus& _Other) = delete;
	ABattlePokemonStatus(ABattlePokemonStatus&& _Other) noexcept = delete;
	ABattlePokemonStatus& operator=(const ABattlePokemonStatus& _Other) = delete;
	ABattlePokemonStatus& operator=(ABattlePokemonStatus&& _Other) noexcept = delete;

	void SetRenderer(std::string_view _Image);
	void SetDataRenderers(PokemonInfo _Entry, bool _IsEnemy, float _Name_X, float _Name_Y, float _Level_X, float _Level_Y, float _Gender_X, float _Gender_Y, float _HpBar_X, float _HpBar_Y);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* StatusWindowRenderer = nullptr;

	UImageRenderer* PokemonNameRenderer = nullptr;
	UImageRenderer* PokemonLevelRenderer = nullptr;
	UImageRenderer* PokemonGenderRenderer = nullptr;
	UImageRenderer* PokemonHpBarRenderer = nullptr;
	UImageRenderer* PokemonHPRenderer = nullptr;
	UImageRenderer* PokemonMaxHpRenderer = nullptr;
	UImageRenderer* PokemonExpBarRenderer = nullptr;

	bool IsEnemy = false;
};

