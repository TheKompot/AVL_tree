#include <iostream>
#include "gtest/gtest.h"

#include "Tree.h"

using namespace ::testing;

TEST(Tree_test,defaultConstructor){
    Tree *t = new Tree();
    ASSERT_EQ(0,t->get_size());
}
TEST(Tree_test,constructorWithNode){
    Node *n = new Node(5);
    Tree *t = new Tree(n);
    ASSERT_EQ(1,t->get_size());
}

TEST(Tree_test,moreNodes){
    Node *root = new Node(5);
    Node *a = new Node(6);
    Node *b = new Node(7);
    Node *c = new Node(8);

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
    Tree *t = new Tree(root);
    ASSERT_EQ(4,t->get_size());
}