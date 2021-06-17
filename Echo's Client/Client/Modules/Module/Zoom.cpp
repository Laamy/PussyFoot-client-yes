#include "Zoom.h"
#include "../../../Client/Client.h"

void Zoom::onLoop() {
    if (key == NULL) key = 0x43;
    this->isEnabled = client->keyMap[key];
}

void Zoom::onEnable() {
    if (player == nullptr) return;
    player->setFieldOfView(0.3);
}
void Zoom::onDisable() {
    if (player == nullptr) return;
    player->setFieldOfView(1);
}