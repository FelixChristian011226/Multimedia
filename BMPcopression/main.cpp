#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
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

size_t getFileSize1(const char *fileName) {

	if (fileName == NULL) {
		return 0;
	}
	
	// 这是一个存储文件(夹)信息的结构体，其中有文件大小和创建时间、访问时间、修改时间等
	struct stat statbuf;

	// 提供文件名字符串，获得文件属性结构体
	stat(fileName, &statbuf);
	
	// 获取文件大小
	size_t filesize = statbuf.st_size;

	return filesize;
}

int main()
{
    cout << "Please enter the file name that you want to compress: " << endl;
    cout << "  ";
    string input;
    cin >> input;
    cout << "Please enter the file name of the output file: " << endl;
    cout << "  ";
    string output;
    cin >> output;

    clock_t start_time=clock();
    BMPFILE bmp(input.c_str());
    //ConvertToRGB(&bmp);
    //TestHuffman();
    unordered_map<unsigned char,string> code;
    unordered_map<string, unsigned char> anticode;
    string hufname = input.substr(0,input.length()-4)+".huf";
    encode(hufname.c_str(), &bmp, anticode);
    BMPFILE decode_bmp = decode(hufname.c_str(), anticode);
    writeBMPFile(output.c_str(), &decode_bmp);
    //bmp.writeData("1-data.txt");
    //decode_bmp.writeData("1-decode-data.txt");
    clock_t end_time=clock();
    cout << "Program running time: " << (double)(end_time-start_time)/CLOCKS_PER_SEC << "s" << endl;
    cout << "Compression ratio: " << (double)getFileSize1(hufname.c_str())/getFileSize1(input.c_str()) << endl;
    return 0;
}
