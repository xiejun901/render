#include "Canvas.h"
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
        
        	*(buf + i * 640 + j) = color;
        }
    }
}

Canvas::~Canvas()
{
}
