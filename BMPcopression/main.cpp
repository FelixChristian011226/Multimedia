#include <windows.h>
#include <stdio.h>
//#include "ReadBMP.h"
#include "WriteBMP.h"

int main()
{
    BMPFILE bmp("test.bmp");
    //PrintInfo(&bmp);
    
    BYTE* e = new BYTE[bmp.getImageSize()/3];
    for (int i = 0; i < bmp.getImageSize()/3; i++) {
        e[i] = 0;
    }

    bmp.setR(bmp.getR());
    bmp.setG(e);
    bmp.setB(e);
    writeBMPFile("test2.bmp", &bmp);


    return 0;
}
