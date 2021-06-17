#include "Jesus.h"

void Jesus::onGmTick(GameMode* GM) {
	if (player == nullptr || GM == nullptr)
		return;
	if (player->isInWater() || player->isInLava()) {
		player->Velocity()->y = 0.01f;
	}
}