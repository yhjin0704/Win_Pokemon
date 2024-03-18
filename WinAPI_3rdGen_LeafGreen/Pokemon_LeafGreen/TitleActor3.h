#pragma once
#include <EngineCore/Actor.h>
#include <EngineBase/EngineFile.h>

class ATitleActor3 : public AActor
{
public:
	// constrcuter destructer
	ATitleActor3();
	~ATitleActor3();

	// delete Function
	ATitleActor3(const ATitleActor3& _Other) = delete;
	ATitleActor3(ATitleActor3&& _Other) noexcept = delete;
	ATitleActor3& operator=(const ATitleActor3& _Other) = delete;
	ATitleActor3& operator=(ATitleActor3&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
protected:

private:
	int StartCheck = 0;

	float Time = 0.0f;
	float FrameTime = 0.016f;

	std::list<UEngineFile> TitleIntro3List;

	std::list<UEngineFile>::iterator TitleIntro3StartIter;
	std::list<UEngineFile>::iterator TitleIntro3EndIter;

	UImageRenderer* TitleIntroRen3 = nullptr;
};

