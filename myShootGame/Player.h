#ifndef PLAYER_H_
#define PLAYER_H_

#include <gslib.h>

// すっごいシンプルなプレイヤークラス
class Player
{
public:
    Player(GSuint texture, const GSvector2& start_pos);

    void update(float dt);
    void draw() const;

private:
    GSuint    texture_{ 0 };          // 使うテクスチャID
    GSvector2 position_{ 0.0f, 0.0f };// 座標
    float     speed_{ 6.0f };         // 移動速度（好きに変えてOK）
};

#endif
