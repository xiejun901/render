#ifndef _CANVAS_H_
#define _CANVAS_H_
class line;
class Triangle;
class Canvas
{
public:
    using OutCode = int;
    Canvas(int width, int height, int *buf);
    void test();
    void setPoint(int column, int row, int r, int g, int b);
    void setPoint(int column, int row, int color);
    void drawLine(int x1, int y1, int x2, int y2);
    //void cohenSutherlandClipAndDraw(int x1, int y1, int x2, int y2);
    //OutCode computeOutCode(int x, int y);
    void drawLine(const line &l);
    void drawTriangle(const Triangle &triangle);
    void clear();
    void testDraw();
    ~Canvas();
//private:
    int *buf;
    int width;
    int height;

    //const OutCode INSIDE = 0;
    //const OutCode LEFT = 1;
    //const OutCode RIGHT = 2;
    //const OutCode BOTTOM = 4;
    //const OutCode TOP = 8;
};
#endif

