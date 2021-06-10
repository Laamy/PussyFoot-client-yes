#pragma once
#include "../Module.h"

class PlayerSpoof : public Module {
public:
	PlayerSpoof(class Client* client, class Category* category, std::string name) : Module(client, category, name) {};
	void onRender(class Renderer*);
	void updateAlpha();

	_RGBA textColour = _RGBA(255, 255, 255, 1.0f);
};