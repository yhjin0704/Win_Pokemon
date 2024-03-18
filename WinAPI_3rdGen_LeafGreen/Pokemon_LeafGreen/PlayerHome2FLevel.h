#pragma once
#include "FieldLevel.h"
#include "PlayerHome2FGround.h"
#include "PlayerHome2FStairs.h"

class UPlayerHome2FLevel : public UFieldLevel
{
public:
	// constrcuter destructer
	UPlayerHome2FLevel();
	~UPlayerHome2FLevel();

	// delete Function
	UPlayerHome2FLevel(const UPlayerHome2FLevel& _Other) = delete;
	UPlayerHome2FLevel(UPlayerHome2FLevel&& _Other) noexcept = delete;
	UPlayerHome2FLevel& operator=(const UPlayerHome2FLevel& _Other) = delete;
	UPlayerHome2FLevel& operator=(UPlayerHome2FLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _PrevLevel) override;
	void LevelEnd(ULevel* _NextLevel) override;

private:
	APlayerHome2FGround* Ground;
	APlayerHome2FStairs* Stairs;
};

