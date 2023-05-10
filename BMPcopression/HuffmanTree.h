#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <iostream>
#include <windows.h>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

class HuffmanNode{
public:
    HuffmanNode(int weight, char ch);
    HuffmanNode(HuffmanNode* left, HuffmanNode* right);
    ~HuffmanNode();
    bool isLeaf();
    int getWeight();
    unsigned char getCh();
    HuffmanNode* getLeft();
    HuffmanNode* getRight();
    void setWeight(int weight);
    void setCh(unsigned char ch);
    void setLeft(HuffmanNode* left);
    void setRight(HuffmanNode* right);

private:
    bool isleaf=false;
    int weight;
    unsigned char ch;    //-1代表非叶子节点
    HuffmanNode* left;
    HuffmanNode* right;

};

HuffmanNode* merge(HuffmanNode* a, HuffmanNode* b);
HuffmanNode* buildHuffmanTree(int n, int* weight, unsigned char* ch);
void printHuffmanTree(HuffmanNode* root);
void printHuffmanCode(HuffmanNode* root, string &code);
void printLevelOrder(HuffmanNode* root);
void record(HuffmanNode* root, unordered_map<char,string> &code, string &s);
void encode(const char *filename, int n, BYTE *b, const unordered_map<char,string> &code);

#endif