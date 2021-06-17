#include "AirJump.h"

void AirJump::onGmTick(GameMode* GM) {
	if (player == nullptr || GM == nullptr)
		return;
	*player->onGround() = true;
}