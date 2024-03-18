#include "Npc.h"
#include "Pokemon3rdGen_Core.h"

ANpc::ANpc()
{
}

ANpc::~ANpc()
{
}

void ANpc::BeginPlay()
{
	ACharacter::BeginPlay();

	CharacterRenderer = CreateImageRenderer(ERenderOrder::NpcPosIsUp);
	CharacterIfDownRenderer = CreateImageRenderer(ERenderOrder::NpcPosIsDown);

	DownCollision = CreateCollision(ECollisionOrder::Npc);
	DownCollision->SetScale({ IGameTileScale / 2 , IGameTileScale / 2 });
	DownCollision->SetPosition({ GetActorLocation().X, (GetActorLocation().Y + FHGameTileScale + (FHGameTileScale / 2)) });
	DownCollision->SetColType(ECollisionType::Rect);

	UpCollision = CreateCollision(ECollisionOrder::Npc);
	UpCollision->SetScale({ IGameTileScale / 2 , IGameTileScale / 2 });
	UpCollision->SetPosition({ GetActorLocation().X, (GetActorLocation().Y + FHGameTileScale - (FHGameTileScale / 2)) });
	UpCollision->SetColType(ECollisionType::Rect);

	LeftCollision = CreateCollision(ECollisionOrder::Npc);
	LeftCollision->SetScale({ IGameTileScale / 2 , IGameTileScale / 2 });
	LeftCollision->SetPosition({ GetActorLocation().X - (FHGameTileScale / 2), (GetActorLocation().Y + FHGameTileScale) });
	LeftCollision->SetColType(ECollisionType::Rect);

	RightCollision = CreateCollision(ECollisionOrder::Npc);
	RightCollision->SetScale({ IGameTileScale / 2 , IGameTileScale / 2 });
	RightCollision->SetPosition({ GetActorLocation().X + (FHGameTileScale / 2), (GetActorLocation().Y + FHGameTileScale) });
	RightCollision->SetColType(ECollisionType::Rect);

	BattlecheckDownCollision = CreateCollision(ECollisionOrder::BattleCheck);
	BattlecheckUpCollision = CreateCollision(ECollisionOrder::BattleCheck);
	BattlecheckLeftCollision = CreateCollision(ECollisionOrder::BattleCheck);
	BattlecheckRightCollision = CreateCollision(ECollisionOrder::BattleCheck);

	MsgBox = CreateImageRenderer(ERenderOrder::Menu);

	MsgBox->SetImage("Dialogue.png");
	MsgBox->SetTransform({ {0,0}, {MsgBox->GetImage()->GetScale() * FScaleMultiple}});

	MsgBox->ActiveOff();
}

void ANpc::Tick(float _DeltaTime)
{
	ACharacter::Tick(_DeltaTime);
}

void ANpc::SetActiveUpDownRenderer(FVector _PlayerPos)
{
	if (_PlayerPos.Y > GetActorLocation().Y)
	{
		CharacterRenderer->ActiveOn();
		CharacterIfDownRenderer->ActiveOff();
	}
	else
	{
		CharacterRenderer->ActiveOff();
		CharacterIfDownRenderer->ActiveOn();
	}
}

void ANpc::SetDirImage(EDirState _Dir, std::string _ImageName)
{
	switch (_Dir)
	{
	case EDirState::Down:
		CharacterRenderer->SetImage(_ImageName, 0);
		CharacterIfDownRenderer->SetImage(_ImageName, 0);
		break;
	case EDirState::Up:
		CharacterRenderer->SetImage(_ImageName, 1);
		CharacterIfDownRenderer->SetImage(_ImageName, 1);
		break;
	case EDirState::Left:
		CharacterRenderer->SetImage(_ImageName, 2);
		CharacterIfDownRenderer->SetImage(_ImageName, 2);
		break;
	case EDirState::Right:
		CharacterRenderer->SetImage(_ImageName, 3);
		CharacterIfDownRenderer->SetImage(_ImageName, 3);
		break;
	default:
		break;
	}
}

void ANpc::SetColPlayerDir()
{
	std::vector<UCollision*> Result;
	if (true == DownCollision->CollisionCheck(ECollisionOrder::Player, Result))
	{
		SetCharacterDir(EDirState::Down);
	}
	else if (true == UpCollision->CollisionCheck(ECollisionOrder::Player, Result))
	{
		SetCharacterDir(EDirState::Up);
	}
	else if (true == LeftCollision->CollisionCheck(ECollisionOrder::Player, Result))
	{
		SetCharacterDir(EDirState::Left);
	}
	else if (true == RightCollision->CollisionCheck(ECollisionOrder::Player, Result))
	{
		SetCharacterDir(EDirState::Right);
	}
}

void ANpc::SetMsgBoxLocation(FVector _PlayerPos)
{
	MsgBox->SetTransform({ {_PlayerPos.X - (136.f * FScaleMultiple), _PlayerPos.Y - (8.0f * FScaleMultiple)}, {MsgBox->GetImage()->GetScale() * FScaleMultiple} });
	SetTextLocation(_PlayerPos);
}

void ANpc::PushBackEntry(int _DexNo, int _Level, std::string _Ability, float _Hp, float _Atk, float _Def, float _SAtk, float _SDef, float _Spd)
{
	if (6 > Entry.size())
	{
		PokemonInfo info = Pokemon3rdGen_Core::GetAllPokemonInfo()[_DexNo];
		info = SetIV(info, _Hp, _Atk, _Def, _SAtk, _SDef, _Spd);
		info.Ability = _Ability;
		info.PokemonInfo::SetLevel(_Level);
		if (0 == info.MeetLevel)
		{
			info.MeetLevel = _Level;
		}
		Entry.push_back(info);
	}
}

PokemonInfo ANpc::SetIV(PokemonInfo _Pokemon, float _Hp, float _Atk, float _Def, float _SAtk, float _SDef, float _Spd)
{
	_Pokemon.IVHp = _Hp;
	_Pokemon.IVAtk = _Atk;
	_Pokemon.IVDef = _Def;
	_Pokemon.IVSAtk = _SAtk;
	_Pokemon.IVSDef = _SDef;
	_Pokemon.IVSpd = _Spd;
	return _Pokemon;
}
