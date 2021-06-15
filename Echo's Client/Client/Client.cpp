#include "Client.h"
#include "../Utils/Utils.h"
#include "../Utils/Renderer.h"

Client::Client(std::string name) {
	this->name = name;
	Utils::DebugLogF("Client Instance has been Initialized", std::string(name + "/Logs/Output.txt").c_str(), true);
}

/* Hook Includes */

#include "../Memory/Hooks/Hook.h"

#include "../Memory/Hooks/Hook/ClientInstance.h"
#include "../Memory/Hooks/Hook/GameMode.h"
#include "../Memory/Hooks/Hook/Actor.h"

#include "../Memory/Hooks/Hook/KeyItem.h"

#include "../Memory/Hooks/Hook/SwapChain.h"

#include "../Memory/Hooks/Hook/LoopbackPacketSender.h"

#include "Modules/Module/AirJump.h"
#include "Modules/Module/Killaura.h"
#include "Modules/Module/TabGUI.h"
#include "Modules/Module/Coords.h"
#include "Modules/Module/EntityList.h"
#include "Modules/Module/PlayerSpoof.h"
#include "Modules/Module/InfiniteAura.h"
#include "Modules/Module/InsideAura.h"
#include "Modules/Module/EmptyModule.h"
#include "Modules/Module/Zoom.h"

/* */

void Client::init() {

	Utils::DebugLogF("Initializing Client...");

	Hook::initMH(this); /* Initialize MinHook */

	this->isRunning = true;

	/* Initialize SwapChain (Dx11) Hook */

	SwapChain_Hook* swapChain_Hook = new SwapChain_Hook();
	swapChain_Hook->init();

	/* Initialize Client Instance Hook */
	CInstance_Hook* cI_Hook = new CInstance_Hook();
	cI_Hook->init();

	/* Initialize GameMode tick */
	GameMode_Hook* gm_Hook = new GameMode_Hook();
	gm_Hook->init();

	/* Initialize Actor Hooks */
	Actor_Hook* actor_Hook = new Actor_Hook();
	actor_Hook->init();

	/* Initialize AVKeyItem Hook */
	KeyItem_Hook* key_Hook = new KeyItem_Hook();
	key_Hook->init();

	/* Initialize LoopbackPacketSender Hook */
	Loopback_Hook* loop_Hook = new Loopback_Hook();
	loop_Hook->init();

	/* Initialize Categories */

	Category* beta = new Category(this, "JarJar Beta");
	Category* exploits = new Category(this, "Exploits");
	Category* visual = new Category(this, "Visual");

	/* Initialize Modules */

	new InfiniteAura(this, beta, "InfiniteAura");
	new InsideAura(this, beta, "InsideYoMamaAura");
	new EmptyModule(this, beta, "");
	new EmptyModule(this, beta, "");
	new EmptyModule(this, beta, "");

	new AirJump(this, exploits, "Airjump");
	new Killaura(this, exploits, "Killaura");
	new EmptyModule(this, exploits, "");
	new EmptyModule(this, exploits, "");
	new EmptyModule(this, exploits, "");

	new Coords(this, visual, "Coords");
	new EntityList(this, visual, "EntityList");
	new PlayerSpoof(this, visual, "PlayerSpoof");
	new TabGui(this, visual, "TabGui");
	new Zoom(this, visual, "Zoom");

	/*modulesThread = std::thread([this] {wanna test 
		while (isRunning) {
			for (auto C : this->categories) {
				for (auto M : C->modules) M->baseTick();
			}
		}
	});*/

	while (isRunning) {
		for (auto C : this->categories) {
			for (auto M : C->modules) M->baseTick();
		}
	}
}