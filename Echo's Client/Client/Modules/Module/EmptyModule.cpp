#include "EmptyModule.h"
#include <iostream>
#include <sstream>

void EmptyModule::onGmTick(GameMode* GM) {
	if (player == nullptr)
		return;
}

std::string delimiter = ".";

void EmptyModule::onPacket(Packet* packet, bool* cancel) {
    if (packet->instanceOf<TextPacket>()) {
        auto currPacket = (TextPacket*)packet;
        if (currPacket->message.starts_with(delimiter)) {
            *cancel = true;
            std::string args[4];
            int i = 0;
            std::stringstream ssin(currPacket->message);
            while (ssin.good() && i < 4) {
                ssin >> args[i];
                ++i;
            }

            if (currPacket->message == delimiter + "help") {
                player->printToChat("--- [[ JarJar Client ]] ---");
                player->printToChat(" ");
                player->printToChat(delimiter + "help - List of helpful commands");
                player->printToChat(delimiter + "fixhitbox - Fix your player hitbox!");
                player->printToChat(delimiter + "top - Teleport to the top block!");
                player->printToChat(delimiter + "tp <int, int, int> - Teleport to a position");
                player->printToChat(delimiter + "prefix <string> - Set the client prefix");
                player->printToChat(delimiter + "xp <int> - Give yourself XP");
                player->printToChat(delimiter + "xpl <int> - Give yourself Levels");
                player->printToChat(delimiter + "say <string, ...> - Send a message into chat");
                player->printToChat(delimiter + "playertp <string> - Teleport to a player");
                player->printToChat(delimiter + "give <string> <int, amount> - Give yourself items!");
            }
            else if (currPacket->message.starts_with(delimiter + "tp ")) {
                player->printToChat("Teleported!!");
                Vec3* vecc = player->getPos();
                vecc->x = std::stoi(args[1]);
                vecc->y = std::stoi(args[2]);
                vecc->z = std::stoi(args[3]);
                player->setPos(vecc);
            }
            else if (currPacket->message.starts_with(delimiter + "fixhitbox")) {
                player->printToChat("Teleported!!");
                auto vecc = player->getPos();
                player->setPos(vecc);
            }
            else if (currPacket->message.starts_with(delimiter + "prefix ")) {
                player->printToChat("Prefix is now '" + args[1] + "'");
                delimiter = args[1];
            }
            else if (currPacket->message.starts_with(delimiter + "playertp ")) {
                for (auto ent : player->getLevel()->getEntities()) {
                    std::string entName = ent->getUsername();
                    std::string _eN = args[1];
                    std::for_each(entName.begin(), entName.end(), [](char& c) { c = ::tolower(c); });
                    std::for_each(_eN.begin(), _eN.end(), [](char& c) { c = ::tolower(c); });
                    if (entName.find(_eN))
                    {
                        player->printToChat("Teleported to " + _eN);
                        player->setPos(ent->getPos());
                    }
                }
            }
            else if (currPacket->message.starts_with(delimiter + "xp ")) {
                player->printToChat("You've just been given XP! ('" + args[1] + "')");
                player->addExperience((int)std::stoi(args[1]));
            }
            else if (currPacket->message.starts_with(delimiter + "xpl ")) {
                player->printToChat("You've just been given Levels!! ('" + args[1] + "')");
                player->addLevels((int)std::stoi(args[1]));
            }
            else if (currPacket->message.starts_with(delimiter + "friend ")) {
                if (args[1] == "add")
                    for (auto ent : player->getLevel()->getEntities())
                        if (ent->getUsername().find(args[2]))
                        {
                            player->printToChat("New Friend " + ent->getUsername());
                            player->canAttack(ent, false);
                        }
                else if (args[1] == "remove")
                    for (auto ent : player->getLevel()->getEntities())
                        if (ent->getUsername().find(args[2]))
                        {
                            player->printToChat("Removed Friend " + ent->getUsername());
                            player->canAttack(ent, true);
                        }
                else player->printToChat("Not a valid friend argument >:(");
            }
            else if (currPacket->message.starts_with(delimiter + "say ")) {
                player->printToChat("Message sent!");
                currPacket->message.erase(0, 5);
                *cancel = false;
            }
            else if (currPacket->message.starts_with(delimiter + "give ")) {
                *cancel = false;
            }
            else if (currPacket->message.starts_with(delimiter + "top")) {
                player->printToChat("Woosh!");
                auto pos = player->getPos();
                pos->y = 320;
                player->chorusFruitTeleport(pos);
            }
            else {
                player->printToChat("Invalid command '" + currPacket->message + "'");
            }
        }
    }
}