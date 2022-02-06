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
            set_size(get_size()+1);
        }
        else{
           node->set_left(insert(node->get_left(), val));
        }
    }
    else if (val > node->get_val()){
        if(node->get_right() == nullptr){
            node->set_right(new Node(val));
            node->get_right()->set_height(1);
            set_size(get_size()+1);
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
        set_size(get_size()+1);
    }
    else{
        root = insert(root,val);
    }

}
const bool AVL::find(int val){
    return find(val,root);
}
void AVL::del(int val){
    root = deleteNode(root,val);

}

Node * AVL::minValueNode(Node* node)
{
    Node* current = node;

    // loop down to find the leftmost leaf
    while (current->get_left() != nullptr)
        current = current->get_left();

    return current;
}


Node* AVL::deleteNode(Node* root, int key)
{

    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == nullptr)
        return root;

    // If the key to be deleted is smaller
    // than the root's key, then it lies
    // in left subtree
    if ( key < root->get_val() )
        root->set_left(deleteNode(root->get_left(), key));

        // If the key to be deleted is greater
        // than the root's key, then it lies
        // in right subtree
    else if( key > root->get_val() )
        root->set_right(deleteNode(root->get_right(), key));

        // if key is same as root's key, then
        // This is the node to be deleted
    else
    {

        // node with only one child or no child
        if( (root->get_left() == nullptr) ||
            (root->get_right() == nullptr) )
        {
            Node *temp = root->get_left() ?
                         root->get_left() :
                         root->get_right();

            // No child case
            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else // One child case
                *root = *temp; // Copy the contents of
            // the non-empty child
            delete temp;
            set_size(get_size()-1);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            Node* temp = minValueNode(root->get_right());

            // Copy the inorder successor's
            // data to this node
            root->set_val(temp->get_val());

            // Delete the inorder successor
            root->set_right(deleteNode(root->get_right(),
                                       temp->get_val())) ;
        }
    }

    // If the tree had only one node
    // then return
    if (root == nullptr)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    if(root->get_right() != nullptr && root->get_left() != nullptr){
        root->set_height(1 + max(root->get_left()->get_height(),
                                 root->get_right()->get_height()));
    }
    else if(root->get_right() != nullptr){
        root->set_height(1 + root->get_right()->get_height());
    }
    else if(root->get_left()!= nullptr){
        root->set_height(1 + root->get_left()->get_height());
    }
    else{
        root->set_height(1);
    }

    // STEP 3: GET THE BALANCE FACTOR OF
    // THIS NODE (to check whether this
    // node became unbalanced)
    int balance = get_balance(root);

    // If this node becomes unbalanced,
    // then there are 4 cases

    // Left Left Case
    if (balance > 1 &&
        get_balance(root->get_left()) >= 0)
        return rotate_right(root);

    // Left Right Case
    if (balance > 1 &&
        get_balance(root->get_left()) < 0)
    {
        root->set_left(rotate_left(root->get_left()));
        return rotate_right(root);
    }

    // Right Right Case
    if (balance < -1 &&
        get_balance(root->get_right()) <= 0)
        return rotate_left(root);

    // Right Left Case
    if (balance < -1 &&
        get_balance(root->get_right()) > 0)
    {
        root->set_right(rotate_right(root->get_right()));
        return rotate_left(root);
    }

    return root;
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