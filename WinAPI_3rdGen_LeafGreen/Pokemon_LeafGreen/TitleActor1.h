#pragma once
#include <EngineCore/Actor.h>
#include <EngineBase\EngineFile.h>

class ATitleActor1 : public AActor
{
public:
	// constrcuter destructer
	ATitleActor1();
	~ATitleActor1();

	// delete Function
	ATitleActor1(const ATitleActor1& _Other) = delete;
	ATitleActor1(ATitleActor1&& _Other) noexcept = delete;
	ATitleActor1& operator=(const ATitleActor1& _Other) = delete;
	ATitleActor1& operator=(ATitleActor1&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	int StartCheck = 0;

	float TitleIntro1Time = 5.0f;

	UImageRenderer* TitleIntroRen1 = nullptr;
};

