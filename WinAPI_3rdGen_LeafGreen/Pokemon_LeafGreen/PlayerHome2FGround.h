#pragma once
#include "Ground.h"
#include <EngineBase\EngineDirectory.h>

class APlayerHome2FGround : public AGround
{
public:
	// constrcuter destructer
	APlayerHome2FGround();
	~APlayerHome2FGround();

	// delete Function
	APlayerHome2FGround(const APlayerHome2FGround& _Other) = delete;
	APlayerHome2FGround(APlayerHome2FGround&& _Other) noexcept = delete;
	APlayerHome2FGround& operator=(const APlayerHome2FGround& _Other) = delete;
	APlayerHome2FGround& operator=(APlayerHome2FGround&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

