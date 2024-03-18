#include "BattleGround.h"
#include "Global.h"

ABattleGround::ABattleGround()
{
}

ABattleGround::~ABattleGround()
{
}

void ABattleGround::BeginPlay()
{
	AActor::BeginPlay();

	GroundRenderer = CreateImageRenderer(ERenderOrder::Object);
	PokemonRenderer = CreateImageRenderer(ERenderOrder::Player);
}

void ABattleGround::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void ABattleGround::SetGroundRenderer(std::string_view _Image)
{
	GroundRenderer->SetImage(_Image);
	UWindowImage* Image = GroundRenderer->GetImage();
	FVector ImageScale = Image->GetScale();
	GroundRenderer->SetTransform({ (ImageScale.Half2D() * FScaleMultiple), {ImageScale * FScaleMultiple} });
}

void ABattleGround::SetPokemonRenderer(PokemonInfo _Entry, bool _IsEnemy)
{
	if (false == _IsEnemy)
	{
		PokemonRenderer->SetImage("1st_Gen_Front_Back_1.png", _Entry.BackImage);
		PokemonRenderer->SetTransform({ {65.0f * FScaleMultiple, 80.0f * FScaleMultiple }, {64.0f * FScaleMultiple, 64.0f * FScaleMultiple} });
	}
	else
	{
		PokemonRenderer->SetImage("1st_Gen_Front_Back_1.png", _Entry.FrontImage);
		PokemonRenderer->SetTransform({ {175.0f * FScaleMultiple, 45.0f * FScaleMultiple}, {64.0f * FScaleMultiple, 64.0f * FScaleMultiple} });
	}
}

void ABattleGround::SetPokemonActiveOnOff(bool _OnOff)
{
	if (true == _OnOff)
	{
		PokemonRenderer->ActiveOn();
	}
	else
	{
		PokemonRenderer->ActiveOff();
	}
}