#include <iostream>
#include "Tree.h"

class BST: public Tree{
    bool find(int val, Node *n);
public:
    using Tree::Tree;
    virtual void insert(int val);
    virtual bool find(int val);
    virtual bool del(int val);
};