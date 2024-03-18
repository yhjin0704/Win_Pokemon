#include "TitleActor3.h"
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>
#include <EngineCore\EngineResourcesManager.h>
#include <EngineCore\EngineCore.h>
#include "Global.h"

ATitleActor3::ATitleActor3()
{
}

ATitleActor3::~ATitleActor3()
{
}

void ATitleActor3::BeginPlay()
{
	AActor::BeginPlay();

	UEngineDirectory TitlePath;
	TitlePath.MoveParent();
	TitlePath.Move("Resources");
	TitlePath.Move("Title");
	TitlePath.Move("Title_Intro_3");

	TitleIntro3List = TitlePath.AllFile({ ".png", ".bmp" }, true);

	TitleIntro3EndIter = TitleIntro3List.end();

	TitleIntroRen3 = CreateImageRenderer(0);

	TitleIntroRen3->SetTransform({ {FHScreen_X, FHScreen_Y}, {FScreen_X, FScreen_Y} });
}

void ATitleActor3::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (0 == StartCheck)
	{
		TitleIntro3StartIter = TitleIntro3List.begin();

		UEngineFile& File = (*TitleIntro3StartIter);
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
		TitleIntroRen3->SetImage(File.GetFileName());
		++TitleIntro3StartIter;

		++StartCheck;
	}
	else if (1 == StartCheck)
	{
		Time += _DeltaTime;
		if (Time >= FrameTime)
		{
			UEngineFile& File = (*TitleIntro3StartIter);
			UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
			TitleIntroRen3->SetImage(File.GetFileName());
			++TitleIntro3StartIter;
			Time = _DeltaTime - FrameTime;
		}

		if (TitleIntro3StartIter == TitleIntro3EndIter)
		{
			StartCheck = 0;
			GEngine->ChangeLevel("TitleLevel4");
		}

		if (UEngineInput::IsAnykeyDown())
		{
			StartCheck = 0;
			GEngine->ChangeLevel("TitleLevel4");
		}
	}
}