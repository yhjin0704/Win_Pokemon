#pragma once
#include <EngineCore\Actor.h>

class ABattleSelectBox : public AActor
{
public:
	// constrcuter destructer
	ABattleSelectBox();
	~ABattleSelectBox();

	// delete Function
	ABattleSelectBox(const ABattleSelectBox& _Other) = delete;
	ABattleSelectBox(ABattleSelectBox&& _Other) noexcept = delete;
	ABattleSelectBox& operator=(const ABattleSelectBox& _Other) = delete;
	ABattleSelectBox& operator=(ABattleSelectBox&& _Other) noexcept = delete;

	void SetSelectBoxActive(bool _OnOff);
	void SetSelectBoxTextActive(bool _OnOff);
	void SetCursorActive(bool _OnOff);

	void SetCursorLocation(float _X, float _Y);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* CursorRender;

	UImageRenderer* BoxRenderer = nullptr;
	UImageRenderer* TextRendererFight = nullptr;
	UImageRenderer* TextRendererBag = nullptr;
	UImageRenderer* TextRendererPokemon = nullptr;
	UImageRenderer* TextRendererRun = nullptr;

	UImageRenderer* MoveTextRenderer1 = nullptr;
	UImageRenderer* MoveTextRenderer2 = nullptr;
	UImageRenderer* MoveTextRenderer3 = nullptr;
	UImageRenderer* MoveTextRenderer4 = nullptr;

	UImageRenderer* PPTextRenderer = nullptr;
	UImageRenderer* TypeTextRenderer = nullptr;
};

