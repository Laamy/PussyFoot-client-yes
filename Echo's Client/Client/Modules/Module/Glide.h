#pragma once
#include "../Module.h"

class Glide : public Module {
public:
	Glide(class Client* client, class Category* category, std::string name) : Module(client, category, name) {};
	void onGmTick(class GameMode*);
};