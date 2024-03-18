#pragma once
#include <string>
#include <string_view>
#include <map>

class UWindowImage;
class UEngineResourcesManager
{
public:
	// delete Function
	UEngineResourcesManager(const UEngineResourcesManager& _Other) = delete;
	UEngineResourcesManager(UEngineResourcesManager&& _Other) noexcept = delete;
	UEngineResourcesManager& operator=(const UEngineResourcesManager& _Other) = delete;
	UEngineResourcesManager& operator=(UEngineResourcesManager&& _Other) noexcept = delete;

	// 싱글톤이라고 한다.
	static UEngineResourcesManager& GetInst()
	{
		// 지역static 싱글톤
		static UEngineResourcesManager Inst = UEngineResourcesManager();
		return Inst;
	}

	UWindowImage* LoadImg(std::string_view _Path);

	UWindowImage* LoadImg(std::string_view _Path, std::string_view _Name);

	void UnloadImg(std::string_view _Name);

	bool IsImage(std::string_view _Name);

	UWindowImage* FindImg(std::string_view _Name);

	// 그 이미지가 없었는데 새롭게 만드는 기능.
	UWindowImage* LoadFolder(std::string_view _Path);

	// 그 이미지가 없었는데 새롭게 만드는 기능.
	UWindowImage* LoadFolder(std::string_view _Path, std::string_view _Name);

	// 기존에 이미 로드한 이미지를 커팅하는 기능
	void CuttingImage(std::string_view _Name, int _X, int _Y);

protected:

private: 
	// constrcuter destructer
	UEngineResourcesManager();
	~UEngineResourcesManager();

	std::map<std::string, UWindowImage*> Images;
};

