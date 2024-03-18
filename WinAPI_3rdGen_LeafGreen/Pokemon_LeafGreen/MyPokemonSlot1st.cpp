#include "MyPokemonSlot1st.h"

AMyPokemonSlot1st::AMyPokemonSlot1st()
{
}

AMyPokemonSlot1st::~AMyPokemonSlot1st()
{
}

void AMyPokemonSlot1st::BeginPlay()
{
	AMyPokemonSlot::BeginPlay();

	IshavePokemon = true;
}

void AMyPokemonSlot1st::Tick(float _DeltaTime)
{
	AMyPokemonSlot::Tick(_DeltaTime);
}