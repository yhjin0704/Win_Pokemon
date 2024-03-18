#include "Character.h"

ACharacter::ACharacter()
{
}

ACharacter::~ACharacter()
{
}

void ACharacter::BeginPlay()
{
	AActor::BeginPlay();

	TextRendererTop = CreateImageRenderer(ERenderOrder::Text);
	TextRendererBottom = CreateImageRenderer(ERenderOrder::Text);

	TextRendererTop->ActiveOff();
	TextRendererBottom->ActiveOff();
}

void ACharacter::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

std::string ACharacter::GetAnimationName(std::string _Name, EMoveType _Move, EDirState _Dir, EMoveState _MoveState)
{
	std::string MoveName = "";
	std::string DirName = "";
	std::string FootName = "";

	switch (_Move)
	{
	case EMoveType::Walk:
		MoveName = "_Walk";
		break;
	case EMoveType::Run:
		MoveName = "_Run";
		break;
	case EMoveType::Bike:
		MoveName = "_Bike";
		break;
	case EMoveType::Surf:
		MoveName = "_Surf";
		break;
	default:
		break;
	}

	switch (_Dir)
	{
	case EDirState::Down:
		DirName = "_Down";
		break;
	case EDirState::Up:
		DirName = "_Up";
		break;
	case EDirState::Left:
		DirName = "_Left";
		break;
	case EDirState::Right:
		DirName = "_Right";
		break;
	default:
		break;
	}

	switch (_MoveState)
	{
	case EMoveState::Idle:
		FootName = "_Idle";
		break;
	case EMoveState::Left:
		FootName = "_R";
		break;
	case EMoveState::Right:
		FootName = "_L";
		break;
	case EMoveState::Jump:
		FootName = "_Jump";
		break;
	default:
		break;
	}

	return _Name + MoveName + DirName + FootName;
}

void ACharacter::SetColCheckPos(EDirState _PrevDirInput)
{
	EncountCheckPos = GetActorLocation();
	switch (_PrevDirInput)
	{
	case EDirState::Down:
		IsColCheckPos = GetActorLocation() + (FVector::Down * FColCheckDown);

		DownCollision->ActiveOn();
		UpCollision->ActiveOff();
		LeftCollision->ActiveOff();
		RightCollision->ActiveOff();

		IsColCheckCollision = DownCollision;
		break;
	case EDirState::Up:
		IsColCheckPos = GetActorLocation() + (FVector::Up * FColCheckUp);

		DownCollision->ActiveOff();
		UpCollision->ActiveOn();
		LeftCollision->ActiveOff();
		RightCollision->ActiveOff();

		IsColCheckCollision = UpCollision;
		break;
	case EDirState::Left:
		IsColCheckPos = GetActorLocation() + (FVector::Left * FColCheckLeft);

		DownCollision->ActiveOff();
		UpCollision->ActiveOff();
		LeftCollision->ActiveOn();
		RightCollision->ActiveOff();

		IsColCheckCollision = LeftCollision;
		break;
	case EDirState::Right:
		IsColCheckPos = GetActorLocation() + (FVector::Right * FColCheckRight);

		DownCollision->ActiveOff();
		UpCollision->ActiveOff();
		LeftCollision->ActiveOff();
		RightCollision->ActiveOn();

		IsColCheckCollision = RightCollision;
		break;
	default:
		break;
	}
}

bool ACharacter::ColCheck(EDirState _PrevDirInput)//FScaleMultiple
{
	std::vector<UCollision*> Result;
	SetColCheckPos(_PrevDirInput);
	Color8Bit ColColor = Global::GColMapImage->GetColor((IsColCheckPos.iX() / IScaleMultiple), (IsColCheckPos.iY() / IScaleMultiple), Color8Bit::MagentaA);
	if (Color8Bit::MagentaA == ColColor)
	{
		return true;
	}
	else if (Color8Bit::BlueA == ColColor)
	{
		return true;
	}
	else if (Color8Bit(0, 255, 255, 0) == ColColor)
	{
		if (EDirState::Down == PrevDirInput)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else if (true == IsColCheckCollision->CollisionCheck(ECollisionOrder::Npc, Result)
		|| true == IsColCheckCollision->CollisionCheck(ECollisionOrder::Item, Result))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ACharacter::SetMovePos()
{
	if (false == IsMove)
	{
		IsMove = true;
		StartPos = GetTransform().GetPosition();

		float OneTile = FGameTileScale;
		switch (PrevDirInput)
		{
		case EDirState::Down:
			if (EMoveState::Jump == MoveState)
			{
				TargetPos = StartPos + (FVector::Down * OneTile * 2);
			}
			else
			{
				TargetPos = StartPos + (FVector::Down * OneTile);
			}
			break;
		case EDirState::Up:
			TargetPos = StartPos + (FVector::Up * OneTile);
			break;
		case EDirState::Left:
			if (EMoveState::Jump == MoveState)
			{
				TargetPos = StartPos + (FVector::Left * OneTile * 2);
			}
			else
			{
				TargetPos = StartPos + (FVector::Left * OneTile);
			}
			break;
		case EDirState::Right:
			if (EMoveState::Jump == MoveState)
			{
				TargetPos = StartPos + (FVector::Right * OneTile * 2);
			}
			else
			{
				TargetPos = StartPos + (FVector::Right * OneTile);
			}
			break;
		}
	}
}

void ACharacter::MovePos(float _DeltaTime)
{
	float MoveStateTime = 0.0f;
	switch (MoveType)
	{
	case EMoveType::Walk:
		if (EMoveState::Jump == MoveState)
		{
			MoveStateTime = _DeltaTime / (FWalkTime * 2.0f);
		}
		else
		{
			MoveStateTime = _DeltaTime / FWalkTime;
		}
		break;
	case EMoveType::Run:
		if (EMoveState::Jump == MoveState)
		{
			MoveStateTime = _DeltaTime / (FWalkTime * 2.0f);
		}
		else
		{
			MoveStateTime = _DeltaTime / FRunTime;
		}
		break;
	case EMoveType::Bike:
		if (EMoveState::Jump == MoveState)
		{
			MoveStateTime = _DeltaTime / (FWalkTime * 2.0f);
		}
		else
		{
			MoveStateTime = _DeltaTime / FBikeTime;
		}
		break;
	case EMoveType::Surf:
		break;
	default:
		break;
	}
	MoveTime += MoveStateTime;
	MovingPos = FVector::LerpClamp(StartPos, TargetPos, MoveTime);
	SetActorLocation(MovingPos);
	if (1.0f <= MoveTime)
	{
		MoveTime = 0.0f;
		IsMove = false;
		MoveEnd = true;
		MoveState = EMoveState::Idle;
	}
}

void ACharacter::PlayMoveAnimation()
{
	float MoveAnimationTime = 0.0f;

	switch (MoveType)
	{
	case EMoveType::Walk:
		MoveAnimationTime = FWalkTime;
		break;
	case EMoveType::Run:
		MoveAnimationTime = FRunTime;
		break;
	case EMoveType::Bike:
		MoveAnimationTime = FBikeTime;
		break;
	case EMoveType::Surf:
		break;
	default:
		break;
	}

	if (EMoveState::Move == MoveState)
	{
		switch (PrevFoot)
		{
		case EMoveState::Left:
			CharacterAnimation = GetAnimationName(Name, MoveType, PrevDirInput, PrevFoot);
			CharacterRenderer->ChangeAnimation(CharacterAnimation, false, 0, MoveAnimationTime / 2.0f);
			PrevFoot = EMoveState::Right;
			break;
		case EMoveState::Right:
			CharacterAnimation = GetAnimationName(Name, MoveType, PrevDirInput, PrevFoot);
			CharacterRenderer->ChangeAnimation(CharacterAnimation, false, 0, MoveAnimationTime / 2.0f);
			PrevFoot = EMoveState::Left;
			break;
		default:
			break;
		}
	}
	else if (EMoveState::Jump == MoveState)
	{
		CharacterAnimation = GetAnimationName(Name, MoveType, PrevDirInput, MoveState);
		CharacterRenderer->ChangeAnimation(CharacterAnimation, false, 0, FWalkTime / 13.0f * 2.0f);
	}
	else
	{
		PlayIdleAnimation();
	}
}

void ACharacter::PlayIdleAnimation()
{
	CharacterAnimation = GetAnimationName(Name, MoveType, PrevDirInput);
	CharacterRenderer->ChangeAnimation(CharacterAnimation);
}

void ACharacter::SetTextLocation(FVector _PlayerPos)
{
	TextRendererTop->SetTransform({ { _PlayerPos.X - (240.0f * FScaleMultiple), _PlayerPos.Y - (16.0f * FScaleMultiple) }, {0, 0} });
	TextRendererBottom->SetTransform({ { _PlayerPos.X - (240.0f * FScaleMultiple), _PlayerPos.Y - (0.0f * FScaleMultiple) }, {0, 0} });
}

void ACharacter::SetTextTop(std::string_view _Text, Color8Bit _TextColor)
{
	TextRendererTop->ActiveOn();
	Global::SetPokemonText(TextRendererTop, Gdiplus::StringAlignment::StringAlignmentNear, _Text, _TextColor);
}

void ACharacter::SetTextBottom(std::string_view _Text, Color8Bit _TextColor)
{
	TextRendererBottom->ActiveOn();
	Global::SetPokemonText(TextRendererBottom, Gdiplus::StringAlignment::StringAlignmentNear, _Text, _TextColor);

}

void ACharacter::TextOff()
{
	TextRendererTop->ActiveOff();
	TextRendererBottom->ActiveOff();
}
