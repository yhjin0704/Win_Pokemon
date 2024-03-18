#include "TitleLevel4.h"
#include <EngineBase/EngineDirectory.h>
#include <EngineCore/EngineResourcesManager.h>
#include <EngineBase/EngineFile.h>
#include "TitleActor4.h"
#include "global.h"

UTitleLevel4::UTitleLevel4()
{
}

UTitleLevel4::~UTitleLevel4()
{
}

void UTitleLevel4::BeginPlay()
{
	ULevel::BeginPlay();

	this->SpawnActor<ATitleActor4>();
}

void UTitleLevel4::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
}

void UTitleLevel4::LevelStart(ULevel* _PrevLevel)
{
	Global::ChangeBGM("Title4.mp3");
}

void UTitleLevel4::LevelEnd(ULevel* _NextLevel)
{
}