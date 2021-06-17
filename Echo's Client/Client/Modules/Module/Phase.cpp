#include "Phase.h"

void Phase::onGmTick(GameMode* GM) {
	if (player == nullptr || GM == nullptr)
		return;
}

void Phase::onEnable() {
	player->xyz1_()->y = player->xyz2_()->y;
}

void Phase::onDisable() {
	player->chorusFruitTeleport(player->getPos());
}