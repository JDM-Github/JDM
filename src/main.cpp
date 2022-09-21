#include "JDM.h"
#include "JDMStatic.h"
#include "JDMCollision.h"
constexpr Uint16 WIDTH = 600;
constexpr Uint16 HEIGHT = 600;

using namespace JDM;
class WindowGame : public Game
{
public:
    WindowGame() : Game("Window", WIDTH, HEIGHT)
    {
        SP<Rectangle> rect2 = MS<Rectangle>();
        SP<Rectangle> rect = MS<Rectangle>();
        Static::setCenter(*rect, *this);
        rect->limit_control = true;
        rect->control_widget = true;
        rect->left_grab = true;

        this->add_widget(rect);
    }
};

int main(int argv, char **argc)
{
    show_memory = true;
    SP<WindowGame> game = MS<WindowGame>();
    game->run();
    return 0;
}
