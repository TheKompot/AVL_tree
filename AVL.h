#include <iostream>
#include  "Tree.h"

class AVL: public Tree{
protected:
    Node* rotate_right(Node *x);
    Node* rotate_left(Node *x);
    static int get_balance(Node *n);
    const bool find(int val, Node *n);
    static int max(int a, int b);
public:
    using Tree::Tree;
    void insert(int val);
    const bool find(int val);
    bool del(int val);
};
class AVL_test: public AVL{
    using AVL::AVL;
public:
    Node*  rotate_right(Node *x) {return AVL::rotate_right(x);}
    Node* rotate_left(Node *x) {return AVL::rotate_left(x);}
    int get_balance(Node *n){return AVL::get_balance(n);}
};