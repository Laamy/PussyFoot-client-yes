#include "InsideAura.h"

void InsideAura::onGmTick(GameMode* GM) {
	for (auto ent : player->getLevel()->getEntities()) {
		if (ent == player) continue;
		if (ent->getPos()->distance(*player->getPos()) <= 6)
			player->teleportTo(ent->getPos(), false, 0, 0);
	}
}