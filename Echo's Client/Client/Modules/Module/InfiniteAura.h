#pragma once
#include "../Module.h"

class InfiniteAura : public Module {
public:
	InfiniteAura(class Client* client, class Category* category, std::string name) : Module(client, category, name) {};
	void onGmTick(class GameMode*);
};