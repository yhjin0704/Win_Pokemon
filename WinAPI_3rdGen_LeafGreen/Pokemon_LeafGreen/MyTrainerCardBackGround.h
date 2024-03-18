#pragma once
#include "BackGround.h"

class AMyTrainerCardBackGround : public ABackGround
{
public:
	// constrcuter destructer
	AMyTrainerCardBackGround();
	~AMyTrainerCardBackGround();

	// delete Function
	AMyTrainerCardBackGround(const AMyTrainerCardBackGround& _Other) = delete;
	AMyTrainerCardBackGround(AMyTrainerCardBackGround&& _Other) noexcept = delete;
	AMyTrainerCardBackGround& operator=(const AMyTrainerCardBackGround& _Other) = delete;
	AMyTrainerCardBackGround& operator=(AMyTrainerCardBackGround&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

