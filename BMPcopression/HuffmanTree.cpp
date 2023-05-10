
#include "HuffmanTree.h"
using namespace std;

HuffmanNode::HuffmanNode(int weight, char ch)
{
    this->weight = weight;
    this->ch = ch;
    this->left = nullptr;
    this->right = nullptr;
}

HuffmanNode::HuffmanNode(HuffmanNode* left, HuffmanNode* right)
{
    this->weight = left->weight + right->weight;
    this->ch = -1;
    this->left = left;
    this->right = right;
}

HuffmanNode::~HuffmanNode()
{
    delete left;
    delete right;
}

int HuffmanNode::getWeight()
{
    return weight;
}

char HuffmanNode::getCh()
{
    return ch;
}

HuffmanNode* HuffmanNode::getLeft()
{
    return left;
}

HuffmanNode* HuffmanNode::getRight()
{
    return right;
}

void HuffmanNode::setWeight(int weight)
{
    this->weight = weight;
}

void HuffmanNode::setCh(char ch)
{
    this->ch = ch;
}

void HuffmanNode::setLeft(HuffmanNode* left)
{
    this->left = left;
}

void HuffmanNode::setRight(HuffmanNode* right)
{
    this->right = right;
}

HuffmanNode* merge(HuffmanNode* a, HuffmanNode* b)
{
    return new HuffmanNode(a, b);
}

class compareWeight {
public:
    bool operator()(HuffmanNode* a, HuffmanNode* b)
    {
        return a->getWeight() > b->getWeight();
    }
};

HuffmanNode* buildHuffmanTree(int n, int* weight, char* ch)
{
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, compareWeight> pq;
    for (int i = 0; i < n; i++) {
        pq.push(new HuffmanNode(weight[i], ch[i]));
    }
    char c1,c2;
    for (int i = 0; i < n - 1; i++) {
        HuffmanNode* a = pq.top();
        c1 = a->getCh();
        pq.pop();
        HuffmanNode* b = pq.top();
        c2 = b->getCh();
        pq.pop();
        pq.push(merge(a, b));
    }
    return pq.top();
}

void printHuffmanTree(HuffmanNode* root)
{
    if (root->getCh() != -1) {
        cout << root->getCh() << endl;
    }
    else {
        printHuffmanTree(root->getLeft());
        printHuffmanTree(root->getRight());
    }
}

void printHuffmanCode(HuffmanNode* root, string &code)
{
    if (root->getCh() != -1) {
        cout << root->getCh() << " " << code << endl;
    }
    else {
        code.push_back('0');
        printHuffmanCode(root->getLeft(), code);
        code.pop_back();
        code.push_back('1');
        printHuffmanCode(root->getRight(), code);
        code.pop_back();
    }
}

void printLevelOrder(HuffmanNode* root)
{
    queue<HuffmanNode*> q,n;
    q.push(root);
    while (!q.empty()) {
        q.front()->getCh() == -1 ? cout << "N" : cout << q.front()->getCh();
        cout << " ";
        if (q.front()->getLeft() != nullptr) {
            n.push(q.front()->getLeft());
        }
        if (q.front()->getRight() != nullptr) {
            n.push(q.front()->getRight());
        }
        q.pop();
        if (q.empty()) {
            cout << endl;
            swap(q, n);
        }
        
    }
    cout << endl;
}