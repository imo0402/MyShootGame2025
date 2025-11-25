#ifndef ACTOR_H_
#define ACTOR_H_

#include <gslib.h>
#include <string>
#include "MyMath.h"
#include "BoundingRectangle.h"

class IWorld;   // まだ作ってないので前方宣言だけ

class Actor {
public:
    Actor() = default;
    virtual ~Actor() = default;

    // 毎フレーム処理
    virtual void update(float delta_time) {}
    // 描画
    virtual void draw() const;
    // ImGui などのデバッグUI用（今は空でOK）
    virtual void draw_gui() const {}
    // 衝突したときの反応
    virtual void react(Actor& other) {}

    // ===== 衝突関連 =====
    void collide(Actor& other);
    bool is_collide(const Actor& other) const;
    void die() { dead_ = true; }
    bool is_dead() const { return dead_; }

    // ===== 情報取得 =====
    const std::string& name() const { return name_; }
    const std::string& tag()  const { return tag_; }

    const Vec2& position() const { return position_; }
    void set_position(const Vec2& p) { position_ = p; }

    const Vec2& velocity() const { return velocity_; }
    void set_velocity(const Vec2& v) { velocity_ = v; }

    float rotation() const { return angle_; }
    void set_rotation(float a) { angle_ = a; }

    BoundingRectangle collider() const {
        return collider_.translate(position_);
    }

protected:
    IWorld* world_{ nullptr }; // ワールドへのポインタ（あとで使う）

    std::string name_;
    std::string tag_;

    Vec2  position_{ 0.0f, 0.0f };
    Vec2  velocity_{ 0.0f, 0.0f };
    float angle_{ 0.0f };      // ラジアン

    bool enable_collider_{ true };
    BoundingRectangle collider_{ 0.0f, 0.0f, 0.0f, 0.0f };
    bool dead_{ false };

    GSuint texture_{ 0 };      // 描画用テクスチャID
};

#endif
