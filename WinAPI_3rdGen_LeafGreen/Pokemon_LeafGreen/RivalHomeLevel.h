#pragma once
#include "FieldLevel.h"
#include "RivalHomeGround.h"
#include "RivalHomeDoor.h"
#include "global.h"
#include "PlayerHelper.h"

class URivalHomeLevel : public UFieldLevel
{
public:
	// constrcuter destructer
	URivalHomeLevel();
	~URivalHomeLevel();

	// delete Function
	URivalHomeLevel(const URivalHomeLevel& _Other) = delete;
	URivalHomeLevel(URivalHomeLevel&& _Other) noexcept = delete;
	URivalHomeLevel& operator=(const URivalHomeLevel& _Other) = delete;
	URivalHomeLevel& operator=(URivalHomeLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _PrevLevel) override;
	void LevelEnd(ULevel* _NextLevel) override;

private:
	ARivalHomeGround* Ground;
	ARivalHomeDoor* Door;
};

