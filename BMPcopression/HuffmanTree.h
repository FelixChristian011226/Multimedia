#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <iostream>
#include <queue>

using namespace std;

class HuffmanNode{
public:
    HuffmanNode(int weight, char ch);
    HuffmanNode(HuffmanNode* left, HuffmanNode* right);
    ~HuffmanNode();
    int getWeight();
    char getCh();
    HuffmanNode* getLeft();
    HuffmanNode* getRight();
    void setWeight(int weight);
    void setCh(char ch);
    void setLeft(HuffmanNode* left);
    void setRight(HuffmanNode* right);

private:
    int weight;
    char ch;    //-1代表非叶子节点
    HuffmanNode* left;
    HuffmanNode* right;

};

HuffmanNode* merge(HuffmanNode* a, HuffmanNode* b);
HuffmanNode* buildHuffmanTree(int n, int* weight, char* ch);
void printHuffmanTree(HuffmanNode* root);
void printHuffmanCode(HuffmanNode* root, string &code);
void printLevelOrder(HuffmanNode* root);

#endif