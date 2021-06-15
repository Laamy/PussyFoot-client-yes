#include "EntityList.h"

void EntityList::updateAlpha() {
	float modifier = 0.03f;
	MinecraftGame* game = instance->minecraftGame();
	if (game->canUseKeys) {
		if (textColour.a < 1.0f) textColour.a += modifier;
	}
	else {
		if (textColour.a > 0) textColour.a -= modifier;
	}
}

void EntityList::onRender(class Renderer* renderer) {
	if (player == nullptr || instance == nullptr || instance->guiData() == nullptr)
		return;

	updateAlpha();

	auto size = instance->guiData()->GuiScale() * 10;
	Vec2 res = instance->guiData()->res;

	auto level = player->getLevel();
	auto entities = level->getEntities();
	int offset = 0;
	for (auto ent : entities) {
		if (ent == player) continue;
		offset++;
	}
	if (offset > 0)
	{
		std::string text("Entities: " + std::to_string(offset));
		std::wstring t(text.begin(), text.end());
		float len = renderer->textWidth(t, size);
		Vec2 tPos = Vec2(4, res.y - (renderer->textHeight(t, size) + (instance->guiData()->GuiScale() * 12)) - (2 * 6));
		renderer->drawString(t, size, tPos, textColour);
	} else {
		std::string text("No Entities");
		std::wstring t(text.begin(), text.end());
		float len = renderer->textWidth(t, size);
		Vec2 tPos = Vec2(4, res.y - (renderer->textHeight(t, size) + (instance->guiData()->GuiScale() * 12)) - (2 * 6));
		renderer->drawString(t, size, tPos, textColour);
	}
}