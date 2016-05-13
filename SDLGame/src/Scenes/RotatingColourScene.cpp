#include "RotatingColourScene.h"

#include <Scene/Fillnode.h>
#include <Scene/Sprite.h>

#include <Scheduler/Scheduler.h>
#include <Scheduler/Task/TaskScale.h>
#include <Scheduler/Task/TaskRotate.h>
#include <Scheduler/Task/TaskCall.h>
#include <Scheduler/Task/SequenceTask.h>
#include <Scheduler/Task/RepeateTask.h>

#include <Event/EventHandler.h>
#include <Globals.h>

#include <Scheduler/MainScheduler.h>

#include <gfx/Texture.h>
#include <Event/Menu.h>

RotatingColourScene::RotatingColourScene() {

	const auto menu = SHARED(Engine::Menu)();
	get_scheduler()->add_task(menu);

	{
		fn_large_ = SHARED(Engine::FillNode)(1440.f, 1440.f);
		fn_large_->set_color({vec4{1, 0, 0, 1}, vec4{0, 1, 0, 1}, vec4{0, 0, 1, 1}, vec4{1, 0, 1, 1}});
		fn_large_->set_rotation_degrees(45.f);

		add_child(fn_large_);
		auto task = SHARED(Engine::TaskRotate)(fn_large_, 90.f);

		get_scheduler()->add_task(task);
	}

	{
		auto tx = SHARED(Engine::Texture)("gfx/heart.png");
		sprite_ = SHARED(Engine::Sprite)(tx);
		sprite_->set_scale(2.f);

		fn_large_->add_child(sprite_);

		auto seq = SHARED(Engine::SequenceTask)();
		{
			auto task = SHARED(Engine::TaskScale)(sprite_, 1.f, vec2{2.f});
			seq->add_task(task);
		}
		{
			auto task = SHARED(Engine::TaskScale)(sprite_, 1.f, vec2{4.f});
			seq->add_task(task);
		}

		auto repeat = SHARED(Engine::RepeateTask)(-1);
		repeat->add_task(seq);

		get_scheduler()->add_task(repeat);
	}

	{
		fn_small_ = SHARED(Engine::FillNode)(200.f, 200.f);
		fn_small_->set_color({vec4{1, 0, 0, 1}, vec4{0, 1, 0, 1}, vec4{0, 0, 1, 1}, vec4{1, 0, 1, 1}});
		fn_small_->set_rotation_degrees(45.f);

		sprite_->add_child(fn_small_);
		auto task = SHARED(Engine::TaskRotate)(fn_small_, 45.f);

		get_scheduler()->add_task(task);
	}

	{
		auto task = SHARED(Engine::TaskCall)([ s = fn_small_, l = fn_large_, sp = sprite_ ](float dt)->bool {
			UNUSED(dt);
			const auto& md = Engine::Events::handler->get_mouse_data();
			if (md.buttons_.at(Engine::MouseButton::LEFT).is_pressed()) {
				s->set_position(Engine::Transform::translate_from_world(sp->get_index(), md.position_));

				if (l->contains(md.position_)) {
					LOG("Hit the square");
				} else {
					LOG("Missed the square");
				}
			}
			if (md.buttons_.at(Engine::MouseButton::RIGHT).is_pressed()) {
				l->set_position(md.position_);
			}

			return false;
		});

		Engine::MainScheduler::get_main_scheduler()->add_task(task);
	}
}

RotatingColourScene::~RotatingColourScene() {
}
