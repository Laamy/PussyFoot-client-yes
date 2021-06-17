#include "AirStuck.h"

void AirStuck::onGmTick(GameMode* GM) {
	if (player == nullptr || GM == nullptr)
		return;
	player->Velocity()->x = 0;
	player->Velocity()->y = 0;
	player->Velocity()->z = 0;
}