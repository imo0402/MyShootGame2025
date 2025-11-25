#include "Player.h"
#include <cmath>

Player::Player(GSuint texture, const GSvector2& start_pos)
    : texture_(texture)
    , position_(start_pos)
{
}

void Player::update(float dt)
{
    GSvector2 dir{ 0.0f, 0.0f };

    if (gsGetKeyState(GKEY_LEFT))  dir.x -= 1.0f;
    if (gsGetKeyState(GKEY_RIGHT)) dir.x += 1.0f;
    if (gsGetKeyState(GKEY_UP))    dir.y -= 1.0f;
    if (gsGetKeyState(GKEY_DOWN))  dir.y += 1.0f;

    // Î‚ß‚Å‘¬‚­‚È‚è‚·‚¬‚È‚¢‚æ‚¤‚É³‹K‰»
    float len = std::sqrt(dir.x * dir.x + dir.y * dir.y);
    if (len > 0.0f) {
        dir.x /= len;
        dir.y /= len;
    }

    position_.x += dir.x * speed_ * dt;
    position_.y += dir.y * speed_ * dt;

    // ‰æ–ÊŠO‚Éo‚È‚¢‚æ‚¤‚ÉŒy‚­ƒK[ƒhiG‚ÅOKj
    if (position_.x < 0.0f)   position_.x = 0.0f;
    if (position_.y < 0.0f)   position_.y = 0.0f;
    if (position_.x > 1280.0f) position_.x = 1280.0f;
    if (position_.y > 720.0f)  position_.y = 720.0f;
}

void Player::draw() const
{
    if (texture_ == 0) return;

    gsDrawSprite2D(
        texture_,
        &position_,
        nullptr,   // Šg‘åk¬
        nullptr,   // Œ´“_
        nullptr,   // Ø‚èæ‚è
        nullptr,   // F
        0.0f       // ‰ñ“]
    );
}
