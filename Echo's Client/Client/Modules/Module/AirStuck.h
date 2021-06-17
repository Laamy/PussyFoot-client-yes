#pragma once
#include "../Module.h"

class AirStuck : public Module {
public:
	AirStuck(class Client* client, class Category* category, std::string name) : Module(client, category, name) {};
	void onGmTick(class GameMode*);
};