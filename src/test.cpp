#include "JDM.h"
#include "JDMStatic.h"

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
        /* All fun stuff here. */
        // Create Rectangle
        SP<Rectangle> rect = MS<Rectangle>();
        // Use JDM::Static Library
        Static::setCenter(*rect, *this);
        // Add Widget Rectnagle
        this->add_widget(rect);
    }

    void manageProperty() override
    {
        /* All loop Property will be here */
    }
};

int main(int argv, char **argc)
{
    show_memory = true;
    MS<WindowGame>()->run();
    return 0;
}
