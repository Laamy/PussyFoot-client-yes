#include "PlayerSpoof.h"

void PlayerSpoof::updateAlpha() {
	float modifier = 0.03f;
	MinecraftGame* game = instance->minecraftGame();
	if (game->canUseKeys) {
		if (textColour.a < 1.0f) textColour.a += modifier;
	}
	else {
		if (textColour.a > 0) textColour.a -= modifier;
	}
}

void PlayerSpoof::onRender(class Renderer* renderer) {
	if (player == nullptr || instance == nullptr || instance->guiData() == nullptr)
		return;
	updateAlpha();
	auto size = instance->guiData()->GuiScale() * 10;
	Vec2 res = instance->guiData()->res;
	auto level = player->getMultiPlayerLevel();
	auto entities = level->getEntities();
	auto myPos = *player->getPos();
	int offset = 2;
	for (auto ent : entities) {
		if (ent == player) continue;
		if (offset > 16) break;
		std::string text(std::to_string((int)ent->getPos()->x) + ", " + std::to_string((int)ent->getPos()->y) + ", " + std::to_string((int)ent->getPos()->z)
			+ " | " + std::to_string((int)ent->getPos()->distance(myPos))); //  / 99999999999 / 70
		std::wstring t(text.begin(), text.end());
		float len = renderer->textWidth(t, size);
		Vec2 tPos = Vec2(4, res.y - (renderer->textHeight(t, size) + (instance->guiData()->GuiScale() * 12)) - (offset * 20));
		renderer->drawString(t, size, tPos, textColour);
		offset++;
	}
}