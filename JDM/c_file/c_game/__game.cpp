#include "JDM.h"

__Game::__Game(const std::string &title, const Uint16 width, const Uint16 height) : __WidgetColor(width, height)
{
    JDM::root = this;
    this->title = title;
    this->__initVariable();
    this->__initWindow();
}

__Game::~__Game()
{
    SDL_DestroyWindow(this->__window);
    SDL_DestroyRenderer(JDM::renderer);
    SDL_Quit();
}

void __Game::__initVariable()
{
    this->__mouseL = this->__mouseR = false;
    this->R_color = this->G_color = this->B_color = 0;
}

void __Game::__initWindow()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        this->__window = SDL_CreateWindow(this->title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->width, this->height, SDL_WINDOW_ALLOW_HIGHDPI);
        if (this->__window == 0)
            this->__b_running = SDL_FALSE;
        JDM::renderer = SDL_CreateRenderer(this->__window, -1, 0);
        if (JDM::renderer == 0)
            this->__b_running = SDL_FALSE;
        return;
    }
    this->__b_running = SDL_FALSE;
}

void __Game::run()
{
    std::srand(std::time(NULL));
    while (this->__running())
    {
        __f_time2 = SDL_GetTicks();
        if (__f_time2 - __f_time > 1000 / 63)
        {
            __tTime = 1000 / (__f_time2 - __f_time);
            JDM::elapseTime = 1.0 / __tTime;
            if (this->displayFPS)
                if (JDM::enable_color)
                    Log(FG_CYAN, "FPS", FG_CLEAR, ": ", FG_GREEN, __tTime, FG_CLEAR);
                else
                    Log("FPS: ", __tTime);

            this->manageProperty();
            this->__update();
            this->__islayout();
            this->__pollEvent();
            this->__manageAnimation();
            this->__render();
            __f_time = SDL_GetTicks();
        }
    }
    if (JDM::enable_log)
        if (JDM::enable_color)
            Log("\n", FG_GREEN, "Window", FG_CLEAR, " is ", FG_RED, "Terminated", FG_CLEAR, ".");
        else
            Log("\nWindow is Terminated.");
}

void __Game::__manageAnimation()
{
    for (auto anim : JDM::Animation)
        if (anim->_update() == false)
            JDM::remove_animation(anim);
}

void __Game::__update()
{
    __Widget::_update();
    this->_loopEvent(this->get_this(), UPDATE);
}

void __Game::__islayout() { this->_loopEvent(this->get_this(), ISLAYOUT); }
void __Game::__pollEvent()
{
    while (SDL_PollEvent(&this->__events))
    {
        switch (this->__events.type)
        {
        case SDL_QUIT:
            this->__b_running = SDL_FALSE;
            break;
        case SDL_KEYDOWN:
            this->__keyBoardDown(this->__events.key);
            break;
        case SDL_KEYUP:
            this->__keyBoardUp(this->__events.key);
            break;
        case SDL_MOUSEBUTTONDOWN:
            this->__mouseDown(this->__events.button);
            break;
        case SDL_MOUSEMOTION:
            this->__mouseMotion(this->__events.motion);
            break;
        case SDL_MOUSEBUTTONUP:
            this->__mouseUp(this->__events.button);
            break;
        default:
            break;
        }
    }
}

void __Game::__render()
{
    SDL_SetRenderDrawColor(JDM::renderer, this->R_color, this->G_color, this->B_color, this->A_color);
    SDL_RenderClear(JDM::renderer);
    this->_loopEvent(this->get_this(), RENDER);
    SDL_RenderPresent(JDM::renderer);
}

void __Game::__keyBoardDown(SDL_KeyboardEvent &key)
{
    switch (key.keysym.sym)
    {
    case SDLK_ESCAPE:
        this->__b_running = SDL_FALSE;
        break;
    case SDLK_a:
        JDM::A_key = true;
        break;
    case SDLK_b:
        JDM::B_key = true;
        break;
    case SDLK_c:
        JDM::C_key = true;
        break;
    case SDLK_d:
        JDM::D_key = true;
        break;
    case SDLK_e:
        JDM::E_key = true;
        break;
    case SDLK_f:
        JDM::F_key = true;
        break;
    case SDLK_g:
        JDM::G_key = true;
        break;
    case SDLK_h:
        JDM::H_key = true;
        break;
    case SDLK_i:
        JDM::I_key = true;
        break;
    case SDLK_j:
        JDM::J_key = true;
        break;
    case SDLK_k:
        JDM::K_key = true;
        break;
    case SDLK_l:
        JDM::L_key = true;
        break;
    case SDLK_m:
        JDM::M_key = true;
        break;
    case SDLK_n:
        JDM::N_key = true;
        break;
    case SDLK_o:
        JDM::O_key = true;
        break;
    case SDLK_p:
        JDM::P_key = true;
        break;
    case SDLK_q:
        JDM::Q_key = true;
        break;
    case SDLK_r:
        JDM::R_key = true;
        break;
    case SDLK_s:
        JDM::S_key = true;
        break;
    case SDLK_t:
        JDM::T_key = true;
        break;
    case SDLK_u:
        JDM::U_key = true;
        break;
    case SDLK_v:
        JDM::V_key = true;
        break;
    case SDLK_w:
        JDM::W_key = true;
        break;
    case SDLK_x:
        JDM::X_key = true;
        break;
    case SDLK_y:
        JDM::Y_key = true;
        break;
    case SDLK_z:
        JDM::Z_key = true;
        break;
    case SDLK_LSHIFT:
        JDM::lshift_key = true;
        break;
    case SDLK_RSHIFT:
        JDM::rshift_key = true;
        break;
    case SDLK_LCTRL:
        JDM::lctrl_key = true;
        break;
    case SDLK_RCTRL:
        JDM::rctrl_key = true;
        break;
    case SDLK_CAPSLOCK:
        JDM::capslock_key = true;
        break;
    case SDLK_RETURN:
        JDM::enter_key = true;
        break;
    case SDLK_SPACE:
        JDM::space_key = true;
        break;
    case SDLK_TAB:
        JDM::tab_key = true;
        break;
    case SDLK_0:
        JDM::n0_key = true;
        break;
    case SDLK_1:
        JDM::n1_key = true;
        break;
    case SDLK_2:
        JDM::n2_key = true;
        break;
    case SDLK_3:
        JDM::n3_key = true;
        break;
    case SDLK_4:
        JDM::n4_key = true;
        break;
    case SDLK_5:
        JDM::n5_key = true;
        break;
    case SDLK_6:
        JDM::n6_key = true;
        break;
    case SDLK_7:
        JDM::n7_key = true;
        break;
    case SDLK_8:
        JDM::n8_key = true;
        break;
    case SDLK_9:
        JDM::n9_key = true;
        break;
    case SDLK_UP:
        JDM::up_key = true;
        break;
    case SDLK_DOWN:
        JDM::down_key = true;
        break;
    case SDLK_LEFT:
        JDM::left_key = true;
        break;
    case SDLK_RIGHT:
        JDM::right_key = true;
        break;
    case SDLK_BACKSPACE:
        JDM::backspace_key = true;
        break;
    default:
        break;
    }
}

void __Game::__keyBoardUp(SDL_KeyboardEvent &key)
{
    switch (key.keysym.sym)
    {
    case SDLK_a:
        JDM::A_key = false;
        break;
    case SDLK_b:
        JDM::B_key = false;
        break;
    case SDLK_c:
        JDM::C_key = false;
        break;
    case SDLK_d:
        JDM::D_key = false;
        break;
    case SDLK_e:
        JDM::E_key = false;
        break;
    case SDLK_f:
        JDM::F_key = false;
        break;
    case SDLK_g:
        JDM::G_key = false;
        break;
    case SDLK_h:
        JDM::H_key = false;
        break;
    case SDLK_i:
        JDM::I_key = false;
        break;
    case SDLK_j:
        JDM::J_key = false;
        break;
    case SDLK_k:
        JDM::K_key = false;
        break;
    case SDLK_l:
        JDM::L_key = false;
        break;
    case SDLK_m:
        JDM::M_key = false;
        break;
    case SDLK_n:
        JDM::N_key = false;
        break;
    case SDLK_o:
        JDM::O_key = false;
        break;
    case SDLK_p:
        JDM::P_key = false;
        break;
    case SDLK_q:
        JDM::Q_key = false;
        break;
    case SDLK_r:
        JDM::R_key = false;
        break;
    case SDLK_s:
        JDM::S_key = false;
        break;
    case SDLK_t:
        JDM::T_key = false;
        break;
    case SDLK_u:
        JDM::U_key = false;
        break;
    case SDLK_v:
        JDM::V_key = false;
        break;
    case SDLK_w:
        JDM::W_key = false;
        break;
    case SDLK_x:
        JDM::X_key = false;
        break;
    case SDLK_y:
        JDM::Y_key = false;
        break;
    case SDLK_z:
        JDM::Z_key = false;
        break;
    case SDLK_LSHIFT:
        JDM::lshift_key = false;
        break;
    case SDLK_RSHIFT:
        JDM::rshift_key = false;
        break;
    case SDLK_LCTRL:
        JDM::lctrl_key = false;
        break;
    case SDLK_RCTRL:
        JDM::rctrl_key = false;
        break;
    case SDLK_CAPSLOCK:
        JDM::capslock_key = false;
        break;
    case SDLK_RETURN:
        JDM::enter_key = false;
        break;
    case SDLK_SPACE:
        JDM::space_key = false;
        break;
    case SDLK_TAB:
        JDM::tab_key = false;
        break;
    case SDLK_0:
        JDM::n0_key = false;
        break;
    case SDLK_1:
        JDM::n1_key = false;
        break;
    case SDLK_2:
        JDM::n2_key = false;
        break;
    case SDLK_3:
        JDM::n3_key = false;
        break;
    case SDLK_4:
        JDM::n4_key = false;
        break;
    case SDLK_5:
        JDM::n5_key = false;
        break;
    case SDLK_6:
        JDM::n6_key = false;
        break;
    case SDLK_7:
        JDM::n7_key = false;
        break;
    case SDLK_8:
        JDM::n8_key = false;
        break;
    case SDLK_9:
        JDM::n9_key = false;
        break;
    case SDLK_UP:
        JDM::up_key = false;
        break;
    case SDLK_DOWN:
        JDM::down_key = false;
        break;
    case SDLK_LEFT:
        JDM::left_key = false;
        break;
    case SDLK_RIGHT:
        JDM::right_key = false;
        break;
    case SDLK_BACKSPACE:
        JDM::backspace_key = false;
        break;
    default:
        break;
    }
}

void __Game::__mouseDown(SDL_MouseButtonEvent &mouse)
{
    if (mouse.button == SDL_BUTTON_LEFT)
    {
        this->__mouseL = true;
        this->l_m_down_Func();
        this->_loopEvent(this->get_this(), L_M_DOWN);
    }
    else if (mouse.button == SDL_BUTTON_RIGHT)
    {
        this->__mouseR = true;
        this->r_m_down_Func();
        this->_loopEvent(this->get_this(), R_M_DOWN);
    }
}

void __Game::__mouseMotion(SDL_MouseMotionEvent &mouse)
{
    SDL_GetMouseState(&JDM::mouseX, &JDM::mouseY);
    if (this->__mouseL)
    {
        this->l_m_motion_Func();
        this->_loopEvent(this->get_this(), L_M_MOTION);
    }
    if (this->__mouseR)
    {
        this->r_m_motion_Func();
        this->_loopEvent(this->get_this(), R_M_MOTION);
    }
}

void __Game::__mouseUp(SDL_MouseButtonEvent &mouse)
{
    if (mouse.button == SDL_BUTTON_LEFT)
    {
        this->__mouseL = false;
        this->l_m_up_Func();
        this->_loopEvent(this->get_this(), L_M_UP);
    }
    else if (mouse.button == SDL_BUTTON_RIGHT)
    {
        this->__mouseR = false;
        this->r_m_up_Func();
        this->_loopEvent(this->get_this(), R_M_UP);
    }
}
