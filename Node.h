#include <iostream>

class Node{
    int value;
    Node *right = nullptr;
    Node *left = nullptr;
    int height;

    public:
        Node(int val,Node *right,Node *left);
        Node(int val,int height,Node *right,Node *left);
        int get_val() { return value;}
        void set_left(Node *n);
        void set_right(Node *n);
        void set_height(int h);
        int get_height() { return height;}
};
