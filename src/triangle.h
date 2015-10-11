#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_
#include"vertex.h"
class Triangle {
public:
    Triangle(const Vertex &v1, const Vertex &v2, const Vertex &v3):v1(v1), v2(v2), v3(v3){}
    Triangle(Vertex &&v1, Vertex &&v2, Vertex &&V3) :v1(v1), v2(v2), v3(v3) {}
    Vertex v1, v2, v3;
};
#endif
