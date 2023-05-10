
#include "LosslessCompress.h"

unsigned char stringToByte(string s, int len)
{
    unsigned char b = 0;
    for(int i=0; i<len; i++)
    {
        b = b << 1;
        if(s[i] == '1')
            b = b | 1;
    }
    return b;
}

void encode(const char *filename, BMPFILE *bmp)
{
   // 打开输出文件
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Failed to create file.\n");
        throw std::runtime_error(("Error: Could not open file " + std::string(filename)));
    }

    // 计算文件头和信息头的大小
    DWORD fileHeaderSize = sizeof(BITMAPFILEHEADER);
    DWORD infoHeaderSize = sizeof(BITMAPINFOHEADER);
    // 计算像素数据的大小（以字节为单位）
    DWORD pixelDataSize = bmp->getWidth() * bmp->getHeight() * sizeof(RGBQUAD);
    // 创建文件头
    BITMAPFILEHEADER fileHeader = {};
    fileHeader.bfType = 0x4D42; // "BM"
    fileHeader.bfSize = bmp->getFileHeader().bfSize;
    fileHeader.bfOffBits = fileHeaderSize + infoHeaderSize;
    // 创建信息头
    BITMAPINFOHEADER infoHeader = {};
    infoHeader.biSize = infoHeaderSize;
    infoHeader.biWidth = bmp->getWidth();
    infoHeader.biHeight = bmp->getHeight();
    infoHeader.biPlanes = 1;
    infoHeader.biBitCount = 24;
    infoHeader.biCompression = BI_RGB;
    infoHeader.biSizeImage = pixelDataSize;
    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, fp);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fp);

    //定义ch数组，0~255即每个BYTE的值，定义weight数组，存储每个BYTE出现的次数，即权重
    unsigned char ch[256];
    int weight[256];
    for(int i=0; i<256; i++)
    {
        ch[i] = i;
        weight[i] = 0;
    }

    //开始统计权重
    for(DWORD i=0; i<bmp->getImageSize(); i++)
    {
        weight[bmp->getImageData()[i]]++;
    }

    //开始建树
    HuffmanNode *root = buildHuffmanTree(256, weight, ch);

    //测试树是否建立成功
    // printLevelOrder(root);

    //开始编码
    unordered_map<unsigned char,string> code;
    string s="";
    record(root, code, s);

    //测试编码是否成功
    // for(int i=0; i<256; i++)
    // {
    //     cout << i << " " << code[i] << endl;
    // }

    //开始写入文件
    string temp;
    unsigned char c;
    for(DWORD i=0; i<bmp->getImageSize(); i++)
    {
        temp += code[bmp->getImageData()[i]];
        if(temp.length() >= 8)
        {
            c = stringToByte(temp, 8);
            fwrite(&c, sizeof(c), 1, fp);
            temp = temp.substr(8);
        }
    }
    if(temp.length() > 0)
    {
        while(temp.length() < 8)
            temp += '0';
        c = stringToByte(temp, 8);
        fwrite(&c, sizeof(c), 1, fp);
    }
    
}