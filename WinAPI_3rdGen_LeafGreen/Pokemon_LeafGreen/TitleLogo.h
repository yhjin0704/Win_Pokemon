#pragma once
class ATitleLogo
{
public:
	// constrcuter destructer
	ATitleLogo();
	~ATitleLogo();

	// delete Function
	ATitleLogo(const ATitleLogo& _Other) = delete;
	ATitleLogo(ATitleLogo&& _Other) noexcept = delete;
	ATitleLogo& operator=(const ATitleLogo& _Other) = delete;
	ATitleLogo& operator=(ATitleLogo&& _Other) noexcept = delete;

protected:

private:

};

