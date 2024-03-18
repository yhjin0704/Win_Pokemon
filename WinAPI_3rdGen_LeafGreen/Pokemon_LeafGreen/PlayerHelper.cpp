#include "PlayerHelper.h"

std::string PlayerHelper::PlayerName = "";
EMoveType PlayerHelper::PlayerMoveType = EMoveType::Walk;
EMoveType PlayerHelper::PrevMoveType = EMoveType::Walk;
bool PlayerHelper::IsUseMenu = false;
bool PlayerHelper::PlayerPause = false;
Color8Bit PlayerHelper::EncountGround = Color8Bit::BlackA;
bool PlayerHelper::IsWild = false;
bool PlayerHelper::IsEncount = false;

PlayerHelper::PlayerHelper()
{
}

PlayerHelper::~PlayerHelper()
{
}