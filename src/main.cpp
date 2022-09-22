#include "JDM.h"
#include "JDMStatic.h"
#include "JDMMoveAnim.h"

// JDM Basic Setup.

constexpr Uint16 WIDTH = 600U;
constexpr Uint16 HEIGHT = 600U;

using namespace JDM;
class WindowGame : public Game
{
public:
    WindowGame() : Game("Window", WIDTH, HEIGHT) { this->initObject(); }
    void initObject() override
    {
        /**
         * All fun stuff will be in here.
         */
        SP<Rectangle> rect = MS<Rectangle>();
        Static::setCenter(*rect, *this);

        rect->l_m_down_Func = std::bind(
            [](SP<Rectangle> rect)
            {
                if (rect->collide_point(mouseX, mouseY))
                {
                    start_animation(MS<MoveSizeAnimation>(rect, 500, 500, 50, 50));
                }
            },
            rect);
        this->add_widget(rect);
    }

    void manageProperty() override
    {
        /**
         * All JDM Loop Property, will be here.
         */
    }
};

int main(int argv, char **argc)
{
    MS<WindowGame>()->run();
    return 0;
}
