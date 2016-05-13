#include <System.h>

#include <Configs.h>
#include <Scene/Node.h>
#include <Scene/SceneHandler.h>
#include <Scene/SceneTransition.h>

#include "Globals.h"
#include "Scenes/RotatingColourScene.h"
#include "Scenes/LoadingScene.h"

void callback() {
	LOG("Initialization done");

	scenes.handler = SHARED(Engine::SceneHandler)();

	auto* root = Engine::Node::get_root();
	root->add_child(scenes.handler);

  scenes.handler->push_scene(SHARED(RotatingColourScene)(), SHARED(Engine::SceneTransition)(), SHARED(Engine::SceneTransition)());
}

void exit_cb() {
	scenes.handler->pop_all_scenes();
}

int main(int, char**) {
	Engine::Configs conf;
	conf.cb_start_ = &callback;
	conf.cb_exit_ = &exit_cb;

	Engine::System::start(&conf);

	return 0;
}
