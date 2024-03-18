#pragma once
#include <EngineCore\ImageRenderer.h>
#include <EnginePlatform\EngineSound.h>

enum class ERenderOrder
{
	ColMap,
	BackGround,
	Object,
	NpcPosIsUp,
	Player,
	NpcPosIsDown,
	CoverMap,
	Menu,
	Text,
	OnMenu,
	OnText,
};

enum class ECollisionOrder
{
	Player,
	Npc,
	BattleCheck,
	Door,
	Item
};

enum class EDirState
{
	Down,
	Up,
	Left,
	Right
};

enum class EMoveType
{
	Test,
	Walk,
	Run,
	Bike,
	Surf
};

enum class EMoveState
{
	Idle,
	Move,
	Jump,
	Left,
	Right
};

class Global
{
public:
	static const int GIScaleMultiple;
	static const int GIGBAScreen_X;
	static const int GIGBAScreen_Y;
	static const int GIScreen_X;
	static const int GIScreen_Y;
	static const int GITileScale;
	static const int GIGameTileScale;
	static const int GIHGameTileScale;
	static const int GIHGBAScreen_X;
	static const int GIHGBAScreen_Y;
	static const int GIHSceen_X;
	static const int GIHSceen_Y;
					 
	static const float GFScaleMultiple;
	static const float GFGBAScreen_X;
	static const float GFGBAScreen_Y;
	static const float GFScreen_X;
	static const float GFScreen_Y;
	static const float GFTileScale;
	static const float GFGameTileScale;
	static const float GFHGameTileScale;
	static const float GFHGBAScreen_X;
	static const float GFHGBAScreen_Y;
	static const float GFHSceen_X;
	static const float GFHSceen_Y;

	static const float GIdleTime;
	static const float GWalkTime;
	static const float GRunTime;
	static const float GBikeTime;

	static const float GColCheckDown;
	static const float GColCheckUp;
	static const float GColCheckLeft;
	static const float GColCheckRight;

	static UWindowImage* GColMapImage;

	static UEngineSoundPlayer BGMPlayer;
	static std::string PrevBGM;

	// constrcuter destructer
	Global();
	~Global();

	// delete Function
	Global(const Global& _Other) = delete;
	Global(Global&& _Other) noexcept = delete;
	Global& operator=(const Global& _Other) = delete;
	Global& operator=(Global&& _Other) noexcept = delete;

	static void ChangeBGM(std::string_view _BGMName);
	static void SetPokemonText(UImageRenderer* _TextRenderer, Gdiplus::StringAlignment _SortOption, std::string_view _Text, Color8Bit _Color = Color8Bit::BlackA, float _Size = 14.0f);

protected:

private:

};

#define IScaleMultiple Global::GIScaleMultiple
#define IGBAScreen_X Global::GIGBAScreen_X
#define IGBAScreen_Y Global::GIGBAScreen_Y
#define IScreen_X Global::GIScreen_X
#define	IScreen_Y Global::GIScreen_Y
#define	ITileScale Global::GITileScale
#define	IGameTileScale Global::GIGameTileScale
#define	IHGameTileScale Global::GIHGameTileScale
#define	IHScreen_X Global::GIHSceen_X
#define	IHScreen_Y Global::GIHSceen_Y
		
#define FScaleMultiple Global::GFScaleMultiple
#define FGBAScreen_X Global::GFGBAScreen_X
#define FGBAScreen_Y Global::GFGBAScreen_Y
#define	FScreen_X Global::GFScreen_X
#define	FScreen_Y Global::GFScreen_Y
#define	FTileScale Global::GFTileScale
#define	FGameTileScale Global::GFGameTileScale
#define	FHGameTileScale Global::GFHGameTileScale
#define	FHScreen_X Global::GFHSceen_X
#define	FHScreen_Y Global::GFHSceen_Y

#define FIdleTime Global::GIdleTime
#define FWalkTime Global::GWalkTime
#define FRunTime Global::GRunTime
#define FBikeTime Global::GBikeTime

#define FColCheckDown Global::GColCheckDown
#define FColCheckUp Global::GColCheckUp
#define FColCheckLeft Global::GColCheckLeft
#define FColCheckRight Global::GColCheckRight
