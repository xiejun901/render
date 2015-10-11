#ifndef _GRAPH_ALGOTHRIMS_H_
#define _GRAPH_ALGOTHRIMS_H_
using OutCode = int;
const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;
OutCode computeOutCode(int xleft, int yup, int xright, int ydown, int x, int y);
bool cohenSutherlandClip(int xleft, int yup,
                         int xright, int ydown,
                         int &x1, int &y1,
                         int &x2, int &y2);

#endif
