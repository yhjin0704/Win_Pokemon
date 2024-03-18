#include "MyPokemonBackGround.h"

AMyPokemonBackGround::AMyPokemonBackGround()
{
}

AMyPokemonBackGround::~AMyPokemonBackGround()
{
}

void AMyPokemonBackGround::BeginPlay()
{
	ABackGround::BeginPlay();

	SetBackGroundImage("MyPokemon_BackGround.png");
}

void AMyPokemonBackGround::Tick(float _DeltaTime)
{
	ABackGround::Tick(_DeltaTime);
}