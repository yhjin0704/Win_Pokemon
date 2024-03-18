#pragma once
#include "MenuUILevel.h"
#include "MyTrainerCardBackGround.h"
#include <EngineBase/EngineString.h>
#include <EngineCore\EngineCore.h>

class UMyTrainerCardLevel : public UMenuUILevel
{
public:
	// constrcuter destructer
	UMyTrainerCardLevel();
	~UMyTrainerCardLevel();

	// delete Function
	UMyTrainerCardLevel(const UMyTrainerCardLevel& _Other) = delete;
	UMyTrainerCardLevel(UMyTrainerCardLevel&& _Other) noexcept = delete;
	UMyTrainerCardLevel& operator=(const UMyTrainerCardLevel& _Other) = delete;
	UMyTrainerCardLevel& operator=(UMyTrainerCardLevel&& _Other) noexcept = delete;

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
	AMyTrainerCardBackGround* BackGround;

	std::string PrevLevelName = "";

};

