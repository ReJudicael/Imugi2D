#pragma once

#include "Core/Config.h"

IMUGI_BEGIN

class IMUGI_API Application
{
public:
	Application() = default;
	virtual ~Application() = default;

	void Run();
};

// To be defined in CLIENT
Application* CreateApplication();

IMUGI_END
