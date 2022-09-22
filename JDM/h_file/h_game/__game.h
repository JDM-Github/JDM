#pragma once
#include "__widget.h"

class __Game : public __Widget
{
public:
    std::string title;
    bool displayFPS = false;

public:
    __Game(const std::string &title = "Window", const Uint16 width = 600, const Uint16 height = 600);
    ~__Game();
    void run();

protected:
    /**
     * Manage Property.
     *  -> Overrideable method, All loopProperty will be in this method.
     */
    virtual void manageProperty() {}

    /**
     * Loop Property
     *  -> Loop through all property.
     *
     * @param Property<>
     */
    template <typename P>
    void loopProperty(property<P> &__property)
    {
        for (auto &prop : __property)
            if (!(prop.first.first == prop.first.second))
            {
                prop.second();
                prop = std::make_pair(std::make_pair(prop.first.second, std::ref(prop.first.second)), prop.second);
            }
    }

private:
    SDL_bool __b_running = SDL_TRUE;
    SDL_Window *__window;
    SDL_Event __events;
    uint32_t __f_time = SDL_GetTicks();
    uint32_t __f_time2;
    float __tTime;
    bool __mouseL, __mouseR;

private:
    void __manageAnimation();

    void __Keyboard();
    void __initWindow();
    void __initVariable();
    void __pollEvent();
    void __update();
    void __islayout();
    void __render();
    void __mouseDown(SDL_MouseButtonEvent &mouse);
    void __mouseMotion(SDL_MouseMotionEvent &mouse);
    void __mouseUp(SDL_MouseButtonEvent &mouse);
    void __keyBoardDown(SDL_KeyboardEvent &key);
    void __keyBoardUp(SDL_KeyboardEvent &key);
    constexpr SDL_bool __running() const { return this->__b_running; }
};
