#include "Tree.h"

int Tree::calculate_size(Node *n){
    int add = 1;
    if(n->get_right() != nullptr)
        add += calculate_size(n->get_right());
    if(n->get_left() != nullptr)
        add += calculate_size(n->get_left());
    return add;
}
Tree::Tree(Node *root):root(root){
    size = calculate_size(this->root);
}
int* Tree::get_all(){
return 0;
}

