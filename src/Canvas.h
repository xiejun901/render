#ifndef _CANVAS_H_
#define _CANVAS_H_
class Canvas
{
public:
    Canvas(int width, int height, int *buf);
    void test();
    void setPoint(int column, int row, int r, int g, int b);
    void setPoint(int column, int row, int color);
    void drawLine(int x1, int y1, int x2, int y2);
    ~Canvas();
private:
    int *buf;
    int width;
    int height;
};
#endif

