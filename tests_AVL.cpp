#include <iostream>
#include "gtest/gtest.h"

#include "AVL.h"

using namespace ::testing;

TEST(AVL_test,constructor){
    AVL *tree = new AVL();
    ASSERT_EQ(tree->get_size(),0);
    ASSERT_EQ(nullptr,tree->get_all());
    delete tree;
}

TEST(AVL_test,successfullFind){
    Node *root = new Node(6);
    Node *a = new Node(5);
    Node *b = new Node(8);
    Node *c = new Node(7);

    root->set_left(a);
    root->set_right(b);
    b->set_left(c);
    /*
     setting up tree
     root
     /  \
    A    B
        /
       C
     */
    AVL *t = new AVL(root);
    ASSERT_TRUE(t->find(8));
    delete a;
    delete b;
    delete c;
    delete root;
    delete t;
}

TEST(AVL_test, emptyRotation){

}
