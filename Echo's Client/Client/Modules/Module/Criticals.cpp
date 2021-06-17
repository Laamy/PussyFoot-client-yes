#include "Criticals.h"

void Criticals::onPacket(Packet* pkt, bool* cancel) {
	if (player == nullptr)
		return;
	if (pkt->instanceOf<MovePlayerPacket>() && player != nullptr) {
		*player->onGround() = false;
	}
}