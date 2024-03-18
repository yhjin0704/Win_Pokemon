#pragma once
#include <EngineCore\Actor.h>
#include "Global.h"

class ACharacter : public AActor
{
public:
	// constrcuter destructer
	ACharacter();
	~ACharacter();

	// delete Function
	ACharacter(const ACharacter& _Other) = delete;
	ACharacter(ACharacter&& _Other) noexcept = delete;
	ACharacter& operator=(const ACharacter& _Other) = delete;
	ACharacter& operator=(ACharacter&& _Other) noexcept = delete;

	std::string GetCharacterName()
	{
		return Name;
	}

	void SetCharacterName(std::string _Name)
	{
		Name = _Name;
	}

	void SetCharacterDir(EDirState _Dir)
	{
		PrevDirInput = _Dir;
	}

	EMoveType GetMoveType()
	{
		return MoveType;
	}

	void SetMoveType(EMoveType _MoveType)
	{
		MoveType = _MoveType;
	}

	void SetTextLocation(FVector _PlayerPos);
	void SetTextTop(std::string_view _Text, Color8Bit _TextColor = Color8Bit::BlackA);
	void SetTextBottom(std::string_view _Text, Color8Bit _TextColor = Color8Bit::BlackA);
	void TextOff();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UImageRenderer* CharacterRenderer;
	std::string Name = "";
	std::string CharacterAnimation = "";

	UCollision* IsColCheckCollision = nullptr;

	UCollision* DownCollision = nullptr;
	UCollision* UpCollision = nullptr;
	UCollision* LeftCollision = nullptr;
	UCollision* RightCollision = nullptr;

	UImageRenderer* TextRendererTop = nullptr;
	UImageRenderer* TextRendererBottom = nullptr;

	FVector IsColCheckPos = FVector::Zero;
	FVector EncountCheckPos = FVector::Zero;

	EMoveType MoveType = EMoveType::Walk;
	EMoveState PrevFoot = EMoveState::Left;
	EMoveState MoveState = EMoveState::Idle;
	EDirState PrevDirInput = EDirState::Down;

	bool IsMove = false;
	bool MoveEnd = false;
	float MoveTime = 0.0f;

	FVector StartPos = FVector::Zero;
	FVector TargetPos = FVector::Zero;
	FVector MovingPos = FVector::Zero;

	void SetColCheckPos(EDirState _PrevDirInput);
	bool ColCheck(EDirState _PrevDirInput);
	void SetMovePos();
	void MovePos(float _DeltaTime);

	std::string GetAnimationName(std::string _Name, EMoveType _Move, EDirState _Dir, EMoveState _MoveState = EMoveState::Idle);
	void PlayMoveAnimation();
	void PlayIdleAnimation();

private:

};

