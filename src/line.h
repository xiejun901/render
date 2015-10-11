#ifndef _LINE_H_
#define _LINE_H_
#include "vertex.h"
class line {
public:
    line(const Vertex &start, const Vertex &end) :start(start), end(end) {}
    line(Vertex &&start, Vertex &&end) :start(start), end(end) {}
    Vertex start;
    Vertex end;
};
#endif
