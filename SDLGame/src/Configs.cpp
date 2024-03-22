#include <Configs.h>

int Engine::Configs::Video::get_width() {
	return 1280;
}
int Engine::Configs::Video::get_height() {
	return 720;
}

float Engine::Configs::Video::get_local_width() {
	return 2560.f;
}
float Engine::Configs::Video::get_local_height() {
	return 1440.f;
}

const char* Engine::Configs::AppInfo::get_company() {
	return "Alia's games";
}
const char* Engine::Configs::AppInfo::get_app_name() {
	return "SDLTest";
}
