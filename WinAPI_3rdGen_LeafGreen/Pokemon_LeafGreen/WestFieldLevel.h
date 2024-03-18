#pragma once
#include "FieldLevel.h"
#include "WestFieldGround.h"
#include "PlayerHomeDoorOut.h"
#include "RivalHomeDoorOut.h"
#include "OaksLabDoorOut.h"

class UWestFieldLevel : public UFieldLevel
{
public:
	// constrcuter destructer
	UWestFieldLevel();
	~UWestFieldLevel();

	// delete Function
	UWestFieldLevel(const UWestFieldLevel& _Other) = delete;
	UWestFieldLevel(UWestFieldLevel&& _Other) noexcept = delete;
	UWestFieldLevel& operator=(const UWestFieldLevel& _Other) = delete;
	UWestFieldLevel& operator=(UWestFieldLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _PrevLevel) override;
	void LevelEnd(ULevel* _NextLevel) override;

private:
	AWestFieldGround* Ground;
	APlayerHomeDoorOut* PlayerHomeDoor;
	ARivalHomeDoorOut* RivalHomeDoor;
	AOaksLabDoorOut* OaksLabDoor;
};
