#ifndef _CANVAS_H_
#define _CANVAS_H_
class Canvas
{
public:
    Canvas(int width, int height, int *buf);
    void test();
    ~Canvas();
private:
    int *buf;
    int width;
    int height;
};
#endif

