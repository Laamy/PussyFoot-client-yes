#include "Killaura.h"

void Killaura::onGmTick(GameMode* GM) {
	auto level = player->getMultiPlayerLevel();
	auto entities = level->getEntities();
	auto myPos = *player->getPos();
	int cntg = 0;
	for (auto ent : entities) {
		if (ent == player) continue;
		if (ent->getPos()->distance(myPos) <= 3) {
			cntg++;
		}
	}
	if (cntg < 4) {
		for (auto ent : entities) {
			if (ent == player) continue;
			if (ent->getPos()->distance(myPos) <= range) {
				GM->attack(ent);
			}
		}
	}
	else isEnabled = false;
}