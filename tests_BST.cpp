#include <iostream>
#include "gtest/gtest.h"

#include "BST.h"

using namespace ::testing;

TEST(BST_test,constructor){
    BST *tree = new BST();
    ASSERT_EQ(tree->get_size(),0);
    ASSERT_EQ(nullptr,tree->get_all());
    delete tree;
}
TEST(BST_test,successfullFind){
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
    BST *t = new BST(root);
    ASSERT_TRUE(t->find(8));
    delete a;
    delete b;
    delete c;
    delete root;
    delete t;
}