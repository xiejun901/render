#ifndef _VERTEX_H_
#define _VERTEX_H_
#include"vector3.h"
#include"Color.h"
class Vertex {
public:
    Vertex(const vector3<int> &p, const Color<int> &c):position(p), color(c){}
    Vertex(vector3<int> &&p, Color<int> &c) :position(p), color(c) {}
    vector3<int> position;
    Color<int> color;
    Vertex &operator+=(const Vertex &right);
    Vertex &operator-=(const Vertex &right);
    Vertex &operator*=(const Vertex &right);
    Vertex &operator*=(const float &right);
};

inline Vertex operator+(const Vertex &left, const Vertex &right)
{
    return Vertex(left) += right;
}

inline Vertex operator-(const Vertex &left, const Vertex &right)
{
    return Vertex(left) -= right;
}

inline Vertex operator*(const Vertex &left, const Vertex &right)
{
    return Vertex(left) *= right;
}

inline Vertex operator*(const Vertex &left, float right)
{
    return Vertex(left) *= right;
}

inline Vertex operator*(float left, const Vertex &right)
{
    return Vertex(right) *= left;
}

#endif