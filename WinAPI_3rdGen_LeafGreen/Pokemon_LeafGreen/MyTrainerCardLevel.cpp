#include "MyTrainerCardLevel.h"

UMyTrainerCardLevel::UMyTrainerCardLevel()
{
}

UMyTrainerCardLevel::~UMyTrainerCardLevel()
{
}

void UMyTrainerCardLevel::BeginPlay()
{
	UMenuUILevel::BeginPlay();

	BackGround = SpawnActor<AMyTrainerCardBackGround>();
}

void UMyTrainerCardLevel::Tick(float _DeltaTime)
{
	UMenuUILevel::Tick(_DeltaTime);

	if (true == UEngineInput::IsDown('L'))
	{
		GEngine->ChangeLevel(PrevLevelName);
	}
}

void UMyTrainerCardLevel::LevelStart(ULevel* _PrevLevel)
{
	PrevLevelName = _PrevLevel->GetName();
}

void UMyTrainerCardLevel::LevelEnd(ULevel* _NextLevel)
{
}