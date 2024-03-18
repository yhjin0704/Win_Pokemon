#include "EvolvePokemon.h"
#include "Pokemon3rdGen_Core.h"
#include "Global.h"

AEvolvePokemon::AEvolvePokemon()
{
}

AEvolvePokemon::~AEvolvePokemon()
{
}

void AEvolvePokemon::BeginPlay()
{
	AActor::BeginPlay();

	EvolvePokemon = CreateImageRenderer(ERenderOrder::Player);
}

void AEvolvePokemon::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void AEvolvePokemon::SetPokemonRenderer(PokemonInfo _Pokemon)
{
	EvolvePokemon->SetImage("1st_Gen_Front_Back_1.png", _Pokemon.FrontImage);
	EvolvePokemon->SetTransform({ { FHScreen_X, FHScreen_Y }, { 64.0f * FScaleMultiple, 64.0f * FScaleMultiple }});
}

void AEvolvePokemon::SetENextPokemonRenderer(PokemonInfo _Pokemon)
{
	PokemonInfo NextEvolve = Pokemon3rdGen_Core::GetAllPokemonInfo()[_Pokemon.NextEvolveDexNo];
	EvolvePokemon->SetImage("1st_Gen_Front_Back_1.png", NextEvolve.FrontImage);
	EvolvePokemon->SetTransform({ { FHScreen_X, FHScreen_Y }, { 64.0f * FScaleMultiple, 64.0f * FScaleMultiple } });
}