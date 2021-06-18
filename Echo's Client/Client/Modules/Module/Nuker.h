#pragma once
#include "../Module.h"

class Nuker : public Module {
public:
	Nuker(class Client* client, class Category* category, std::string name) : Module(client, category, name) {};
	void onGmTick(class GameMode*);
	int tick = 0;
	int maxTick = 5;
	int nukerRadius = 5;
};