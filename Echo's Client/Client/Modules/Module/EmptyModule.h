#pragma once
#include "../Module.h"

class EmptyModule : public Module {
public:
	EmptyModule(class Client* client, class Category* category, std::string name) : Module(client, category, name) {};
	void onGmTick(class GameMode*);
	virtual void onPacket(Packet* pkt, bool* cancel);
};