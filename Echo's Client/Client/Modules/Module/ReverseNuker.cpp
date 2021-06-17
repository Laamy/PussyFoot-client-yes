#include "ReverseNuker.h"

void ReverseNuker::onGmTick(GameMode* GM) {
	if (player == nullptr || GM == nullptr)
		return;
	if (player->getSelectedItem()->getId() <= 0)
		return;
	Vec3i tempPos = Vec3i(player->getPos()->x, player->getPos()->y, player->getPos()->z);
	for (int x = -nukerRadius; x < nukerRadius; x++) {
		for (int y = -nukerRadius; y < nukerRadius; y++) {
			for (int z = -nukerRadius; z < nukerRadius; z++) {
				tempPos.x = (int)GM->player->getPos()->x + x;
				tempPos.y = (int)GM->player->getPos()->y + y;
				tempPos.z = (int)GM->player->getPos()->z + z;
				GM->startBuildBlock(tempPos, 1);
				GM->stopBuildBlock();
			}
		}
	}
}