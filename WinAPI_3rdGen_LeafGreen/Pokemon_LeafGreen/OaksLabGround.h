#pragma once
#include "Ground.h"
#include <EngineBase\EngineDirectory.h>

class AOaksLabGround : public AGround
{
public:
	// constrcuter destructer
	AOaksLabGround();
	~AOaksLabGround();

	// delete Function
	AOaksLabGround(const AOaksLabGround& _Other) = delete;
	AOaksLabGround(AOaksLabGround&& _Other) noexcept = delete;
	AOaksLabGround& operator=(const AOaksLabGround& _Other) = delete;
	AOaksLabGround& operator=(AOaksLabGround&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

