#pragma once
#include "../Module.h"

class Zoom : public Module {
public:
	Zoom(class Client* client, class Category* category, std::string name) : Module(client, category, name) {};
	void onGmTick(class GameMode*);
};