#pragma once
#include <EngineCore\Actor.h>

class APlayerHomeDoorOut : public AActor
{
public:
	// constrcuter destructer
	APlayerHomeDoorOut();
	~APlayerHomeDoorOut();

	// delete Function
	APlayerHomeDoorOut(const APlayerHomeDoorOut& _Other) = delete;
	APlayerHomeDoorOut(APlayerHomeDoorOut&& _Other) noexcept = delete;
	APlayerHomeDoorOut& operator=(const APlayerHomeDoorOut& _Other) = delete;
	APlayerHomeDoorOut& operator=(APlayerHomeDoorOut&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UCollision* HomeDoorCollision = nullptr;
};