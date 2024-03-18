#pragma once
#include "Npc.h"

class AMom : public ANpc
{
public:
	// constrcuter destructer
	AMom();
	~AMom();

	// delete Function
	AMom(const AMom& _Other) = delete;
	AMom(AMom&& _Other) noexcept = delete;
	AMom& operator=(const AMom& _Other) = delete;
	AMom& operator=(AMom&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	int DialogCount = 0;
	void DefaultEvent();
};

