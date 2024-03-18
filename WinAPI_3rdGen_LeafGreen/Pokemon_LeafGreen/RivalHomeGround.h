#pragma once
#include "Ground.h"
#include <EngineBase\EngineDirectory.h>

class ARivalHomeGround : public AGround
{
public:
	// constrcuter destructer
	ARivalHomeGround();
	~ARivalHomeGround();

	// delete Function
	ARivalHomeGround(const ARivalHomeGround& _Other) = delete;
	ARivalHomeGround(ARivalHomeGround&& _Other) noexcept = delete;
	ARivalHomeGround& operator=(const ARivalHomeGround& _Other) = delete;
	ARivalHomeGround& operator=(ARivalHomeGround&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

