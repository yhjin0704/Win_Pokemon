#pragma once
#include <EngineCore/Actor.h>
#include <EngineBase\EngineFile.h>

class ATitleActor2 : public AActor
{
public:
	// constrcuter destructer
	ATitleActor2();
	~ATitleActor2();

	// delete Function
	ATitleActor2(const ATitleActor2& _Other) = delete;
	ATitleActor2(ATitleActor2&& _Other) noexcept = delete;
	ATitleActor2& operator=(const ATitleActor2& _Other) = delete;
	ATitleActor2& operator=(ATitleActor2&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
protected:

private:
	int StartCheck = 0;

	float Time = 0.0f;
	float FrameTime = 0.016f;

	std::list<UEngineFile> TitleIntro2List;

	std::list<UEngineFile>::iterator TitleIntro2StartIter;
	std::list<UEngineFile>::iterator TitleIntro2EndIter;

	//std::string_view TitleIntro2PrevFileName = "";

	UImageRenderer* TitleIntroRen2 = nullptr;
};

