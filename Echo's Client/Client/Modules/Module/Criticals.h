#pragma once
#include "../Module.h"

class Criticals : public Module {
public:
	Criticals(class Client* client, class Category* category, std::string name) : Module(client, category, name) {};
	void onPacket(class Packet*, bool* cancel = (bool*)false);
};