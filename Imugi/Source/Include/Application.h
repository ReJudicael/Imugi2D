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

Application* CreateApplication();

IMUGI_END
