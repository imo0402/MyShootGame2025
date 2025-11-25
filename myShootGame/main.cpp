#include <GSgame.h>
#include "Player.h"

// テクスチャIDはとりあえず1だけ
enum TextureID {
    TEX_PLAYER_RED = 1,
};

class MyGame : public gslib::Game
{
public:
    MyGame()
        : gslib::Game(1280, 720, false)  // 解像度とフルスクリーン設定
        , player_(nullptr)
    {
    }

    ~MyGame()
    {
        delete player_;
    }

private:
    Player* player_;

    void start() override
    {
        // ★ ここは「さっき映ったときと同じパス」にしてね
        // 例：x64\Debug\Texture\Player\player_red.png なら ↓ のままでOK
        gsLoadTexture(TEX_PLAYER_RED, "Assets/player_red.png");

        // 画面中央スタート
        GSvector2 pos{ 640.0f, 360.0f };
        player_ = new Player(TEX_PLAYER_RED, pos);
    }

    void update(float dt) override
    {
        if (player_) {
            player_->update(dt);
        }
    }

    void draw() override
    {
        if (player_) {
            player_->draw();
        }
    }

    void end() override
    {
        gsDeleteTexture(TEX_PLAYER_RED);
    }
};

int main()
{
    return MyGame().run();
}
