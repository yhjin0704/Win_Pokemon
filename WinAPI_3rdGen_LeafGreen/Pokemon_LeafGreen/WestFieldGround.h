#pragma once
#include "Ground.h"

class AWestFieldGround : public AGround
{
public:
	// constrcuter destructer
	AWestFieldGround();
	~AWestFieldGround();

	// delete Function
	AWestFieldGround(const AWestFieldGround& _Other) = delete;
	AWestFieldGround(AWestFieldGround&& _Other) noexcept = delete;
	AWestFieldGround& operator=(const AWestFieldGround& _Other) = delete;
	AWestFieldGround& operator=(AWestFieldGround&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
};

