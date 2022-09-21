#include "JDM.h"

// JDM Basic Setup.

constexpr Uint16 WIDTH = 600U;
constexpr Uint16 HEIGHT = 600U;

using namespace JDM;
class WindowGame : public Game
{
public:
    WindowGame() : Game("Window", WIDTH, HEIGHT)
    {
    }
};

int main(int argv, char **argc)
{
    SP<WindowGame> game = MS<WindowGame>();
    game->run();
    return 0;
}
