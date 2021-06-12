#include "InfiniteAura.h"

void InfiniteAura::onGmTick(GameMode* GM) {
	for (auto ent : player->getMultiPlayerLevel()->getEntities()) {
		if (ent == player) continue;
		GM->attack(ent);
	}
}