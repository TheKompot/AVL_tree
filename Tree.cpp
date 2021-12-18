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
int* Tree::inorder(Node *n){
    int *left = nullptr;
    int *right = nullptr;

    if(n->get_left()!= nullptr)
        left = inorder(n->get_left());
    if(n->get_right()!= nullptr)
        right = inorder(n->get_right());

    int left_size=0;
    int right_size=0;

    if(left != nullptr)
        left_size = left[0]-1;
    if(right != nullptr)
        right_size = right[0]-1;

    int arr_length = left_size+right_size+2;
    int *output = new int[arr_length];

    output[0] = arr_length;
    for(int i = 1;i<left_size+1;i++){
        output[i] = left[i];
    }
    output[left_size+1] = n->get_val();
    for(int i = 1;i<right_size+1;i++){
        output[i+left_size+1] = right[i];
    }

    delete[] left;
    delete[] right;

    return output;
}

int* Tree::get_all(){
    if(root == nullptr)
        return nullptr;
    int * arr = inorder(root);
    int *output = arr+1;
    delete arr;
    return output;
}

