#include <windows.h>
#include <stdio.h>
//#include "ReadBMP.h"
#include "WriteBMP.h"

int main()
{
    BMPFILE bmp("test.bmp");
    //PrintInfo(&bmp);
    
    writeBMPFile("test2.bmp", &bmp);


    return 0;
}
