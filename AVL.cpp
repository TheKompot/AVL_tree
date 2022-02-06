#include "AVL.h"

const bool AVL::find(int val, Node *n){
    // method for finding a value in tree using recursion

    //if value found -> return true
    if(n->get_val()==val){
        return true;
    }
    // if value smaller -> try to go left
    if(n->get_val() > val){
        if(n->get_left() != nullptr){
            // find value in sub tree
            return find(val,n->get_left());
        }
        //if cannot go left -> value is not in tree
        return false;
    }
    // if value larger -> try to go right
    if(n->get_right() != nullptr){
        return find(val,n->get_right());
    }
    return false;
}
Node* AVL::insert(Node* node, int val){

    /* 1. Perform the normal BST insertion */

    if (val < node->get_val()){
        if(node->get_left() == nullptr){
            node->set_left(new Node(val));
            node->get_left()->set_height(1);
        }
        else{
           node->set_left(insert(node->get_left(), val));
        }
    }
    else if (val > node->get_val()){
        if(node->get_right() == nullptr){
            node->set_right(new Node(val));
            node->get_right()->set_height(1);
        }
        else{
            node->set_right(insert(node->get_right(), val));
        }
    }
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    if(node->get_right() != nullptr && node->get_left() != nullptr){
        node->set_height(1 + max(node->get_left()->get_height(),
                                 node->get_right()->get_height()));
    }
    else if(node->get_right() != nullptr){
        node->set_height(1 + node->get_right()->get_height());
    }
    else{
        node->set_height(1 + node->get_left()->get_height());
    }
    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = get_balance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if ( balance > 1 && (node->get_left() == nullptr||val < node->get_left()->get_val()))
        return rotate_right(node);

    // Right Right Case
    if (balance < -1 && (node->get_right() == nullptr||val > node->get_right()->get_val()))
        return rotate_left(node);

    // Left Right Case
    if (balance > 1 && (node->get_left() == nullptr||val > node->get_left()->get_val())){
        node->set_left(rotate_left(node->get_left()));
        return rotate_right(node);
    }

    // Right Left Case
    if (balance < -1 && (node->get_right() == nullptr||val < node->get_right()->get_val())){
        node->set_right(rotate_right(node->get_right()));
        return rotate_left(node);
    }



    return node;
}
void AVL::insert(int val){
    if(root == nullptr){
        root = new Node(val);
        root->set_height(1);
    }
    else{
        root = insert(root,val);
    }

}
const bool AVL::find(int val){
    return find(val,root);
}
bool AVL::del(int val){
    return false;
}

int AVL::max(int a, int b){
    return (a > b)? a : b;
}

Node* AVL::rotate_left(Node *x){
    if(x == nullptr)
        return nullptr;
    Node *y = x->get_right();
    Node *T2 = y->get_left();

    // Perform rotation
    y->set_left(x);
    x->set_right(T2);

    int xleft_height = 0;
    int xright_height = 0;
    int yleft_height = 0;
    int yright_height = 0;

    // Update heights
    if(x->get_left() != nullptr){
        xleft_height = x->get_left()->get_height();
    }
    if(x->get_right()!= nullptr){
        xright_height = x->get_right()->get_height();
    }
    x->set_height(max(xleft_height,
                      xright_height) + 1);
    if(y->get_left() != nullptr){
        yleft_height = y->get_left()->get_height();
    }
    if(y->get_right()!= nullptr){
        yright_height = y->get_right()->get_height();
    }

    y->set_height(max(yleft_height,
                      yright_height) + 1);

    // Return new root
    return y;
}

Node* AVL::rotate_right(Node *x) {
    if(x == nullptr)
        return nullptr;

    Node *y = x->get_left();
    Node *T2 = y->get_right();

    // Perform rotation
    y->set_right(x);
    x->set_left(T2);
    int xleft_height = 0;
    int xright_height = 0;
    int yleft_height = 0;
    int yright_height = 0;

    // Update heights
    if(x->get_left() != nullptr){
        xleft_height = x->get_left()->get_height();
    }
    if(x->get_right()!= nullptr){
        xright_height = x->get_right()->get_height();
    }
    x->set_height(max(xleft_height,
                      xright_height) + 1);
    if(y->get_left() != nullptr){
        yleft_height = y->get_left()->get_height();
    }
    if(y->get_right()!= nullptr){
        yright_height = y->get_right()->get_height();
    }

    y->set_height(max(yleft_height,
                      yright_height) + 1);

    // Return new root
    return y;
}

int AVL::get_balance(Node *n){
    if(n == nullptr)
        return 0;
    if(n->get_left() != nullptr && n->get_right() != nullptr){
        return n->get_left()->get_height() - n->get_right()->get_height();
    }
    if(n->get_left() != nullptr){
        return n->get_left()->get_height();
    }
    if(n->get_right() != nullptr){
        return -n->get_right()->get_height();
    }
    return 0;
}

AVL::~AVL(){
    recursiveDestructor(root);
}

void AVL::recursiveDestructor(Node* n) {
    if(n != nullptr){
        recursiveDestructor(n->get_right());
        recursiveDestructor(n->get_left());
        delete n;
    }
}