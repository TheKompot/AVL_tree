#include <iostream>
#include  "Tree.h"
#include "AVL_test.h"

class AVL: public Tree{
    friend AVL_test;
    Node*  rotate_right(Node *n);
    Node* rotate_left(Node *x);
    bool is_balanced(Node *n);
    bool find(int val, Node *n);
    int max(int a, int b);
public:
    using Tree::Tree;
    void insert(int val);
    bool find(int val);
    bool del(int val);
};
