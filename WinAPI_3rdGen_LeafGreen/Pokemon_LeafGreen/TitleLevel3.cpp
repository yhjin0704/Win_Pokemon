#include "TitleLevel3.h"
#include <EngineBase/EngineDirectory.h>
#include <EngineCore/EngineResourcesManager.h>
#include <EngineBase/EngineFile.h>
#include "TitleActor3.h"
#include "global.h"

UTitleLevel3::UTitleLevel3()
{
}

UTitleLevel3::~UTitleLevel3()
{
}

void UTitleLevel3::BeginPlay()
{
	ULevel::BeginPlay();

	this->SpawnActor<ATitleActor3>();
}

void UTitleLevel3::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
}

void UTitleLevel3::LevelStart(ULevel* _PrevLevel)
{
	Global::ChangeBGM("Title3.mp3");
}

void UTitleLevel3::LevelEnd(ULevel* _NextLevel)
{
}