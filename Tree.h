#include <iostream>
#include "Node.h"


class Tree{
    Node *root = nullptr;

    public:
        Tree();
        Tree(Node *root);
        virtual void insert(int val);
        virtual bool find(int val);
        virtual bool del(int val);
        virtual int* get_all();
};
