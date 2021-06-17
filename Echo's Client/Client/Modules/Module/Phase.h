#pragma once
#include "../Module.h"

class Phase : public Module {
public:
	Phase(class Client* client, class Category* category, std::string name) : Module(client, category, name) {};
	void onGmTick(class GameMode*);
	void onEnable();
	void onDisable();
};