#include "MyBagLevel.h"
#include "BattleHelper.h"

UMyBagLevel::UMyBagLevel()
{
}

UMyBagLevel::~UMyBagLevel()
{
}

void UMyBagLevel::BeginPlay()
{
	UMenuUILevel::BeginPlay();

	BackGround = SpawnActor<AMyBagBackGround>();
}

void UMyBagLevel::Tick(float _DeltaTime)
{
	UMenuUILevel::Tick(_DeltaTime);

	if (true == UEngineInput::IsDown('P') && UEngineString::ToUpper("BattleLevel") == PrevLevelName)
	{
		BattleHelper::UseBall = EUseBall::MasterBall;
		GEngine->ChangeLevel(PrevLevelName);
	}

	if (true == UEngineInput::IsDown('L'))
	{
		GEngine->ChangeLevel(PrevLevelName);
	}
}

void UMyBagLevel::LevelStart(ULevel* _PrevLevel)
{
	PrevLevelName = _PrevLevel->GetName();
}

void UMyBagLevel::LevelEnd(ULevel* _NextLevel)
{
}