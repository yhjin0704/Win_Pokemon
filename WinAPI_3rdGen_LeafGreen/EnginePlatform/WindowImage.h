#pragma once
#include <EngineBase\PathObject.h>
#include <EngineBase\EngineMath.h>
#include <EngineBase\Transform.h>
#include <EngineBase\EngineDebug.h>
#include <Windows.h>
#include <string>
#include <string_view>

#include <objidl.h>
#include <gdiplus.h>

enum class EImageLoadType
{
	IMG_Folder,
	IMG_Cutting,
};

enum class EWIndowImageType
{
	IMG_NONE,
	IMG_BMP,
	IMG_PNG
};

class UImageInfo 
{
public:
	HBITMAP hBitMap;
	HDC ImageDC = nullptr;
	FTransform CuttingTrans;
	UImageInfo* RotationMaskImage = nullptr;
	EWIndowImageType ImageType = EWIndowImageType::IMG_NONE;
};

class UEngineWindow;
// 설명 :
class UWindowImage : public UPathObject
{
	friend UEngineWindow;

public:
	// constrcuter destructer
	UWindowImage();
	~UWindowImage();

	// delete Function
	UWindowImage(const UWindowImage& _Other) = delete;
	UWindowImage(UWindowImage&& _Other) noexcept = delete;
	UWindowImage& operator=(const UWindowImage& _Other) = delete;
	UWindowImage& operator=(UWindowImage&& _Other) noexcept = delete;

	// bool을 리턴해서 false면 실패 true면 성공
	bool Load(UWindowImage* _Image);

	bool LoadFolder(UWindowImage* _Image);

	FVector GetScale();

	void BitCopy(UWindowImage* _CopyImage, const FTransform& _Trans);

	void TransCopy(UWindowImage* _CopyImage, const FTransform& _Trans, int _Index, Color8Bit _Color = Color8Bit::Black);

	void AlphaCopy(UWindowImage* _CopyImage, const FTransform& _Trans, int _Index, Color8Bit _Color = Color8Bit::Black);

	void PlgCopy(UWindowImage* _CopyImage, const FTransform& _Trans, int _Index, float _RadAngle);

	void TextCopy(const std::string& _Text, const std::string& _Font, float _Size, const FTransform& _Trans, Color8Bit _Color /*= Color8Bit::Black*/);

	void TextCopy(const std::string& _Text, const std::string& _Font, float _Size, const FTransform& _Trans, Color8Bit _OutLineColor, Color8Bit _FillColor);

	void TextCopy(const std::string& _Text, const std::string& _Font, float _Size, const FTransform& _Trans, Gdiplus::StringAlignment _SortOption1, Gdiplus::StringAlignment _SortOption2, Color8Bit _FillColor);

	void TextCopyBold(const std::string& _Text, const std::string& _Font, float _Size, const FTransform& _Trans, Color8Bit _Color /*= Color8Bit::Black*/);

	void TextCopyFormat(const std::string& _Text, const std::string& _Font, const Gdiplus::StringFormat& stringFormat, float _Size, const FTransform& _Trans, Color8Bit _Color /*= Color8Bit::Black*/);

	bool Create(UWindowImage* _Image, const FVector& _Scale);

	void Cutting(int _X, int _Y);

	void SetCuttingTransform(const FTransform& _CuttingTrans, int _Index = 0);

	void DrawRectangle(const FTransform& _Trans);
	void DrawEllipse(const FTransform& _Trans);

	Color8Bit GetColor(int _X, int _Y, Color8Bit _DefaultColor);

	EWIndowImageType GetImageType()
	{
		return ImageType;
	}

	void SetRotationMaskImage(int _Index, UWindowImage* _RotationMaskImage, int _MaskIndex)
	{
		UImageInfo& Ref = _RotationMaskImage->Infos[_MaskIndex];
		Infos[_Index].RotationMaskImage = &Ref;
	}

	void SetRotationMaskImageFolder(UWindowImage* _RotationMaskImage)
	{
		if (Infos.size() != _RotationMaskImage->Infos.size())
		{
			MsgBoxAssert("이미지정보의 크기가 다른 이미지 끼리 매칭을 할수가 없습니다.");
			return;
		}

		for (int i = 0; i < static_cast<int>(Infos.size()); i++)
		{
			SetRotationMaskImage(i, _RotationMaskImage, i);
		}
	}

	void TextPrint(std::string_view _Text, FVector _Pos);
	const UImageInfo& ImageInfo(int _Index)
	{
		if (_Index >= Infos.size())
		{
			MsgBoxAssert("커팅된 이미지보다 더 큰 이미지 인덱스를 사용했습니다.");
		}

		return Infos[_Index];
	}

protected:

private:

	EImageLoadType LoadType = EImageLoadType::IMG_Cutting;

	// 윈도우에서 지원해주는 H붙은 애들은 다 struct HBITMAP__{int unused;}; typedef struct HBITMAP__ *HBITMAP
	// 포인터이면서 8바이트 정수입니다.
	HBITMAP hBitMap = 0;
	HDC ImageDC = 0;
	BITMAP BitMapInfo = BITMAP();
	EWIndowImageType ImageType = EWIndowImageType::IMG_NONE;

	std::vector<UImageInfo> Infos;

	bool Create(HDC _MainDC);
};

