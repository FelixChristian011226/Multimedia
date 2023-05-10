
// #include "LosslessCompress.h"

// void encode(const char *filename, int n, BMPFILE *bmp, const unordered_map<char,string> &code)
// {
//    // 打开输出文件
//     FILE* fp = fopen(filename, "wb");
//     if (fp == NULL) {
//         printf("Failed to create file.\n");
//         throw std::runtime_error(("Error: Could not open file " + std::string(filename)));
//     }

//     //先写入文件头和信息头
//     fwrite(&bmp->getFileHeader(), sizeof(BITMAPFILEHEADER), 1, fp);
//     fwrite(&bmp->getInfoHeader(), sizeof(BITMAPINFOHEADER), 1, fp);

    
// }