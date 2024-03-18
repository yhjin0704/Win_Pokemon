#pragma once
#include <EngineCore\Actor.h>
#include <EngineCore\EngineCore.h>
#include "Global.h"

class AOaksLabDoorOut : public AActor
{
public:
	// constrcuter destructer
	AOaksLabDoorOut();
	~AOaksLabDoorOut();

	// delete Function
	AOaksLabDoorOut(const AOaksLabDoorOut& _Other) = delete;
	AOaksLabDoorOut(AOaksLabDoorOut&& _Other) noexcept = delete;
	AOaksLabDoorOut& operator=(const AOaksLabDoorOut& _Other) = delete;
	AOaksLabDoorOut& operator=(AOaksLabDoorOut&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UCollision* LabDoorCollision = nullptr;
};

