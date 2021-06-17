#include "Killaura.h"

void Killaura::onGmTick(GameMode* GM) {
	if (player == nullptr || GM == nullptr)
		return;
	auto myPos = *player->getPos();
	for (auto ent : player->getLevel()->getEntities())
		if (ent->getPos()->distance(myPos) <= range && ent != player)
			GM->attack(ent);
}