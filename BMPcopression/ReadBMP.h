#ifndef READBMP_H
#define READBMP_H

#include <windows.h>
#include <stdio.h>
#include <string>
#include <stdexcept>

class BMPFILE{
public:
    BMPFILE(const char* filename);
    BMPFILE(int width, int height, int colorDepth, BYTE* bmpData);
    ~BMPFILE();
    DWORD getWidth();
    DWORD getHeight();
    DWORD getColorDepth();
    DWORD getImageSize();
    BYTE* getImageData();
    BYTE* getR();
    BYTE* getG();
    BYTE* getB();
    BYTE* setR(BYTE* r);
    BYTE* setG(BYTE* g);
    BYTE* setB(BYTE* b);

private:
    // 定义BMP文件头、位图信息头、调色板和像素数组等变量
    BITMAPFILEHEADER bmpHeader;
    BITMAPINFOHEADER bmpInfo;
    RGBQUAD palette[256];
    BYTE *bmpData;
    DWORD width, height, colorDepth, imageSize;
};

void PrintInfo(BMPFILE* bmp);

#endif // READBMP_H

