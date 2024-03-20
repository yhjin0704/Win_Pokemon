#include "EvolveLevel.h"
#include "Pokemon3rdGen_Core.h"
#include "PlayerHelper.h"

UEvolveLevel::UEvolveLevel()
{
}

UEvolveLevel::~UEvolveLevel()
{
}

void UEvolveLevel::BeginPlay()
{
	ULevel::BeginPlay();

	BackGround = SpawnActor<AEvolveBackGround>();
	EvolvePokemonRenderer = SpawnActor<AEvolvePokemon>();

	EvolvePokemonRenderer->ActiveOff();

}

void UEvolveLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	if (true == UEngineInput::IsDown('L'))
	{

		EvolvePokemon.CanEvolve = false;
		GEngine->ChangeLevel(PrevLevelName);
	}

	Delay -= _DeltaTime;

	switch (Order)
	{
	case 0:
		EvolvePokemonRenderer->ActiveOn();
		EvolvePokemonRenderer->SetPokemonRenderer(EvolvePokemon);
		if (Delay <= 0)
		{
			++Order;
			Delay = 1.0f;
		}

		if (4 == Count)
		{
			Order = 2;
		}
		break;
	case 1:
		EvolvePokemonRenderer->SetENextPokemonRenderer(EvolvePokemon);
		if (Delay <= 0)
		{
			++Count;
			--Order;
			Delay = 1.0f;
		}
		break;
	case 2:
		EvolvePokemon.Evolve();
		EvolvePokemon.CanEvolve = false;
		++Order;
		break;
	case 3:
		EvolvePokemonRenderer->SetPokemonRenderer(EvolvePokemon);
		*EntryIter = EvolvePokemon;
		if (true == UEngineInput::IsDown('P') || true == UEngineInput::IsDown('L'))
		{
			GEngine->ChangeLevel(PrevLevelName);
		}
		break;
	default:
		break;
	}
}

void UEvolveLevel::LevelStart(ULevel* _PrevLevel)
{
	PrevLevelName = _PrevLevel->GetName();

	Global::ChangeBGM("Evolve.mp3");

	Entry = dynamic_cast<Pokemon3rdGen_Core*>(GEngine)->GetEntry();
	for (EntryIter = Entry.begin(); EntryIter != Entry.end(); EntryIter++)
	{
		EvolvePokemon = *EntryIter;
		if (true == EvolvePokemon.NowLevelUp)
		{
			Order = 0;
			Delay = 1.0f;
			Count = 0;
			break;
		}
	}
}

void UEvolveLevel::LevelEnd(ULevel* _NextLevel)
{
	dynamic_cast<Pokemon3rdGen_Core*>(GEngine)->SetEntry(Entry);
}