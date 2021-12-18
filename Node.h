#include <iostream>

class Node{
    int value;
    Node *right;
    Node *left;
    int height = 0;
    public:
        Node(int val,Node *right=nullptr,Node *left=nullptr);
        Node(int val,int height,Node *right=nullptr,Node *left=nullptr);
        int get_val() { return value;}
        void set_left(Node *n);
        void set_right(Node *n);
        Node *get_right() {return right;}
        Node *get_left() {return left;}
        void set_height(int h);
        int get_height() { return height;}
};
