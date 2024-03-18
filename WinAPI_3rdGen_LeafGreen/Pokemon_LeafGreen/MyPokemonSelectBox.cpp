#include "MyPokemonSelectBox.h"
#include "Global.h"

AMyPokemonSelectBox::AMyPokemonSelectBox()
{
}

AMyPokemonSelectBox::~AMyPokemonSelectBox()
{
}

void AMyPokemonSelectBox::BeginPlay()
{
	AActor::BeginPlay();

	CursorRender = CreateImageRenderer(ERenderOrder::OnText);
	BoxRenderer = CreateImageRenderer(ERenderOrder::OnMenu);

	CursorRender->SetImage("MenuCursor.png");
	CursorRender->SetTransform({ { 0, 0 }, { (CursorRender->GetImage()->GetScale()) * FScaleMultiple} });

	BoxRenderer->SetImage("MyPokemon_Select_Box.png");
	BoxRenderer->SetSortType(EImageSortType::Right);
	BoxRenderer->SetTransform({ {240.0f * FScaleMultiple, 129.0f * FScaleMultiple }, { (BoxRenderer->GetImage()->GetScale()) * FScaleMultiple} });

	CursorRender->ActiveOff();
	BoxRenderer->ActiveOff();
}

void AMyPokemonSelectBox::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void AMyPokemonSelectBox::SetSelectBoxActive(bool _OnOff)
{
	if (true == _OnOff)
	{
		CursorRender->ActiveOn();
		BoxRenderer->ActiveOn();
	}
	else
	{
		CursorRender->ActiveOff();
		BoxRenderer->ActiveOff();
	}
}

void AMyPokemonSelectBox::SetCursorLocation(float _X, float _Y)
{
	CursorRender->SetTransform({ { _X * FScaleMultiple, _Y * FScaleMultiple }, { (CursorRender->GetImage()->GetScale()) * FScaleMultiple} });
}