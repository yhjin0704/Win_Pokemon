#pragma once
#include <EngineCore\Level.h>

class UTitleLevel2 : public ULevel
{
public:
	// constrcuter destructer
	UTitleLevel2();
	~UTitleLevel2();

	// delete Function
	UTitleLevel2(const UTitleLevel2& _Other) = delete;
	UTitleLevel2(UTitleLevel2&& _Other) noexcept = delete;
	UTitleLevel2& operator=(const UTitleLevel2& _Other) = delete;
	UTitleLevel2& operator=(UTitleLevel2&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _PrevLevel) override;
	void LevelEnd(ULevel* _NextLevel) override;

private:

};

