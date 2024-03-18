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
	//UINT CodePage, = CP_ACP ���� window�� ������ �ʱ� ���ڿ� ���ڵ����� ó���ش޶�
	//DWORD dwFlags, = ��ȯ�Ҷ� �߰� ������ �ֳ���? �ƴϿ� 0 => ����Ʈ ���� �÷��׾ּ� �˰� ���� �ʾ� 0=> ����Ʈ�� ����
	//LPCCH lpMultiByteStr, = ��ȯ�� ���ڿ�
	//int cbMultiByte, => ��ȯ�� ���ڿ��� ����
	//LPWSTR lpWideCharStr, => wide ����Ʈ ���ڿ� => ��ȯ�� ���� nullptr �־��ָ� �̳༮�� ũ�⸦ �����Ѵ�
	//int cchWideChar => wide ����Ʈ ���ڿ��� ũ��
	int Size = MultiByteToWideChar(CP_ACP, 0, _View.data(), static_cast<int>(_View.size()), nullptr, 0);

	if (0 == Size)
	{
		MsgBoxAssert("���ڿ� ��ȯ�� �����߰ų� ũ�Ⱑ 0�� ���ڿ��� �־�����ϴ�");
		return L"";
	}

	std::wstring Result;
	Result.resize(Size);

	// ��ȯ�Ǿ��� ����
	Size = MultiByteToWideChar(CP_ACP, 0, _View.data(), static_cast<int>(_View.size()), &Result[0], Size);

	if (0 == Size)
	{
		MsgBoxAssert("���ڿ� ��ȯ�� �����߰ų� ũ�Ⱑ 0�� ���ڿ��� �־�����ϴ�");
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