#include "TitleLevel2.h"
#include <EngineBase/EngineDirectory.h>
#include <EngineCore/EngineResourcesManager.h>
#include <EngineBase/EngineFile.h>
#include "global.h"

UTitleLevel2::UTitleLevel2()
{
}

UTitleLevel2::~UTitleLevel2()
{
}

void UTitleLevel2::BeginPlay()
{
	ULevel::BeginPlay();

	
}

void UTitleLevel2::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
}

void UTitleLevel2::LevelStart(ULevel* _PrevLevel)
{
	TitleActor = SpawnActor<ATitleActor2>();
	Global::ChangeBGM("Title2.mp3");
}

void UTitleLevel2::LevelEnd(ULevel* _NextLevel)
{
	TitleActor->Destroy();
}