#include <iostream>
#include  "Tree.h"

class AVL: public Tree{

    void recursiveDestructor(Node* n);
protected:
    Node* rotate_right(Node *x);
    Node* rotate_left(Node *x);
    static int get_balance(Node *n);
    const bool find(int val, Node *n);
    static int max(int a, int b);
    static Node* minValueNode(Node* node);
    Node* insert(Node* node, int val);
    Node* deleteNode(Node* root, int key);
public:
    using Tree::Tree;
    void insert(int val);
    const bool find(int val);
    void del(int val);
    int get_height() {return root->get_height();}
    ~AVL();
};

class AVL_test: public AVL{
    using AVL::AVL;
public:
    Node*  rotate_right(Node *x) {return AVL::rotate_right(x);}
    Node* rotate_left(Node *x) {return AVL::rotate_left(x);}
    int get_balance(Node *n){return AVL::get_balance(n);}
    Node* get_root(){return AVL::root;}
};