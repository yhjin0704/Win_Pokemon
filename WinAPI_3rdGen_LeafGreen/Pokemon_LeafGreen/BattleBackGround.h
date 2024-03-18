#pragma once
#include "BackGround.h"

class ABattleBackGround : public ABackGround
{
public:
	// constrcuter destructer
	ABattleBackGround();
	~ABattleBackGround();

	// delete Function
	ABattleBackGround(const ABattleBackGround& _Other) = delete;
	ABattleBackGround(ABattleBackGround&& _Other) noexcept = delete;
	ABattleBackGround& operator=(const ABattleBackGround& _Other) = delete;
	ABattleBackGround& operator=(ABattleBackGround&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

