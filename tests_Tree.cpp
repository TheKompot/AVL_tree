#include <iostream>
#include "gtest/gtest.h"

#include "Tree.h"

using namespace ::testing;

TEST(Tree_test,defaultConstructor){
    Tree *t = new Tree();
    ASSERT_EQ(0,t->get_size());
    delete t;
}
TEST(Tree_test,constructorWithNode){
    Node *n = new Node(5);
    Tree *t = new Tree(n);
    ASSERT_EQ(1,t->get_size());
    delete n;
    delete t;
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
    delete a;
    delete b;
    delete c;
    delete root;
    delete t;
}

TEST(Tree_test,getEmptyTree){
    Tree *t = new Tree();
    ASSERT_EQ(nullptr,t->get_all());
    delete t;
}

TEST(Tree_test,getOnlyRoot){
    Node n(5);
    Tree t(&n);
    int* list = t.get_all();
    ASSERT_EQ(5,list[0]);
    delete []list;
}

TEST(Tree_test,getWithFewNodes){
    Node root(5);
    Node a(4);
    Node b(3);
    Node c(2);
    Node d(1);
    Node e(6);
    Node f(7);

    root.set_left(&c);
    root.set_right(&e);

    c.set_left(&d);
    c.set_right(&a);

    a.set_left(&b);

    e.set_right(&f);
    /*
     Tree setup
     5
    / \
   2   6
  / \   \
 1   4   7
    /
   3
     Inorder is: 1, 2, 3, 4, 5, 6, 7
     */
    Tree t(&root);
    int *list = t.get_all();
    for(int i=0;i<7;i++){
        ASSERT_EQ(i+1,list[i]);
    }
    delete []list;
}
