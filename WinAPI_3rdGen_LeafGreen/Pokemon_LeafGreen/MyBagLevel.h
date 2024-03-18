#pragma once
#include "MenuUILevel.h"
#include "MyBagBackGround.h"
#include <EngineBase/EngineString.h>
#include <EngineCore\EngineCore.h>

class UMyBagLevel : public UMenuUILevel
{
public:
	// constrcuter destructer
	UMyBagLevel();
	~UMyBagLevel();

	// delete Function
	UMyBagLevel(const UMyBagLevel& _Other) = delete;
	UMyBagLevel(UMyBagLevel&& _Other) noexcept = delete;
	UMyBagLevel& operator=(const UMyBagLevel& _Other) = delete;
	UMyBagLevel& operator=(UMyBagLevel&& _Other) noexcept = delete;

	std::string GetPrevLevelName()
	{
		return PrevLevelName;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _PrevLevel) override;
	void LevelEnd(ULevel* _NextLevel) override;

private:
	AMyBagBackGround* BackGround;

	std::string PrevLevelName = "";
};

