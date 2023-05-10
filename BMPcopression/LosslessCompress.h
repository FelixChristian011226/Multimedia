#ifndef LOSSLESSCOMPRESS_H
#define LOSSLESSCOMPRESS_H

#include <iostream>
#include <fstream>
#include <unordered_map>
#include "ReadBMP.h"
#include "HuffmanTree.h"

void encode(const char *filename, BMPFILE *bmp);

#endif