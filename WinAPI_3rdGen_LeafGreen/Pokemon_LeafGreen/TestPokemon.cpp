#include "TestPokemon.h"

ATestPokemon::ATestPokemon()
{
}

ATestPokemon::~ATestPokemon()
{
}

void ATestPokemon::BeginPlay()
{
	APokemon::BeginPlay();
}

void ATestPokemon::Tick(float _DeltaTime)
{
	APokemon::Tick(_DeltaTime);
}