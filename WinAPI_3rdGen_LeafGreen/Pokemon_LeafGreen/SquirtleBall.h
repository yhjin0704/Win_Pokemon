#pragma once
#include <EngineCore\Actor.h>
#include <EngineCore\EngineCore.h>

class ASquirtleBall : public AActor
{
public:
	// constrcuter destructer
	ASquirtleBall();
	~ASquirtleBall();

	// delete Function
	ASquirtleBall(const ASquirtleBall& _Other) = delete;
	ASquirtleBall(ASquirtleBall&& _Other) noexcept = delete;
	ASquirtleBall& operator=(const ASquirtleBall& _Other) = delete;
	ASquirtleBall& operator=(ASquirtleBall&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* BallRender;
	UImageRenderer* SelectImage;
	UImageRenderer* TextBox;

	UCollision* BallCollision = nullptr;
};

