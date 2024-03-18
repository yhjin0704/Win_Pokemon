#include "MyPokemonSlot.h"
#include "Pokemon3rdGen_Core.h"
#include "Global.h"

AMyPokemonSlot::AMyPokemonSlot()
{
}

AMyPokemonSlot::~AMyPokemonSlot()
{
}

void AMyPokemonSlot::BeginPlay()
{
	AActor::BeginPlay();

	PokemonSlotRenderer = CreateImageRenderer(ERenderOrder::Menu);
	PokemonImageRenderer = CreateImageRenderer(ERenderOrder::Text);
	PokemonNameRenderer = CreateImageRenderer(ERenderOrder::Text);
	PokemonLevelRenderer = CreateImageRenderer(ERenderOrder::Text);
	PokemonGenderRenderer = CreateImageRenderer(ERenderOrder::Text);
	PokemonHpBarRenderer = CreateImageRenderer(ERenderOrder::Text);
	PokemonHPRenderer = CreateImageRenderer(ERenderOrder::Text);
	PokemonMaxHpRenderer = CreateImageRenderer(ERenderOrder::Text);
}

void AMyPokemonSlot::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void AMyPokemonSlot::SetSlotRenderer(std::string_view _SlotImage, float _Slot_X, float _Slot_Y)
{
	Empty = false;

	PokemonSlotRenderer->SetImage(_SlotImage);
	UWindowImage* SlotImage = PokemonSlotRenderer->GetImage();
	FVector SlotImageScale = SlotImage->GetScale();
	PokemonSlotRenderer->SetTransform({ { _Slot_X * FScaleMultiple, _Slot_Y * FScaleMultiple }, (SlotImageScale * FScaleMultiple) });
}

void AMyPokemonSlot::SetDotRenderer(float _Ani_X, float _Ani_Y, PokemonInfo _Entry)
{
	PokemonImageRenderer->ActiveOn();
	if (false == PokemonImageRenderer->IsAnimation(_Entry.Tribe + "_Dot"))
	{
		PokemonImageRenderer->CreateAnimation(_Entry.Tribe + "_Dot", "1st_Gen_Dot.png", _Entry.DotAnimationStart, _Entry.DotAnimationEnd, 0.1f, true);
	}
	PokemonImageRenderer->SetTransform({ { _Ani_X * FScaleMultiple, _Ani_Y * FScaleMultiple }, {32.0f * FScaleMultiple, 32.0f * FScaleMultiple} });
	PokemonImageRenderer->ChangeAnimation(_Entry.Tribe + "_Dot", false, 0, 0.1f);
}

void AMyPokemonSlot::SetDataRenderers(PokemonInfo _Entry,
	float _Name_X, float _Name_Y,
	float _Level_X, float _Level_Y,
	float _Gender_X, float _Gender_Y,
	float _HpBar_X, float _HpBar_Y,
	float _Hp_X, float _Hp_Y,
	float _MaxHp_X, float _MaxHp_Y)
{
	PokemonNameRenderer->ActiveOn();
	PokemonLevelRenderer->ActiveOn();
	PokemonGenderRenderer->ActiveOn();
	PokemonHpBarRenderer->ActiveOn();
	PokemonHPRenderer->ActiveOn();
	PokemonMaxHpRenderer->ActiveOn();

	Global::SetPokemonText(PokemonNameRenderer, Gdiplus::StringAlignment::StringAlignmentNear, _Entry.Name, Color8Bit::WhiteA);
	PokemonNameRenderer->SetTransform({ { _Name_X * FScaleMultiple, _Name_Y * FScaleMultiple }, { 0, 0 } });

	Global::SetPokemonText(PokemonLevelRenderer, Gdiplus::StringAlignment::StringAlignmentNear, std::to_string(_Entry.Level), Color8Bit::WhiteA, 12.0f);
	PokemonLevelRenderer->SetTransform({ { _Level_X * FScaleMultiple, _Level_Y * FScaleMultiple }, { 0, 0 } });

	if (true == _Entry.Gender)
	{
		PokemonGenderRenderer->SetImage("Gender_Male.png");
	}
	else
	{
		PokemonGenderRenderer->SetImage("Gender_Female.png");
	}
	UWindowImage* GenderImage = PokemonGenderRenderer->GetImage();
	FVector GenderImageScale = GenderImage->GetScale();
	PokemonGenderRenderer->SetTransform({ { _Gender_X * FScaleMultiple, _Gender_Y * FScaleMultiple }, (GenderImageScale * FScaleMultiple) });

	int BarGage = std::lround(std::ceil((static_cast<float>(_Entry.Hp) / static_cast<float>(_Entry.MaxHp)) * 48));
	if (0 > BarGage)
	{
		BarGage = 0;
	}
	if (48 < BarGage)
	{
		BarGage = 48;
	}
	PokemonHpBarRenderer->SetImage("Hp" + std::to_string(BarGage) + ".png");
	UWindowImage* BarImage = PokemonHpBarRenderer->GetImage();
	FVector BarImageScale = BarImage->GetScale();
	PokemonHpBarRenderer->SetTransform({ { _HpBar_X * FScaleMultiple, _HpBar_Y * FScaleMultiple }, (BarImageScale * FScaleMultiple) });
	
	if (0 > _Entry.Hp)
	{
		_Entry.Hp = 0;
	}
	if(_Entry.MaxHp < _Entry.Hp)
	{
		_Entry.Hp = _Entry.MaxHp;
	}
	Global::SetPokemonText(PokemonHPRenderer, Gdiplus::StringAlignment::StringAlignmentFar, std::to_string(_Entry.Hp), Color8Bit::WhiteA, 10.0f);
	PokemonHPRenderer->SetTransform({ { _Hp_X * FScaleMultiple, _Hp_Y * FScaleMultiple }, { 0, 0 } });

	Global::SetPokemonText(PokemonMaxHpRenderer, Gdiplus::StringAlignment::StringAlignmentNear, std::to_string(_Entry.MaxHp), Color8Bit::WhiteA, 10.0f);
	PokemonMaxHpRenderer->SetTransform({ { _MaxHp_X * FScaleMultiple, _MaxHp_Y * FScaleMultiple }, { 0, 0 } });
}

void AMyPokemonSlot::IsEmpty(float _Slot_X, float _Slot_Y)
{
	Empty = true;

	PokemonSlotRenderer->SetImage("MyPokemon_Slot_empty.png");
	UWindowImage* SlotImage = PokemonSlotRenderer->GetImage();
	FVector SlotImageScale = SlotImage->GetScale();
	PokemonSlotRenderer->SetTransform({ { _Slot_X * FScaleMultiple, _Slot_Y * FScaleMultiple }, (SlotImageScale * FScaleMultiple) });

	PokemonImageRenderer->ActiveOff();
	PokemonNameRenderer->ActiveOff();
	PokemonLevelRenderer->ActiveOff();
	PokemonGenderRenderer->ActiveOff();
	PokemonHpBarRenderer->ActiveOff();
	PokemonHPRenderer->ActiveOff();
	PokemonMaxHpRenderer->ActiveOff();
}