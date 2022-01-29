#include "Tree.h"

const int Tree::calculate_size(Node *n){
    // using recursion get size of tree

    int add = 1; // adding itself to size
    if(n->get_right() != nullptr)
        add += calculate_size(n->get_right()); // adding size of left subtree
    if(n->get_left() != nullptr)
        add += calculate_size(n->get_left()); // adding size of right subtree
    return add;
}
Tree::Tree(Node *root):root(root){
    size = calculate_size(this->root); // calculates size of added tree
}
int* Tree::inorder(Node *n){
    // creates inorder int array of tree
    // first element is size of array (including the first element)
    // returns a pointer of ints from dynamic memory

    int *left = nullptr; // inorder of left subtree
    int *right = nullptr; // inorder of right subtree

    if(n->get_left()!= nullptr)
        left = inorder(n->get_left());
    if(n->get_right()!= nullptr)
        right = inorder(n->get_right());

    int left_size=0;
    int right_size=0;

    if(left != nullptr)
        left_size = left[0]-1; // size of arr "left" without information about size
    if(right != nullptr)
        right_size = right[0]-1; // size of arr "right" without information about size

    int arr_length = left_size+right_size+2; // size of output -> array of ints with inorder
    int *output = new int[arr_length];

    output[0] = arr_length; // first element is size of arr
    for(int i = 1;i<left_size+1;i++){
        output[i] = left[i]; // copying left inorder
    }
    output[left_size+1] = n->get_val(); // adding value of current node
    for(int i = 1;i<right_size+1;i++){
        output[i+left_size+1] = right[i]; // copying right inorder
    }

    delete[] left;
    delete[] right;

    return output;
}

int* Tree::get_all(){
    if(root == nullptr)
        return nullptr;
    int * arr = inorder(root);
    int *output = arr+1; // removing first element with size of array
    delete arr;
    return output;
}

