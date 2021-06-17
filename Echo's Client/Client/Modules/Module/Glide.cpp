#include "Glide.h"

void Glide::onGmTick(GameMode* GM) {
	if (player == nullptr || GM == nullptr)
		return;
	player->Velocity()->y = 0;
}