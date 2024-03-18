#pragma once
#include <EngineCore\Actor.h>

class AMyPokemonSelectBox : public AActor
{
public:
	// constrcuter destructer
	AMyPokemonSelectBox();
	~AMyPokemonSelectBox();

	// delete Function
	AMyPokemonSelectBox(const AMyPokemonSelectBox& _Other) = delete;
	AMyPokemonSelectBox(AMyPokemonSelectBox&& _Other) noexcept = delete;
	AMyPokemonSelectBox& operator=(const AMyPokemonSelectBox& _Other) = delete;
	AMyPokemonSelectBox& operator=(AMyPokemonSelectBox&& _Other) noexcept = delete;

	void SetSelectBoxActive(bool _OnOff);

	void SetCursorLocation(float _X, float _Y);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* CursorRender = nullptr;

	UImageRenderer* BoxRenderer = nullptr;

	UImageRenderer*	SummaryTextRenderer = nullptr;
	UImageRenderer*	SwitchTextRenderer = nullptr;
    UImageRenderer*	CancelTextRenderer = nullptr;

};

