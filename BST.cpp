#include "BST.h"

bool BST::find(int val, Node *n){
    if(n->get_val()==val){
        return true;
    }
    if(n->get_val() > val){
        if(n->get_left() != nullptr){
            return find(val,n->get_left());
        }
        return false;
    }
    if(n->get_right() != nullptr){
        return find(val,n->get_right());
    }
    return false;
}
void BST::insert(int val){

}
bool BST::find(int val){
    return find(val,root);
}
bool BST::del(int val){
    return false;
}
