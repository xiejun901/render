#include "graph_algothrims.h"
inline OutCode computeOutCode(int xleft, int yup, int xright, int ydown, int x, int y)
{
    OutCode code = INSIDE;
    if (x < xleft)
        code |= LEFT;
    else if (x>xright)
        code |= RIGHT;
    if (y < yup)
        code |= TOP;
    else if (y>ydown)
        code |= BOTTOM;
    return code;

}
bool cohenSutherlandClip(int xleft, int yup, int xright, int ydown, int &x1, int &y1, int &x2, int &y2)
{
    OutCode outcode1 = computeOutCode(xleft, yup, xright, ydown, x1, y1);
    OutCode outcode2 = computeOutCode(xleft, yup, xright, ydown, x2, y2);
    bool accept = false;
    while (true)
    {
        if (!(outcode1 | outcode2))//在外边啦
        {
            accept = true;
            break;
        }
        else if (outcode1 & outcode2)//在里边啦
            break;
        else
        {
            int x, y;
            OutCode outcodeOut = outcode1 ? outcode1 : outcode2;
            if (outcodeOut & TOP)
            {
                //上边部分有出头
                x = x1 + (x2 - x1)*(yup-y1) / (y2 - y1);
                y = yup;
            }
            else if (outcodeOut & BOTTOM)
            {
                //下边部分有出头
                x = x1 + (x2 - x1)*(ydown-y1) / (y2 - y1);
                y = ydown;
            }
            else if (outcodeOut & RIGHT)
            {
                //右边部分有出头
                y = y1 - (y2 - y1)*(xright - x1) / (x2 - x1);
                x = xright;
            }
            else if (outcodeOut & LEFT) 
            { 
                //左边有出头~
                y = y1 - (y2 - y1) * (xleft - x1) / (x2 - x1);
                x = xleft;
            }
            if (outcodeOut == outcode1) {
                x1 = x;
                y1 = y;
                outcode1 = computeOutCode(xleft, yup, xright, ydown, x1, y1);
            }
            else {
                x2 = x;
                y2 = y;
                outcode2 = computeOutCode(xleft, yup, xright, ydown, x2, y2);
            }
        }
    }
    return accept;
}

