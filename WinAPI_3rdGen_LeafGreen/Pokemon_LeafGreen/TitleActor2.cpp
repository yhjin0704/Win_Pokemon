#include "TitleActor2.h"
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>
#include <EngineCore\EngineResourcesManager.h>
#include <EngineCore\EngineCore.h>
#include "Global.h"

ATitleActor2::ATitleActor2()
{
}

ATitleActor2::~ATitleActor2()
{
}

void ATitleActor2::BeginPlay()
{
	AActor::BeginPlay();

	UEngineDirectory TitlePath;
	TitlePath.MoveParent();
	TitlePath.Move("Resources");
	TitlePath.Move("Title");
	TitlePath.Move("Title_Intro_2");

	TitleIntro2List = TitlePath.AllFile({ ".png", ".bmp" }, true);

	TitleIntro2EndIter = TitleIntro2List.end();

	TitleIntroRen2 = CreateImageRenderer(0);
	
	TitleIntroRen2->SetTransform({ {FHScreen_X, FHScreen_Y}, {FScreen_X, FScreen_Y} });
}

void ATitleActor2::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (0 == StartCheck)
	{
		TitleIntro2StartIter = TitleIntro2List.begin();

		UEngineFile& File = (*TitleIntro2StartIter);
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
		TitleIntroRen2->SetImage(File.GetFileName());
		++TitleIntro2StartIter;

		++StartCheck;
	}
	else if (1 == StartCheck)
	{
		Time += _DeltaTime;
		if (Time >= FrameTime)
		{
			UEngineFile& File = (*TitleIntro2StartIter);
			UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
			TitleIntroRen2->SetImage(File.GetFileName());
			++TitleIntro2StartIter;

			Time = _DeltaTime - FrameTime;
		}

		if (TitleIntro2StartIter == TitleIntro2EndIter)
		{
			StartCheck = 0;
			TitleIntroRen2->ActiveOff();
			GEngine->ChangeLevel("TitleLevel3");
		}

		if (UEngineInput::IsAnykeyDown())
		{
			StartCheck = 0;
			TitleIntroRen2->ActiveOff();
			GEngine->ChangeLevel("TitleLevel3");
		}
	}
}