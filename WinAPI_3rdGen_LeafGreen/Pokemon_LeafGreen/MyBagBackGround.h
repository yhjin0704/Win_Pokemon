#pragma once
#include "BackGround.h"

class AMyBagBackGround : public ABackGround
{
public:
	// constrcuter destructer
	AMyBagBackGround();
	~AMyBagBackGround();

	// delete Function
	AMyBagBackGround(const AMyBagBackGround& _Other) = delete;
	AMyBagBackGround(AMyBagBackGround&& _Other) noexcept = delete;
	AMyBagBackGround& operator=(const AMyBagBackGround& _Other) = delete;
	AMyBagBackGround& operator=(AMyBagBackGround&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

