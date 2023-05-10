#include <windows.h>
#include <stdio.h>
//#include "ReadBMP.h"
#include "WriteBMP.h"

int main()
{
    BMPFILE bmp("test.bmp");
    
    //空BYTE数组
    BYTE* e = new BYTE[bmp.getImageSize()/3];
    for (int i = 0; i < bmp.getImageSize()/3; i++) {
        e[i] = 0;
    }

    BMPFILE r(&bmp);
    BMPFILE g(&bmp);
    BMPFILE b(&bmp);

    r.setG(e);
    r.setB(e);
    g.setR(e);
    g.setB(e);
    b.setR(e);
    b.setG(e);

    writeBMPFile("r.bmp", &r);
    writeBMPFile("g.bmp", &g);
    writeBMPFile("b.bmp", &b);


    return 0;
}
