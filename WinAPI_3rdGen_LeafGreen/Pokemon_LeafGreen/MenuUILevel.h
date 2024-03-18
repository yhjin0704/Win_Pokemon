#pragma once
#include <EngineCore\Level.h>

class UMenuUILevel : public ULevel
{
public:
	// constrcuter destructer
	UMenuUILevel();
	~UMenuUILevel();

	// delete Function
	UMenuUILevel(const UMenuUILevel& _Other) = delete;
	UMenuUILevel(UMenuUILevel&& _Other) noexcept = delete;
	UMenuUILevel& operator=(const UMenuUILevel& _Other) = delete;
	UMenuUILevel& operator=(UMenuUILevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

