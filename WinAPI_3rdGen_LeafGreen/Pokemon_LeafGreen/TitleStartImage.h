#pragma once
class ATitleStartImage
{
public:
	// constrcuter destructer
	ATitleStartImage();
	~ATitleStartImage();

	// delete Function
	ATitleStartImage(const ATitleStartImage& _Other) = delete;
	ATitleStartImage(ATitleStartImage&& _Other) noexcept = delete;
	ATitleStartImage& operator=(const ATitleStartImage& _Other) = delete;
	ATitleStartImage& operator=(ATitleStartImage&& _Other) noexcept = delete;

protected:

private:

};

