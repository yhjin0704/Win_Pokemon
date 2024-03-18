#include "EngineString.h"
#include <Windows.h>
#include "EngineDebug.h"

UEngineString::UEngineString() 
{
}

UEngineString::~UEngineString() 
{
}

std::wstring UEngineString::AnsiToUniCode(std::string_view _View)
{
	//UINT CodePage, = CP_ACP 현재 window에 설정된 초기 문자열 인코딩으로 처리해달라
	//DWORD dwFlags, = 변환할때 추가 정보가 있나요? 아니요 0 => 디폴트 너의 플래그애서 알고 싶지 않아 0=> 디폴트로 해줘
	//LPCCH lpMultiByteStr, = 변환할 문자열
	//int cbMultiByte, => 변환할 문자열의 길이
	//LPWSTR lpWideCharStr, => wide 바이트 문자열 => 변환을 받을 nullptr 넣어주면 이녀석은 크기를 리턴한다
	//int cchWideChar => wide 바이트 문자열의 크기
	int Size = MultiByteToWideChar(CP_ACP, 0, _View.data(), static_cast<int>(_View.size()), nullptr, 0);

	if (0 == Size)
	{
		MsgBoxAssert("문자열 변환에 실패했거나 크기가 0인 문자열을 넣어줬습니다");
		return L"";
	}

	std::wstring Result;
	Result.resize(Size);

	// 변환되어진 개수
	Size = MultiByteToWideChar(CP_ACP, 0, _View.data(), static_cast<int>(_View.size()), &Result[0], Size);

	if (0 == Size)
	{
		MsgBoxAssert("문자열 변환에 실패했거나 크기가 0인 문자열을 넣어줬습니다");
		return L"";
	}

	return Result;
}

std::string UEngineString::ToUpper(std::string_view View)
{
	std::string Name = View.data();

	for (char& _Ch : Name)
	{
		_Ch = std::toupper(_Ch);
	}

	return Name;
}