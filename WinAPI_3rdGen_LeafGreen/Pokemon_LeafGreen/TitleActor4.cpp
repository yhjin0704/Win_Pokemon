#include "TitleActor4.h"
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>
#include <EngineCore\EngineResourcesManager.h>
#include <EngineCore\EngineCore.h>
#include "Global.h"

ATitleActor4::ATitleActor4()
{
}

ATitleActor4::~ATitleActor4()
{
}

void ATitleActor4::BeginPlay()
{
	AActor::BeginPlay();

	UEngineDirectory TitlePath;
	TitlePath.MoveParent();
	TitlePath.Move("Resources");
	TitlePath.Move("Title");
	TitlePath.Move("Title_Intro_4");

	TitleIntro4List = TitlePath.AllFile({ ".png", ".bmp" }, true);

	TitleIntro4EndIter = TitleIntro4List.end();

	TitleIntroRen4 = CreateImageRenderer(0);

	TitleIntroRen4->SetTransform({ {FHScreen_X, FHScreen_Y}, {FScreen_X, FScreen_Y} });
}

void ATitleActor4::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (0 == StartCheck)
	{
		TitleIntro4StartIter = TitleIntro4List.begin();

		UEngineFile& File = (*TitleIntro4StartIter);
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
		TitleIntroRen4->SetImage(File.GetFileName());
		++TitleIntro4StartIter;

		++StartCheck;
	}
	else if (1 == StartCheck)
	{
		Time += _DeltaTime;
		if (Time >= FrameTime)
		{
			UEngineResourcesManager::GetInst().UnloadImg(TitleIntroRen4->GetImage()->GetName());
			UEngineFile& File = (*TitleIntro4StartIter);
			UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
			TitleIntroRen4->SetImage(File.GetFileName());
			++TitleIntro4StartIter;
			Time = _DeltaTime - FrameTime;
		}

		if (TitleIntro4StartIter == TitleIntro4EndIter)
		{
			StartCheck = 0;
			TitleIntroRen4->ActiveOff();
			UEngineResourcesManager::GetInst().UnloadImg(TitleIntroRen4->GetImage()->GetName());
			GEngine->ChangeLevel("TitleLevel1");
		}

		if (UEngineInput::IsAnykeyDown())
		{
			StartCheck = 0;
			TitleIntroRen4->ActiveOff();
			UEngineResourcesManager::GetInst().UnloadImg(TitleIntroRen4->GetImage()->GetName());
			GEngine->ChangeLevel("PlayerHome2FLevel");
		}
	}
}