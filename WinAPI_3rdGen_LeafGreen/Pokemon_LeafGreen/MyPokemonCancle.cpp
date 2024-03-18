#include "MyPokemonCancle.h"
#include "Global.h"

AMyPokemonCancle::AMyPokemonCancle()
{
}

AMyPokemonCancle::~AMyPokemonCancle()
{
}

void AMyPokemonCancle::BeginPlay()
{
	AActor::BeginPlay();

	ButtonRenderer = CreateImageRenderer(ERenderOrder::Menu);
	ButtonRenderer->SetImage("MyPokemon_Cancel_Button.png");
	UWindowImage* ButtonImage = ButtonRenderer->GetImage();
	FVector ButtonImageScale = ButtonImage->GetScale();
	ButtonRenderer->SetTransform({ {211.0f * FScaleMultiple, 144.0f * FScaleMultiple},{ButtonImageScale * FScaleMultiple} });
}

void AMyPokemonCancle::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void AMyPokemonCancle::SetCancleRenderer(std::string_view _Image)
{
	ButtonRenderer->SetImage(_Image);
}