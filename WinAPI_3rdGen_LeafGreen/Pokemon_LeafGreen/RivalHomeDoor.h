#pragma once
#include <EngineCore\Actor.h>
#include <EngineCore\EngineCore.h>
#include "Global.h"

class ARivalHomeDoor : public AActor
{
public:
	// constrcuter destructer
	ARivalHomeDoor();
	~ARivalHomeDoor();

	// delete Function
	ARivalHomeDoor(const ARivalHomeDoor& _Other) = delete;
	ARivalHomeDoor(ARivalHomeDoor&& _Other) noexcept = delete;
	ARivalHomeDoor& operator=(const ARivalHomeDoor& _Other) = delete;
	ARivalHomeDoor& operator=(ARivalHomeDoor&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UCollision* HomeDoorCollision = nullptr;
};

