#pragma once
#include <EngineCore/Actor.h>
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDirectory.h>
#include "PokemonInfo.h"

class AMyPokemonSlot : public AActor
{
public:
	// constrcuter destructer
	AMyPokemonSlot();
	~AMyPokemonSlot();

	// delete Function
	AMyPokemonSlot(const AMyPokemonSlot& _Other) = delete;
	AMyPokemonSlot(AMyPokemonSlot&& _Other) noexcept = delete;
	AMyPokemonSlot& operator=(const AMyPokemonSlot& _Other) = delete;
	AMyPokemonSlot& operator=(AMyPokemonSlot&& _Other) noexcept = delete;

	void SetSlotRenderer(std::string_view _SlotImage, float _Slot_X, float _Slot_Y);
	void SetDotRenderer(float _Ani_X, float _Ani_Y, PokemonInfo _Entry);
	void SetDataRenderers(PokemonInfo _Entry, float _Name_X, float _Name_Y, float _Level_X, float _Level_Y, float _Gender_X, float _Gender_Y, float _HpBar_X, float _HpBar_Y, float _Hp_X, float _Hp_Y, float _MaxHp_X, float _MaxHp_Y);
	
	void IsEmpty(float _Slot_X, float _Slot_Y);
	bool GetEmpty()
	{
		return Empty;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	bool Empty = false;

	UImageRenderer* PokemonSlotRenderer = nullptr;
	UImageRenderer* PokemonImageRenderer = nullptr;
	UImageRenderer* PokemonNameRenderer = nullptr;
	UImageRenderer* PokemonLevelRenderer = nullptr;
	UImageRenderer* PokemonGenderRenderer = nullptr;
	UImageRenderer* PokemonHpBarRenderer = nullptr;
	UImageRenderer* PokemonHPRenderer = nullptr;
	UImageRenderer* PokemonMaxHpRenderer = nullptr;

private:
};

