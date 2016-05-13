#pragma once

#include <General.h>
#include <Scene/Scene.h>

DECLARE_EN_CLASS(FillNode);
DECLARE_EN_CLASS(Sprite);

class RotatingColourScene : public Engine::Scene {
private:
  Engine::sFillNode fn_large_;
  Engine::sFillNode fn_small_;
  Engine::sSprite sprite_;
  
public:
	RotatingColourScene();
	virtual ~RotatingColourScene();
};
