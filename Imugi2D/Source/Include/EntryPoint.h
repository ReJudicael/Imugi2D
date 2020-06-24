#pragma once

#include "Core/Config.h"

#ifdef IMUGI_PLATFORM_WINDOWS

extern IMUGI::Application* IMUGI::CreateApplication();

int main(int argc, char** argv)
{
	auto app = IMUGI::CreateApplication();
	app->Run();
	delete app;
}

#endif
