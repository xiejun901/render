#include "Canvas.h"
#include <algorithm>
using std::abs;
Canvas::Canvas(int width, int height, int * buf):width(width), height(height), buf(buf)
{
}

void Canvas::test()
{
    for (int i = 0; i < 480; ++i)
    {
        int color;
        if (i < 80)
        	color = 0x00FF0000;
        else if (i < 160)
        	color = 0x0000FF00;
        else if (i < 240)
        	color = 0x000000FF;
        else if (i < 320)
            color = 0x00FFFF00;
        else if (i<400)
            color = 0x0000FFFF;
        else
            color = 0x00FF00FF;
    
        for (int j = 0; j < 640; ++j)
        {
        	setPoint(j,i,color);
        }
    }
}

inline void Canvas::setPoint(int column, int row, int r, int g, int b)
{
    *(buf + row*width + column) = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void Canvas::setPoint(int column, int row, int color)
{
    *(buf + row*width + column) = color;
}

void Canvas::drawLine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    if (abs(dx) > abs(dy)) {
        int sign = x2 - x1 > 0 ? 1 : -1;
        float ratio = 0;
        if (dx != 0) {
            ratio = (float)dy / dx;
        }

        for (int x = x1; x != x2; x += sign) {
            int y = y1 + static_cast<int>((x - x1) * ratio);
            setPoint(x, y, 0);
        }
    }
    else {
        int sign = y2 - y1 > 0 ? 1 : -1;
        float ratio = 0;
        if (dy != 0) {
            ratio = (float)dx / dy;
        }

        for (int y = y1; y != y2; y += sign) {
            int x = x1 + static_cast<int>((y - y1) * ratio);
            setPoint(x, y, 0);
        }
    }
}

Canvas::~Canvas()
{
}
