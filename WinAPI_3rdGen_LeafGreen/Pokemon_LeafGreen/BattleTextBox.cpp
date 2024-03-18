#include "BattleTextBox.h"
#include "Global.h"

ABattleTextBox::ABattleTextBox()
{
}

ABattleTextBox::~ABattleTextBox()
{
}

void ABattleTextBox::BeginPlay()
{
	AActor::BeginPlay();

	BoxRenderer = CreateImageRenderer(ERenderOrder::Menu);
	TextRendererTop = CreateImageRenderer(ERenderOrder::Text);
	TextRendererBottom = CreateImageRenderer(ERenderOrder::Text);

	TextRendererTop->ActiveOff();
	TextRendererBottom->ActiveOff();

	BoxRenderer->SetImage("BattleMsgBox.png");
	UWindowImage* Image = BoxRenderer->GetImage();
	FVector ImageScale = Image->GetScale();
	BoxRenderer->SetTransform({ {120.0f * FScaleMultiple, 136.0f * FScaleMultiple }, { ImageScale * FScaleMultiple }});

	TextRendererTop->SetTransform({ { 10.0f * FScaleMultiple, 128.0f * FScaleMultiple }, {0, 0} });
	TextRendererBottom->SetTransform({ { 10.0f * FScaleMultiple, 144.0f * FScaleMultiple }, {0, 0} });
}

void ABattleTextBox::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void ABattleTextBox::SetTextTop(std::string_view _Text)
{
	TextRendererTop->ActiveOn();
	Global::SetPokemonText(TextRendererTop, Gdiplus::StringAlignment::StringAlignmentNear, _Text, Color8Bit::WhiteA);
}

void ABattleTextBox::SetTextBottom(std::string_view _Text)
{
	TextRendererBottom->ActiveOn();
	Global::SetPokemonText(TextRendererBottom, Gdiplus::StringAlignment::StringAlignmentNear, _Text, Color8Bit::WhiteA);
}

void ABattleTextBox::TextOff()
{
	TextRendererTop->ActiveOff();
	TextRendererBottom->ActiveOff();
}