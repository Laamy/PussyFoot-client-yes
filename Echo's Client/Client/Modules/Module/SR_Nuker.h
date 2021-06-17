#pragma once
#include "../Module.h"

class SR_Nuker : public Module {
public:
	SR_Nuker(class Client* client, class Category* category, std::string name) : Module(client, category, name) {};
	void onGmTick(class GameMode*);
	void onEnable();
	void onDisable();

	int nukerRadius = 3; // Settings :P
	int tickSpeed = 3;

	int tick = 0;
};