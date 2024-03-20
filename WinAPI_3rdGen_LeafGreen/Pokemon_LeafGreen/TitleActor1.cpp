#include "TitleActor1.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineCore\EngineCore.h>
#include "Global.h"

ATitleActor1::ATitleActor1()
{
}

ATitleActor1::~ATitleActor1()
{
}

void ATitleActor1::BeginPlay()
{
	AActor::BeginPlay();

	TitleIntroRen1 = CreateImageRenderer(0);

	TitleIntroRen1->SetTransform({ {FHScreen_X, FHScreen_Y}, {FScreen_X, FScreen_Y} });
	TitleIntroRen1->SetImage("Title_Intro_1.png");
}

void ATitleActor1::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	if (0 == StartCheck)
	{
		++StartCheck;
	}
	else if (1 == StartCheck)
	{
		if (TitleIntro1Time <= 0.0f)
		{
			TitleIntro1Time = 5.0f;
			StartCheck = 0;
			TitleIntroRen1->ActiveOff();
			GEngine->ChangeLevel("TitleLevel2");
		}

		if (UEngineInput::IsAnykeyDown())
		{
			TitleIntro1Time = 5.0f;
			StartCheck = 0;
			TitleIntroRen1->ActiveOff();
			GEngine->ChangeLevel("TitleLevel2");
		}

		TitleIntro1Time -= _DeltaTime;
	}
}