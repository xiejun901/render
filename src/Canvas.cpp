#include "Canvas.h"
#include "line.h"
#include "graph_algothrims.h"
#include "triangle.h"
#include <algorithm>
#include <string.h>
using std::abs;
using std::swap;
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
    if (cohenSutherlandClip(0, 0, width, height, x1, y1, x2, y2))
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
}

void Canvas::drawLine(const line &l)
{
    int x1 = l.start.position.getX();
    int y1 = l.start.position.getY();
    int x2 = l.end.position.getX();
    int y2 = l.end.position.getY();
    if (cohenSutherlandClip(0, 0, width, height, x1, y1, x2, y2))
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
                //Color<int> c = l.start.color + ((l.end.color - l.start.color) * (x - x1) / (x2 - x1));
                Color<int> c(0, 0, 0);
                setPoint(x, y, c.red, c.green, c.blue);
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
                //Color<int> c = l.start.color + ((l.end.color - l.start.color) * (x - x1) / (x2 - x1));
                Color<int> c(0, 0, 0);
                setPoint(x, y, c.red, c.green, c.blue);
            }
        }
    }
}

void Canvas::drawTriangle(const Triangle & triangle)
{
    Vertex a = triangle.v1;
    Vertex b = triangle.v2;
    Vertex c = triangle.v3; 
    if (a.position.getY() > b.position.getY())
        swap(a, b);
    if (b.position.getY() > c.position.getY())
        swap(b, c);
    if (a.position.getY() > c.position.getY())
        swap(a, c);
    float middleFactor = (float)(b.position.getY() - a.position.getY()) /(float) (c.position.getY() - a.position.getY());
    Vertex m = a + (c - a)*middleFactor;//A B ÷–µ„M
    static int indexxxx = 100;
    int startY = a.position.getY();
    int endY = b.position.getY();
    for (int y = startY; y <= endY; ++y) 
    {
        float factor = 0;
        if (endY != startY) {
            factor = (float)(y - startY) / (endY - startY);
        }
        Vertex vb = a+(b-a)*factor;
        Vertex va = a+(m-a)*factor;
        if (va.position.getY() != vb.position.getY())
        {
            int a = 10;
            int b = *(&a);
        }
        drawLine(line(va, vb));
    }
    startY = b.position.getY();
    endY = c.position.getY();
    for (int y = startY; y <= endY; ++y) {
        float factor = 0;
        if (endY != startY) {
            factor = (float)(y - startY) / (endY - startY);
        }
        Vertex va = b + (c - b)*factor;
        Vertex vb = m + (c - m)*factor;
        if (va.position.getY() != vb.position.getY())
        {
            int a = 10;
            int b = *(&a);
        }
        drawLine(line(va, vb));
    }
}

void Canvas::clear()
{
    memset(buf, -1,width * height * 4);
}

void Canvas::testDraw()
{
    clear();
    //drawLine(-320, -240, 320, 240);
    //drawLine(320, -240, 320, 240);
    //drawLine(960, -240, 320, 240);
    //drawLine(-320, 240, 320, 240);
    //drawLine(320, 240, 320, 240);
    //drawLine(960, 240, 320, 240);
    //drawLine(-320, 720, 320, 240);
    //drawLine(320, 720, 320, 240);
    //drawLine(960, 720, 320, 240);
    //drawLine(960, 720, -280, -140);
    //drawLine(100, 100, 200, 2000);
    //Vertex v1(vector3<int>(100, 100), Color<int>(255, 255, 0));
    //Vertex v2(vector3<int>(200, 200), Color<int>(0, 255, 255));
    //line l(v1, v2);
    //drawLine(l);
    Vertex v1(vector3<int>(300, 500), Color<int>(0, 255, 255));
    Vertex v2(vector3<int>(300, 700), Color<int>(0, 255, 255));
    Vertex v3(vector3<int>(200, 700), Color<int>(0, 255, 255));
    Triangle tr(v1,v2,v3);
    drawTriangle(tr);
}


Canvas::~Canvas()
{
}
