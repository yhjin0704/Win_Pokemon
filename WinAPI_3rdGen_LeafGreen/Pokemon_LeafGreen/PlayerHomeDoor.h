#pragma once
#include <EngineCore\Actor.h>

class APlayerHomeDoor : public AActor
{
public:
	// constrcuter destructer
	APlayerHomeDoor();
	~APlayerHomeDoor();

	// delete Function
	APlayerHomeDoor(const APlayerHomeDoor& _Other) = delete;
	APlayerHomeDoor(APlayerHomeDoor&& _Other) noexcept = delete;
	APlayerHomeDoor& operator=(const APlayerHomeDoor& _Other) = delete;
	APlayerHomeDoor& operator=(APlayerHomeDoor&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UCollision* HomeDoorCollision = nullptr;
};

