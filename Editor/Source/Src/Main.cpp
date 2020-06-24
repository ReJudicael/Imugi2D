#include <Imugi.h>

class Game : public IMUGI::Application
{
public:
	Game() = default;
	~Game() = default;
};

IMUGI::Application* IMUGI::CreateApplication()
{
	return new Game();
}
