#include "__texture.h"
#include "JDM.h"

SDL_Texture *TextureManager::__createTexture(const std::string &source) { return IMG_LoadTexture(JDM::renderer, source.c_str()); }
SDL_Texture *TextureManager::__createTTFTexture(const std::string &text, const std::string &font, Uint8 r, Uint8 g, Uint8 b)
{
    if (TTF_Init() == 0)
    {
        TTF_Font *tempFont = TTF_OpenFont((font.compare("None") == 0) ? "C:\\JDM\\assets\\font\\orange kid.ttf" : font.c_str(), 256);
        SDL_Surface *tempsurface = TTF_RenderText_Blended(tempFont, text.c_str(), SDL_Color{r, g, b});
        SDL_Texture *texture = SDL_CreateTextureFromSurface(JDM::renderer, tempsurface);
        SDL_FreeSurface(tempsurface);
        TTF_CloseFont(tempFont);
        return texture;
    }
}
