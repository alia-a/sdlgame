#pragma once

#include <Scene/Scene.h>

ENG_CLASS_DERIVED(EmptyModalScene) : public Engine::Scene {
public:
	EmptyModalScene();
	~EmptyModalScene() override = default;
};
