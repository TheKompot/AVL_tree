#include <iostream>
#include "Node.h"


class Tree{
    Node *root;
    int size;
    int calculate_size(Node *n);
    public:
        Tree():size(0),root(nullptr){}
        Tree(Node *root);
        virtual void insert(int val){}
        virtual bool find(int val){return false;}
        virtual bool del(int val){return false;}
        int* get_all();
        const int get_size() {return size;}
};
