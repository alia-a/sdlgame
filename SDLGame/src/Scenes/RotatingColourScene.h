#pragma once

#include <General.h>
#include <Scene/Scene.h>

DECLARE_EN_CLASS(FillNode);
DECLARE_EN_CLASS(Sprite);

class RotatingColourScene final : public Engine::Scene {
private:
	Engine::sFillNode fn_large_;
	Engine::sFillNode fn_small_;
	Engine::sSprite sprite_;

public:
	RotatingColourScene();
	~RotatingColourScene() override = default;
	RotatingColourScene(const RotatingColourScene&) = default;
	RotatingColourScene& operator=(const RotatingColourScene&) = default;
	RotatingColourScene(RotatingColourScene&&) = default;
	RotatingColourScene& operator=(RotatingColourScene&&) = default;
};
