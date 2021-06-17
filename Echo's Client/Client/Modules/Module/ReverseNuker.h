#pragma once
#include "../Module.h"

class ReverseNuker : public Module {
public:
	ReverseNuker(class Client* client, class Category* category, std::string name) : Module(client, category, name) {};
	void onGmTick(class GameMode*);
	int tick = 0;
	int maxTick = 5;
	int nukerRadius = 3;
};