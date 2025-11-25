#ifndef BOUNDING_RECTANGLE_H_
#define BOUNDING_RECTANGLE_H_

#include "MyMath.h"  // Vec2 を使う

class BoundingRectangle {
public:
    BoundingRectangle() = default;

    BoundingRectangle(float left, float top, float right, float bottom)
        : min_{ left, top }
        , max_{ right, bottom } {
    }

    BoundingRectangle(const Vec2& min, const Vec2& max)
        : min_{ min }
        , max_{ max } {
    }

    const Vec2& min() const { return min_; }
    const Vec2& max() const { return max_; }

    float width()  const { return max_.x - min_.x; }
    float height() const { return max_.y - min_.y; }

    // 位置をずらした矩形を返す（Actor の position を足す用）
    BoundingRectangle translate(const Vec2& offset) const {
        return BoundingRectangle{ min_ + offset, max_ + offset };
    }

    // 矩形同士が重なっているか？
    bool intersects(const BoundingRectangle& other) const {
        if (max_.x <= other.min_.x) return false;
        if (min_.x >= other.max_.x) return false;
        if (max_.y <= other.min_.y) return false;
        if (min_.y >= other.max_.y) return false;
        return true;
    }

    // 中心＋サイズから作るヘルパ（プレイヤー等に便利）
    static BoundingRectangle FromCenterSize(const Vec2& center, const Vec2& size) {
        Vec2 half = size * 0.5f;
        return BoundingRectangle{ center - half, center + half };
    }

private:
    Vec2 min_{ 0.0f, 0.0f };
    Vec2 max_{ 0.0f, 0.0f };
};

#endif
