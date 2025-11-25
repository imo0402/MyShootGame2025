#include "Actor.h"

#include "Actor.h"

void Actor::draw() const
{
    if (texture_ == 0) {
        return; // テクスチャ未設定なら何もしない
    }

    // 位置 = スプライトの中心として描画（とりあえずこれでOK）
    gsDrawSprite2D(
        texture_,       // テクスチャID
        &position_,     // 中心座標
        nullptr,        // 拡大縮小（今は1倍）
        nullptr,        // 原点オフセット
        nullptr,        // 切り取り矩形
        nullptr,        // 色（画像に色ついてるならnullptrでOK）
        angle_          // 回転
    );
}

void Actor::collide(Actor& other) {
    if (!enable_collider_ || !other.enable_collider_) {
        return;
    }
    if (is_collide(other)) {
        react(other);
        other.react(*this);
    }
}

bool Actor::is_collide(const Actor& other) const {
    return collider().intersects(other.collider());
}
