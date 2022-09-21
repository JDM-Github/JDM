#pragma once
#include "__game.h"
#include "__image.h"
#include "__label.h"
#include "__color.h"
#include "__gridlayout.h"
#include "__stacklayout.h"

#include "__circle.h"
#include "__rectangle.h"
#include "__line.h"
/**
 * SDL2 Basic Template.
 */
namespace JDM
{
    extern float camera_x, camera_y;
    extern bool control_camera;
    extern bool enable_log;
    extern bool enable_color;
    extern bool show_memory;

    typedef __Vector2F Vector2F;
    typedef __Game Game;
    typedef __Widget Widget;
    typedef __Image Image;
    typedef __Label Label;

    typedef __GridLayout GridLayout;
    typedef __StackLayout StackLayout;

    typedef __Rectangle Rectangle;
    typedef __Circle Circle;
    typedef __Line Line;

    typedef __DragBehavior DragBehavior;
    typedef __MoveAbleBehavior MoveAbleBehavior;

    extern __Game *root;
    extern SDL_Renderer *renderer;
    extern float elapseTime;
    extern int mouseX;
    extern int mouseY;

    template <class T>
    using SP = std::shared_ptr<T>;
    template <class T, typename... Args>
    std::shared_ptr<T> MS(Args... arguments) { return std::make_shared<T>(arguments...); }
    extern int randint(const int &first, const int &second);

    template <typename P>
    void PropertyBind(property<P> &prop, P &var, funcCallback func) { prop.push_back(std::make_pair(std::make_pair(var, std::ref(var)), func)); }
    template <class W>
    using WMap = std::map<std::string, std::shared_ptr<W>>;
    template <class W>
    using WVec = std::vector<std::shared_ptr<W>>;
    template <class W>
    using WList = std::list<std::shared_ptr<W>>;
    template <class W>
    using WDeq = std::deque<std::shared_ptr<W>>;
    template <class W, size_t T>
    using WArr = std::array<std::shared_ptr<W>, T>;

    extern bool A_key, B_key, C_key;
    extern bool D_key, E_key, F_key;
    extern bool G_key, H_key, I_key;
    extern bool J_key, K_key, L_key;
    extern bool M_key, N_key, O_key;
    extern bool P_key, Q_key, R_key;
    extern bool S_key, T_key, U_key;
    extern bool V_key, W_key, X_key;
    extern bool Y_key, Z_key;

    extern bool lshift_key, rshift_key, lctrl_key, rctrl_key;
    extern bool capslock_key, enter_key, space_key, tab_key;
    extern bool n0_key, n1_key, n2_key, n3_key, n4_key;
    extern bool n5_key, n6_key, n7_key, n8_key, n9_key;

    extern bool up_key, down_key, left_key, right_key, backspace_key;
};
