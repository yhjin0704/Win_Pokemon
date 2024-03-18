#pragma once
#include "Ground.h"
#include <EngineBase\EngineDirectory.h>

class APlayerHome1FGround : public AGround
{
public:
	// constrcuter destructer
	APlayerHome1FGround();
	~APlayerHome1FGround();

	// delete Function
	APlayerHome1FGround(const APlayerHome1FGround& _Other) = delete;
	APlayerHome1FGround(APlayerHome1FGround&& _Other) noexcept = delete;
	APlayerHome1FGround& operator=(const APlayerHome1FGround& _Other) = delete;
	APlayerHome1FGround& operator=(APlayerHome1FGround&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
};

