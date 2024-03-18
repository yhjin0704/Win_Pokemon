#pragma once
#include <EngineCore\Actor.h>
#include <EngineCore\EngineCore.h>
#include "Global.h"

class AOaksLabDoor : public AActor
{
public:
	// constrcuter destructer
	AOaksLabDoor();
	~AOaksLabDoor();

	// delete Function
	AOaksLabDoor(const AOaksLabDoor& _Other) = delete;
	AOaksLabDoor(AOaksLabDoor&& _Other) noexcept = delete;
	AOaksLabDoor& operator=(const AOaksLabDoor& _Other) = delete;
	AOaksLabDoor& operator=(AOaksLabDoor&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UCollision* LabDoorCollision = nullptr;

};

