#pragma once

// ���� :
class $safeitemname$
{
public:
	// constrcuter destructer
	$safeitemname$();
	~$safeitemname$();

	// delete Function
	$safeitemname$(const $safeitemname$& _Other) = delete;
	$safeitemname$($safeitemname$&& _Other) noexcept = delete;
	$safeitemname$& operator=(const $safeitemname$& _Other) = delete;
	$safeitemname$& operator=($safeitemname$&& _Other) noexcept = delete;

protected:

private:

};

