#pragma once
#include "../Module.h"

class Jesus : public Module {
public:
	Jesus(class Client* client, class Category* category, std::string name) : Module(client, category, name) {};
	void onGmTick(class GameMode*);
};