#include "TitleLevel1.h"
#include <EngineBase/EngineDirectory.h>
#include <EngineCore/EngineResourcesManager.h>
#include <EngineBase/EngineFile.h>
#include "TitleActor1.h"

UTitleLevel1::UTitleLevel1()
{
}

UTitleLevel1::~UTitleLevel1()
{
}

void UTitleLevel1::BeginPlay()
{
	ULevel::BeginPlay();

	UEngineDirectory TitlePath;
	TitlePath.MoveParent();
	TitlePath.Move("Resources");
	TitlePath.Move("Title");
	TitlePath.Move("Title_Intro_1");

	std::list<UEngineFile> AllFiles = TitlePath.AllFile();
	for (UEngineFile& File : AllFiles)
	{
		std::string Path = File.GetFullPath();
		UEngineResourcesManager::GetInst().LoadImg(Path);
	}

	this->SpawnActor<ATitleActor1>();
}

void UTitleLevel1::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
}

void UTitleLevel1::LevelStart(ULevel* _PrevLevel)
{
}

void UTitleLevel1::LevelEnd(ULevel* _NextLevel)
{
}