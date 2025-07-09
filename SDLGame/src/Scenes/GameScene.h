#pragma once

#include <General.h>
#include <Scene/Scene.h>

DECLARE_EN_CLASS(FillNode);
DECLARE_EN_CLASS(Sprite);

class GameScene final : public Engine::Scene {
private:
	Engine::sFillNode fn_large_;
	Engine::sFillNode fn_small_;
	Engine::sSprite sprite_;

public:
	GameScene();
	~GameScene() override = default;
	GameScene(const GameScene&) = default;
	GameScene& operator=(const GameScene&) = default;
	GameScene(GameScene&&) = default;
	GameScene& operator=(GameScene&&) = default;
};
