#pragma once
#include <EngineCore\Actor.h>
#include <EngineCore\EngineCore.h>

class ABulbasaurBall : public AActor
{
public:
	// constrcuter destructer
	ABulbasaurBall();
	~ABulbasaurBall();

	// delete Function
	ABulbasaurBall(const ABulbasaurBall& _Other) = delete;
	ABulbasaurBall(ABulbasaurBall&& _Other) noexcept = delete;
	ABulbasaurBall& operator=(const ABulbasaurBall& _Other) = delete;
	ABulbasaurBall& operator=(ABulbasaurBall&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* BallRender;
	UImageRenderer* SelectImage;
	UImageRenderer* TextBox;

	UCollision* BallCollision = nullptr;
};

