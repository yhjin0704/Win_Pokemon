#pragma once
#include <EngineCore\Actor.h>
#include "PokemonInfo.h"

class ABattleGround : public AActor
{
public:
	// constrcuter destructer
	ABattleGround();
	~ABattleGround();

	// delete Function
	ABattleGround(const ABattleGround& _Other) = delete;
	ABattleGround(ABattleGround&& _Other) noexcept = delete;
	ABattleGround& operator=(const ABattleGround& _Other) = delete;
	ABattleGround& operator=(ABattleGround&& _Other) noexcept = delete;

	void SetGroundRenderer(std::string_view _Image);
	void SetPokemonRenderer(PokemonInfo _Entry, bool _IsEnemy);
	void SetPokemonActiveOnOff(bool _OnOff);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* GroundRenderer = nullptr;
	UImageRenderer* PokemonRenderer = nullptr;

	bool IsEnemy = false;
};
