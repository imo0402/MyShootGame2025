#ifndef COLOR_H_
#define COLOR_H_

struct Color
{
    float r;
    float g;
    float b;
    float a;

    Color()
        : r(1.0f), g(1.0f), b(1.0f), a(1.0f) {
    }

    Color(float _r, float _g, float _b, float _a = 1.0f)
        : r(_r), g(_g), b(_b), a(_a) {
    }
};

// ------------------
// ÇÊÇ≠égÇ§êFÇíËã`
// ------------------
namespace Colors
{
    static const Color White{ 1.0f, 1.0f, 1.0f, 1.0f };
    static const Color Black{ 0.0f, 0.0f, 0.0f, 1.0f };
    static const Color Red{ 1.0f, 0.0f, 0.0f, 1.0f };
    static const Color Green{ 0.0f, 1.0f, 0.0f, 1.0f };
    static const Color Blue{ 0.0f, 0.0f, 1.0f, 1.0f };
    static const Color Yellow{ 1.0f, 1.0f, 0.0f, 1.0f };
    static const Color Cyan{ 0.0f, 1.0f, 1.0f, 1.0f };
    static const Color Magenta{ 1.0f, 0.0f, 1.0f, 1.0f };
    static const Color Transparent{ 1.0f, 1.0f, 1.0f, 0.0f };
}

#endif

