#pragma once
#include <EngineCore\Actor.h>

class APlayerHome2FStairs : public AActor
{
public:
	// constrcuter destructer
	APlayerHome2FStairs();
	~APlayerHome2FStairs();

	// delete Function
	APlayerHome2FStairs(const APlayerHome2FStairs& _Other) = delete;
	APlayerHome2FStairs(APlayerHome2FStairs&& _Other) noexcept = delete;
	APlayerHome2FStairs& operator=(const APlayerHome2FStairs& _Other) = delete;
	APlayerHome2FStairs& operator=(APlayerHome2FStairs&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UCollision* HomeStairsCollision = nullptr;
};

