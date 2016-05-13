#include <Configs.h>

int Engine::Configs::Video::get_width() const {
	return 1280;
}
int Engine::Configs::Video::get_height() const {
	return 720;
}

float Engine::Configs::Video::get_local_width() const {
	return 2560.f;
}
float Engine::Configs::Video::get_local_height() const {
	return 1440.f;
}

char* Engine::Configs::AppInfo::get_company() const {
	return (char*)"Alia's games";
}
char* Engine::Configs::AppInfo::get_app_name() const {
	return (char*)"SDLTest";
}
