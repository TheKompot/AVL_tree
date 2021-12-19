#include "AVL.h"

bool AVL::find(int val, Node *n){
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
void AVL::insert(int val){

}
bool AVL::find(int val){
    return find(val,root);
}
bool AVL::del(int val){
    return false;
}

int AVL::max(int a, int b){
    return (a > b)? a : b;
}

Node* AVL::rotate_left(Node *x){
    Node *y = x->get_right();
    Node *T2 = y->get_left();

    // Perform rotation
    y->set_left(x);
    x->set_right(T2);

    // Update heights
    x->set_height(max(x->get_left()->get_height(),
                      x->get_right()->get_height()) + 1);
    y->set_height(max(y->get_left()->get_height(),
                      y->get_right()->get_height()) + 1);

    // Return new root
    return y;
}
