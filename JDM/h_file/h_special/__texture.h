#pragma once
#include "__header.h"

struct TextureManager
{
    static SDL_Texture *__createTexture(const std::string &name);
    static SDL_Texture *__createTTFTexture(const std::string &text, const std::string &font = "None", Uint8 r = 255, Uint8 g = 255, Uint8 b = 255);
};
