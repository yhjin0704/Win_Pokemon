#pragma once
#include "EngineCore/Level.h"

class UEndingLevel : public ULevel
{
public:
	// constrcuter destructer
	UEndingLevel();
	~UEndingLevel();

	// delete Function
	UEndingLevel(const UEndingLevel& _Other) = delete;
	UEndingLevel(UEndingLevel&& _Other) noexcept = delete;
	UEndingLevel& operator=(const UEndingLevel& _Other) = delete;
	UEndingLevel& operator=(UEndingLevel&& _Other) noexcept = delete;

protected:

private:

};

