#pragma once
#include "../Module.h"

class InsideAura : public Module {
public:
	InsideAura(class Client* client, class Category* category, std::string name) : Module(client, category, name) {};
	void onGmTick(class GameMode*);
};