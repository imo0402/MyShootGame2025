#ifndef TEXTURE_MANAGER_H_
#define TEXTURE_MANAGER_H_

#include <gslib.h>
#include "TextureID.h"

class TextureManager
{
public:
    static void LoadAll()
    {
        gsLoadTexture(TEX_PLAYER_RED, "Assets/Texture/Player/player_red.png");
        gsLoadTexture(TEX_PLAYER_BLUE, "Assets/Texture/Player/player_blue.png");
        gsLoadTexture(TEX_PLAYER_YELLOW, "Assets/Texture/Player/player_yellow.png");

        gsLoadTexture(TEX_ENEMY_01, "Texture/Enemy/enemy01.png");
        gsLoadTexture(TEX_ENEMY_02, "Texture/Enemy/enemy02.png");

        gsLoadTexture(TEX_BULLET_01, "Texture/Bullet/bullet01.png");

        gsLoadTexture(TEX_BACKGROUND_01, "Texture/Bg/bg01.png");
    }
};

#endif
