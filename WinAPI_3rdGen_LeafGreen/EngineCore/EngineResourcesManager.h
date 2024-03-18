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

	// �̱����̶�� �Ѵ�.
	static UEngineResourcesManager& GetInst()
	{
		// ����static �̱���
		static UEngineResourcesManager Inst = UEngineResourcesManager();
		return Inst;
	}

	UWindowImage* LoadImg(std::string_view _Path);

	UWindowImage* LoadImg(std::string_view _Path, std::string_view _Name);

	void UnloadImg(std::string_view _Name);

	bool IsImage(std::string_view _Name);

	UWindowImage* FindImg(std::string_view _Name);

	// �� �̹����� �����µ� ���Ӱ� ����� ���.
	UWindowImage* LoadFolder(std::string_view _Path);

	// �� �̹����� �����µ� ���Ӱ� ����� ���.
	UWindowImage* LoadFolder(std::string_view _Path, std::string_view _Name);

	// ������ �̹� �ε��� �̹����� Ŀ���ϴ� ���
	void CuttingImage(std::string_view _Name, int _X, int _Y);

protected:

private: 
	// constrcuter destructer
	UEngineResourcesManager();
	~UEngineResourcesManager();

	std::map<std::string, UWindowImage*> Images;
};

