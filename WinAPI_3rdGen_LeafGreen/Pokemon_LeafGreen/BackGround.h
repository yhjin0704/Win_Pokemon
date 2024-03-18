#pragma once
#include <EngineCore\Actor.h>
#include <EnginePlatform\EngineInput.h>
#include "Global.h"

class ABackGround : public AActor
{
public:
	// constrcuter destructer
	ABackGround();
	~ABackGround();

	// delete Function
	ABackGround(const ABackGround& _Other) = delete;
	ABackGround(ABackGround&& _Other) noexcept = delete;
	ABackGround& operator=(const ABackGround& _Other) = delete;
	ABackGround& operator=(ABackGround&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UImageRenderer* BackGroundRenderer = nullptr;

	void SetBackGroundImage(std::string_view _BackGroundImage);

private:
};

