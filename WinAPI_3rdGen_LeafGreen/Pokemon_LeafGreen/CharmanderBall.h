#pragma once
#include <EngineCore\Actor.h>
#include <EngineCore\EngineCore.h>

class ACharmanderBall : public AActor
{
public:
	// constrcuter destructer
	ACharmanderBall();
	~ACharmanderBall();

	// delete Function
	ACharmanderBall(const ACharmanderBall& _Other) = delete;
	ACharmanderBall(ACharmanderBall&& _Other) noexcept = delete;
	ACharmanderBall& operator=(const ACharmanderBall& _Other) = delete;
	ACharmanderBall& operator=(ACharmanderBall&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* BallRender;
	UImageRenderer* SelectImage;
	UImageRenderer* TextBox;

	UCollision* BallCollision = nullptr;
};

