#include <iostream>
#include "Node.h"
#inlucde "BST.h"

class AVL: public BST{
    Node*  rotate_right(Node *n);
    Node* rotate_left(Node *n);
    int get_hight(Node *n);
    bool is_balanced(Node *n);

public:
    void insert(int val);
    bool find(int val);
    bool del(int val);
};
