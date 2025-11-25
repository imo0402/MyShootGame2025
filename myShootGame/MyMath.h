#ifndef MY_MATH_H_
#define MY_MATH_H_

#include <gslib.h>
#include <cmath>

// =============================
// 基本型
// =============================

using Vec2 = GSvector2;

// =============================
// 生成ヘルパ
// =============================

inline Vec2 Vec2_Zero() {
    return Vec2{ 0.0f, 0.0f };
}

inline Vec2 Vec2_Set(float x, float y) {
    return Vec2{ x, y };
}

// =============================
// Vec2 演算系（GSvector2 と衝突しない安全なものだけ）
// =============================

inline Vec2 Vec2_Add(const Vec2& a, const Vec2& b) {
    return Vec2{ a.x + b.x, a.y + b.y };
}

inline Vec2 Vec2_Sub(const Vec2& a, const Vec2& b) {
    return Vec2{ a.x - b.x, a.y - b.y };
}

inline Vec2 Vec2_Mul(const Vec2& v, float s) {
    return Vec2{ v.x * s, v.y * s };
}

inline Vec2 Vec2_Div(const Vec2& v, float s) {
    return Vec2{ v.x / s, v.y / s };
}

inline float Vec2_Dot(const Vec2& a, const Vec2& b) {
    return a.x * b.x + a.y * b.y;
}

inline float Vec2_Length(const Vec2& v) {
    return std::sqrtf(v.x * v.x + v.y * v.y);
}

inline float Vec2_LengthSq(const Vec2& v) {
    return v.x * v.x + v.y * v.y;
}

inline Vec2 Vec2_Normalize(const Vec2& v) {
    float len = Vec2_Length(v);
    if (len <= 0.00001f) {
        return Vec2_Zero();
    }
    return Vec2{ v.x / len, v.y / len };
}

inline Vec2 Vec2_MoveTowards(const Vec2& a, const Vec2& b, float maxStep) {
    Vec2 diff{ b.x - a.x, b.y - a.y };
    float dist = Vec2_Length(diff);
    if (dist <= maxStep || dist < 0.00001f) {
        return b;
    }
    float t = maxStep / dist;
    return Vec2{ a.x + diff.x * t, a.y + diff.y * t };
}

// =============================
// 汎用ユーティリティ
// =============================

inline float Clamp(float v, float minV, float maxV) {
    if (v < minV) return minV;
    if (v > maxV) return maxV;
    return v;
}

inline float Lerp(float a, float b, float t) {
    return a + (b - a) * t;
}

inline float Deg2Rad(float deg) {
    return deg * (3.1415926535f / 180.0f);
}

inline float Rad2Deg(float rad) {
    return rad * (180.0f / 3.1415926535f);
}

template<typename T>
inline T MinT(const T& a, const T& b) {
    return (a < b) ? a : b;
}

template<typename T>
inline T MaxT(const T& a, const T& b) {
    return (a > b) ? a : b;
}

// =============================
// ※ GSvector2 と競合する演算子は絶対に再定義しない！
// =============================

// inline Vec2& operator+=(Vec2& a, const Vec2& b) { ... }
// inline Vec2& operator-=(Vec2& a, const Vec2& b) { ... }
// inline Vec2& operator*=(Vec2& v, float s) { ... }
// inline Vec2& operator/=(Vec2& v, float s) { ... }

#endif
