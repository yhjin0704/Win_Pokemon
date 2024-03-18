#pragma once
#include "FieldLevel.h"
#include "OaksLabGround.h"
#include "OaksLabDoor.h"
#include "BulbasaurBall.h"
#include "CharmanderBall.h"
#include "SquirtleBall.h"
#include "global.h"
#include "PlayerHelper.h"

class UOaksLabLevel : public UFieldLevel
{
public:
	// constrcuter destructer
	UOaksLabLevel();
	~UOaksLabLevel();

	// delete Function
	UOaksLabLevel(const UOaksLabLevel& _Other) = delete;
	UOaksLabLevel(UOaksLabLevel&& _Other) noexcept = delete;
	UOaksLabLevel& operator=(const UOaksLabLevel& _Other) = delete;
	UOaksLabLevel& operator=(UOaksLabLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _PrevLevel) override;
	void LevelEnd(ULevel* _NextLevel) override;

private:
	AOaksLabGround* Ground;
	AOaksLabDoor* Door;
	ABulbasaurBall* BBall;
	ACharmanderBall* CBall;
	ASquirtleBall* SBall;
};

