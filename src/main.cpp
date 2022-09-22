#include "JDM.h"
#include "MoveAnimation.h"

// JDM Basic Setup.

constexpr Uint16 WIDTH = 600U;
constexpr Uint16 HEIGHT = 600U;

using namespace JDM;
class WindowGame : public Game
{
public:
    WindowGame() : Game("Window", WIDTH, HEIGHT)
    {
        SP<Rectangle> rect = MS<Rectangle>(100, 100, 0);
        this->add_widget(rect);
        start_animation(MS<MoveAnimation>(rect, 400, 400, 0.5));
    }
};

int main(int argv, char **argc)
{
    SP<WindowGame> game = MS<WindowGame>();
    game->run();
    return 0;
}
