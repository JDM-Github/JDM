#include "JDM.h"
#include "JDMStatic.h"
#include "JDMCollision.h"

#include <stdbool.h>

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
    }
    void manageProperty() override
    {
        /* All loop Property will be here */
    }
};

int main(int argv, char **argc)
{
    MS<WindowGame>()->run();
    return 0;
}
