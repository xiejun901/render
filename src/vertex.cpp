#include "vertex.h"

Vertex & Vertex::operator+=(const Vertex & right)
{
    position += right.position;
    color += right.color;
    return *this;
}

Vertex & Vertex::operator-=(const Vertex & right)
{
    position -= right.position;
    color -= right.color;
    return *this;
}

Vertex & Vertex::operator*=(const Vertex & right)
{
    position *= right.position;
    color *= right.color;
    return *this;
}

Vertex & Vertex::operator*=(const float & right)
{
    position *= right;
    color *= right;
    return *this;
}
