#pragma once
#include <EngineCore/Actor.h>
#include <EngineBase/EngineFile.h>

class ATitleActor4 : public AActor
{
public:
	// constrcuter destructer
	ATitleActor4();
	~ATitleActor4();

	// delete Function
	ATitleActor4(const ATitleActor4& _Other) = delete;
	ATitleActor4(ATitleActor4&& _Other) noexcept = delete;
	ATitleActor4& operator=(const ATitleActor4& _Other) = delete;
	ATitleActor4& operator=(ATitleActor4&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
protected:

private:
	int StartCheck = 0;

	float Time = 0.0f;
	float FrameTime = 0.016f;

	std::list<UEngineFile> TitleIntro4List;

	std::list<UEngineFile>::iterator TitleIntro4StartIter;
	std::list<UEngineFile>::iterator TitleIntro4EndIter;

	UImageRenderer* TitleIntroRen4 = nullptr;
};

