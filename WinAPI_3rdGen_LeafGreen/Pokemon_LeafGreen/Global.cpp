#include "Global.h"
#include <cmath>

const int Global::GIScaleMultiple	= 4;
const int Global::GIGBAScreen_X		= 240;
const int Global::GIGBAScreen_Y		= 160;
const int Global::GIScreen_X		= GIGBAScreen_X * GIScaleMultiple;
const int Global::GIScreen_Y		= GIGBAScreen_Y * GIScaleMultiple;
const int Global::GITileScale		= 16;
const int Global::GIGameTileScale   = GITileScale * GIScaleMultiple;
const int Global::GIHGameTileScale  = (GIGameTileScale / 2);
const int Global::GIHGBAScreen_X    = (GIGBAScreen_X / 2);
const int Global::GIHGBAScreen_Y    = (GIGBAScreen_Y / 2);
const int Global::GIHSceen_X        = (GIScreen_X / 2);	
const int Global::GIHSceen_Y        = (GIScreen_Y / 2);
				  
const float Global::GFScaleMultiple  = std::lround(GIScaleMultiple);
const float Global::GFGBAScreen_X	 = std::lround(GIGBAScreen_X);
const float Global::GFGBAScreen_Y	 = std::lround(GIGBAScreen_Y);
const float Global::GFScreen_X		 = std::lround(GIScreen_X);
const float Global::GFScreen_Y		 = std::lround(GIScreen_Y);
const float Global::GFTileScale		 = std::lround(GITileScale);
const float Global::GFGameTileScale  = std::lround(GIGameTileScale);
const float Global::GFHGameTileScale = std::lround(GIHGameTileScale);
const float Global::GFHGBAScreen_X	 = std::lround(GIHGBAScreen_X);
const float Global::GFHGBAScreen_Y	 = std::lround(GIHGBAScreen_Y);
const float Global::GFHSceen_X		 = std::lround(GIHSceen_X);
const float Global::GFHSceen_Y		 = std::lround(GIHSceen_Y);

const float Global::GIdleTime = 0.08f;
const float Global::GWalkTime = 0.36f;
const float Global::GRunTime = 0.18f;
const float Global::GBikeTime = 0.12f;

const float Global::GColCheckDown = GFGameTileScale;
const float Global::GColCheckUp = 1.0f;
const float Global::GColCheckLeft = GFHGameTileScale + (GFScaleMultiple / 2) + 1.0f;
const float Global::GColCheckRight = GFHGameTileScale;

UWindowImage* Global::GColMapImage = nullptr;

UEngineSoundPlayer Global::BGMPlayer;
std::string Global::PrevBGM;

Global::Global()
{
}

Global::~Global()
{
}

void Global::ChangeBGM(std::string_view _BGMName)
{
	BGMPlayer.Off();
	BGMPlayer = UEngineSound::SoundPlay(_BGMName);
	PrevBGM = _BGMName;
	BGMPlayer.Loop();
}

void Global::SetPokemonText(UImageRenderer* _TextRenderer, Gdiplus::StringAlignment _SortOption, std::string_view _Text, Color8Bit _Color, float _Size)
{
	_TextRenderer->SetFont("PokemonGSK2");
	_TextRenderer->SetTextSize(_Size * FScaleMultiple);
	_TextRenderer->SetTextSortOption(_SortOption, Gdiplus::StringAlignment::StringAlignmentCenter);
	_TextRenderer->SetText(_Text);
	_TextRenderer->SetTextColor(_Color);
}