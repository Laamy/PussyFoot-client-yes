#include "InfiniteAura.h"

void InfiniteAura::onGmTick(GameMode* GM) {
	if (player == nullptr || GM == nullptr)
		return;
	for (auto ent : player->getLevel()->getEntities()) {
		if (ent == player) continue;
		if (ent->getPos()->distance(*player->getPos()) <= 32) {
			for (int i = 0; i < 2; i++) 
				GM->attack(ent);
		}
	}
}