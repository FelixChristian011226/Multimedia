#include <windows.h>
#include <stdio.h>
#include "ReadBMP.h"
#include "WriteBMP.h"
#include "HuffmanTree.h"
#include "LosslessCompress.h"

void ConvertToRGB(BMPFILE* bmp)
{
    BMPFILE r(bmp);
    BMPFILE g(bmp);
    BMPFILE b(bmp);

    //空BYTE数组
    BYTE* e = new BYTE[bmp->getImageSize()/3];
    for (int i = 0; i < bmp->getImageSize()/3; i++) {
        e[i] = 0;
    }
    r.setG(e);
    r.setB(e);
    g.setR(e);
    g.setB(e);
    b.setR(e);
    b.setG(e);

    writeBMPFile("1-r.bmp", &r);
    writeBMPFile("1-g.bmp", &g);
    writeBMPFile("1-b.bmp", &b);    
}

void TestHuffman()
{
    unsigned char ch[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    int f[8] = {1,2,3,4,5,6,7,8};
    HuffmanNode* root = buildHuffmanTree(8, f, ch);
    printLevelOrder(root);
    string code="";
    printHuffmanCode(root, code);
}

int main()
{
    BMPFILE bmp("0.bmp");
    //ConvertToRGB(&bmp);
    //TestHuffman();
    unordered_map<unsigned char,string> code;
    unordered_map<string, unsigned char> anticode;
    encode("1.txt", &bmp, anticode);
    BMPFILE decode_bmp = decode("1.txt", anticode);
    writeBMPFile("1.bmp", &decode_bmp);
    //bmp.writeData("1-data.txt");
    //decode_bmp.writeData("1-decode-data.txt");

    return 0;
}
