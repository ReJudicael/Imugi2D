#include <Imugi.h>
#include <iostream>
class Game : public IMUGI::Application
{
public:
	Game() = default;
	~Game() = default;
};

IMUGI::Application* IMUGI::CreateApplication()
{
	std::cout << "test" << std::endl;
	return new Game();
}
