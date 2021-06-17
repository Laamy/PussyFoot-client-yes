#include "Nuker.h"
void Nuker::onGmTick(GameMode* GM) {
	if (player == nullptr || GM == nullptr)
		return;
	tick++;
	if (tick == maxTick) {
		Vec3i tempPos = Vec3i(player->getPos()->x, player->getPos()->y, player->getPos()->z);
		for (int x = -nukerRadius; x < nukerRadius; x++) {
			for (int y = -nukerRadius; y < nukerRadius; y++) {
				for (int z = -nukerRadius; z < nukerRadius; z++) {
					tempPos.x = (int)GM->player->getPos()->x + x;
					tempPos.y = (int)GM->player->getPos()->y + y;
					tempPos.z = (int)GM->player->getPos()->z + z;
					GM->destroyBlock(tempPos, 0x07);
				}
			}
		}
		tick = 0;
	}
}