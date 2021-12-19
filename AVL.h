#include <iostream>
#include  "Tree.h"

class AVL: public Tree{
    Node*  rotate_right(Node *n);
    Node* rotate_left(Node *n);
    int get_hight(Node *n);
    bool is_balanced(Node *n);
    bool find(int val, Node *n);
public:
    using Tree::Tree;
    void insert(int val);
    bool find(int val);
    bool del(int val);
};
