#include "TitleLevel2.h"
#include <EngineBase/EngineDirectory.h>
#include <EngineCore/EngineResourcesManager.h>
#include <EngineBase/EngineFile.h>
#include "TitleActor2.h"
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

	this->SpawnActor<ATitleActor2>();
}

void UTitleLevel2::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
}

void UTitleLevel2::LevelStart(ULevel* _PrevLevel)
{
	Global::ChangeBGM("Title2.mp3");
}

void UTitleLevel2::LevelEnd(ULevel* _NextLevel)
{
}