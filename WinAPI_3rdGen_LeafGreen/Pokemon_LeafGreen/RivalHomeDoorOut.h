#pragma once
#include <EngineCore\Actor.h>
#include <EngineCore\EngineCore.h>
#include "Global.h"

class ARivalHomeDoorOut : public AActor
{
public:
	// constrcuter destructer
	ARivalHomeDoorOut();
	~ARivalHomeDoorOut();

	// delete Function
	ARivalHomeDoorOut(const ARivalHomeDoorOut& _Other) = delete;
	ARivalHomeDoorOut(ARivalHomeDoorOut&& _Other) noexcept = delete;
	ARivalHomeDoorOut& operator=(const ARivalHomeDoorOut& _Other) = delete;
	ARivalHomeDoorOut& operator=(ARivalHomeDoorOut&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UCollision* HomeDoorCollision = nullptr;
};

