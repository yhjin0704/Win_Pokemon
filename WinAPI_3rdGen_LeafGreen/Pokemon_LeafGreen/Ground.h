#pragma once
#include "BackGround.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDirectory.h>
#include "Global.h"

class AGround : public ABackGround
{
public:
	// constrcuter destructer
	AGround();
	~AGround();

	// delete Function
	AGround(const AGround& _Other) = delete;
	AGround(AGround&& _Other) noexcept = delete;
	AGround& operator=(const AGround& _Other) = delete;
	AGround& operator=(AGround&& _Other) noexcept = delete;

	void SetMapImage(std::string_view _MapImageName);
	void SetColMapImage(std::string_view _MapImageName);
	void SetCoverMapImage(std::string_view _MapImageName);

	UWindowImage* GetColMapImage()
	{
		return ColMapImage;
	}

	void SwitchDebug();


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UWindowImage* ColMapImage = nullptr;

	UImageRenderer* ColMapRenderer = nullptr;
	UImageRenderer* CoverMapRenderer = nullptr;

private:
};

