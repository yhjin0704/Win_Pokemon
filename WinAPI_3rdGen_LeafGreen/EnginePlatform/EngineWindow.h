#pragma once
#include <Windows.h>
#include <string>
#include <EngineBase\EngineMath.h>

class UWindowImage;
// 설명 :
class UEngineWindow
{
public:
	// constrcuter destructer
	UEngineWindow();
	~UEngineWindow();

	// delete Function
	UEngineWindow(const UEngineWindow& _Other) = delete;
	UEngineWindow(UEngineWindow&& _Other) noexcept = delete;
	UEngineWindow& operator=(const UEngineWindow& _Other) = delete;
	UEngineWindow& operator=(UEngineWindow&& _Other) noexcept = delete;

	void Open(std::string_view _Title = "Title", std::string_view _IconPath = "");

	static void Init(HINSTANCE _hInst);
	static unsigned __int64 WindowMessageLoop(void(*_Update)(), void(*_End)());

	UWindowImage* GetWindowImage()
	{
		return WindowImage;
	}

	UWindowImage* GetBackBufferImage()
	{
		return BackBufferImage;
	}

	void SetWindowPosition(const FVector& _Pos);
	void SetWindowScale(const FVector& _Scale);

	void ScreenClear();
	void ScreenUpdate();

	FVector GetWindowScale()
	{
		return Scale;
	}

	void SetClearColor(Color8Bit _Color)
	{
		_Color.A = 0;
		ClearColor = _Color;
	}

	void SetWindowTitle(std::string_view _Text)
	{
		SetWindowTextA(hWnd, _Text.data());
	}

	void SetWindowSmallIcon();
	
	FVector GetMousePosition();

	void Off()
	{
		WindowLive = false;
	}

	void CursorOff();

protected:

private:
	static bool WindowLive;
	static HINSTANCE hInstance;
	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	Color8Bit ClearColor = Color8Bit::WhiteA;

	HWND hWnd = nullptr;
	// HDC hDC = nullptr;
	// 윈도우와 직접적으로 연결된 DC를 가지고 있는 최종 이미지
	UWindowImage* WindowImage = nullptr;
	// 윈도우를 오직 1번만 갱신하기 위한 이미지

	// 이미지를 1개 만들어요. => 윈도우 전체 크기만하게 => 단계를 할수가 없다.
	UWindowImage* BackBufferImage = nullptr;
	// 이미지가 2개다 이미지는 버퍼라는 개념으로도 부른다. => 더블버퍼링이라는 이름인 겁니다.
	FVector Scale;
	FVector Position;
};

