#include "MyTrainerCardBackGround.h"

AMyTrainerCardBackGround::AMyTrainerCardBackGround()
{
}

AMyTrainerCardBackGround::~AMyTrainerCardBackGround()
{
}

void AMyTrainerCardBackGround::BeginPlay()
{
	ABackGround::BeginPlay();

	SetBackGroundImage("Boy_TrainerCard.png");
}

void AMyTrainerCardBackGround::Tick(float _DeltaTime)
{
	ABackGround::Tick(_DeltaTime);
}