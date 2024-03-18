#pragma once
#include "FieldLevel.h"
#include "PlayerHome1FGround.h"
#include "PlayerHomeDoor.h"
#include "PlayerHome1FStairs.h"
#include "Mom.h"

class UPlayerHome1FLevel : public UFieldLevel
{
public:
	// constrcuter destructer
	UPlayerHome1FLevel();
	~UPlayerHome1FLevel();

	// delete Function
	UPlayerHome1FLevel(const UPlayerHome1FLevel& _Other) = delete;
	UPlayerHome1FLevel(UPlayerHome1FLevel&& _Other) noexcept = delete;
	UPlayerHome1FLevel& operator=(const UPlayerHome1FLevel& _Other) = delete;
	UPlayerHome1FLevel& operator=(UPlayerHome1FLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _PrevLevel) override;
	void LevelEnd(ULevel* _NextLevel) override;

private:
	APlayerHome1FGround* Ground;
	APlayerHomeDoor* Door;
	APlayerHome1FStairs* Stairs;

	AMom* Mom;
};

