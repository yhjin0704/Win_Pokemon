#pragma once
#include <EngineCore\Actor.h>

class APlayerHome1FStairs : public AActor
{
public:
	// constrcuter destructer
	APlayerHome1FStairs();
	~APlayerHome1FStairs();

	// delete Function
	APlayerHome1FStairs(const APlayerHome1FStairs& _Other) = delete;
	APlayerHome1FStairs(APlayerHome1FStairs&& _Other) noexcept = delete;
	APlayerHome1FStairs& operator=(const APlayerHome1FStairs& _Other) = delete;
	APlayerHome1FStairs& operator=(APlayerHome1FStairs&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UCollision* HomeStairsCollision = nullptr;
};

