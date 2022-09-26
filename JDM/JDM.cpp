#include "JDM.h"

namespace JDM
{
    bool control_camera = false;
    bool enable_log = true;
    bool enable_color = false;
    bool show_memory = false;
    float camera_x = 0;
    float camera_y = 0;
    float elapseTime = 0.f;
    int mouseX = 0;
    int mouseY = 0;

    Game *root = nullptr;
    SDL_Renderer *renderer = nullptr;
    int randint(const Uint64 &first, const Uint64 &second)
    {
        if (first >= second)
            return second;
        int result = (rand() % second) + first;
        if (result > second)
            result -= (result - second) + (rand() % (second - first) + 1);
        return result;
    }

    std::list<std::shared_ptr<__Animation>> Animation;
    void start_animation(std::shared_ptr<__Animation> anim) { Animation.emplace_back(anim); }
    void remove_animation(std::shared_ptr<__Animation> anim)
    {
        auto position = std::find(Animation.begin(), Animation.end(), anim);
        if (position != Animation.end())
        {
            Animation.erase(position);
        }
    }

    bool A_key = false, B_key = false, C_key = false;
    bool D_key = false, E_key = false, F_key = false;
    bool G_key = false, H_key = false, I_key = false;
    bool J_key = false, K_key = false, L_key = false;
    bool M_key = false, N_key = false, O_key = false;
    bool P_key = false, Q_key = false, R_key = false;
    bool S_key = false, T_key = false, U_key = false;
    bool V_key = false, W_key = false, X_key = false;
    bool Y_key = false, Z_key = false;

    bool lshift_key = false, rshift_key = false, lctrl_key = false, rctrl_key = false;
    bool capslock_key = false, enter_key = false, space_key = false, tab_key = false;
    bool n0_key = false, n1_key = false, n2_key = false, n3_key = false, n4_key = false;
    bool n5_key = false, n6_key = false, n7_key = false, n8_key = false, n9_key = false;

    bool up_key = false, down_key = false, left_key = false, right_key = false, backspace_key = false;
};

void *operator new(size_t size)
{
    if (JDM::show_memory)
        if (JDM::enable_log)
            if (JDM::enable_color)
                Log(FG_YELLOW, "Allocating", FG_CLEAR, ": ", FG_CYAN, size, FG_GREEN, " bytes", FG_CLEAR, "...");
            else
                Log("Allocating: ", size, " bytes...");
    return malloc(size);
}
