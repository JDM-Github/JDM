#include "JDM.h"
#include "JDMStatic.h"
#include "JDMMoveAnim.h"
#include "JDMColorAnim.h"

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
