#include "SR_Nuker.h"
#include <iostream>

std::vector<Vec3> Positions = {};
void SR_Nuker::onEnable() {
	if (player == nullptr)
		return;
	player->printToChat("[JarJar]: Creating positions list...");
	Vec3i tempPos = Vec3i(player->getPos()->x, player->getPos()->y, player->getPos()->z);
	for (int x = -nukerRadius; x < nukerRadius; x++) {
		for (int y = -nukerRadius; y < nukerRadius; y++) {
			for (int z = -nukerRadius; z < nukerRadius; z++) {
				tempPos.x = (int)player->getPos()->x + x;
				tempPos.y = (int)player->getPos()->y + y;
				tempPos.z = (int)player->getPos()->z + z;
				Positions.push_back(Vec3(tempPos.x, tempPos.y, tempPos.z));
			}
		}
	}
}

void SR_Nuker::onDisable() {
	Positions.clear();
}

void SR_Nuker::onGmTick(GameMode* GM) {
	if (player == nullptr || GM == nullptr)
		return;
	if (player->getSelectedItem()->getId() <= 0)
		return;
	if (Positions.size() <= 0) {
		Positions.clear();
		this->isEnabled = false;
	}
	else {
		GM->startBuildBlock(Vec3i(Positions.back().x, Positions.back().y, Positions.back().z), 1);
		GM->stopBuildBlock();
		Positions.pop_back();
	}
}