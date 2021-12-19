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

TEST(AVL_test, emptyLeftRotation){
    AVL_test tester;
    ASSERT_EQ(nullptr,tester.rotate_left(nullptr));
}

TEST(AVL_test, normalLeftRotation){

    Node root(5);
    Node t1(4);
    Node A(7);
    Node t2(6);
    Node t3(8);

    root.set_left(&t1);
    root.set_right(&A);
    root.set_height(6);

    A.set_left(&t2);
    A.set_right(&t3);
    A.set_height(5);

    t1.set_height(3);
    t2.set_height(3);
    t3.set_height(4);

/*
 creating tree
    root
    /  \
   t1   A
       / \
      t2  t3
 */
/*
 expected tree
      A
     / \
   root t3
   / \
  t1  t2
 */
    AVL_test tester(&root);
    Node *new_root = tester.rotate_left(&root);
    ASSERT_EQ(&A,new_root);
    ASSERT_EQ(&t3,new_root->get_right());
    ASSERT_EQ(&root,new_root->get_left());
    ASSERT_EQ(&t1,new_root->get_left()->get_left());
    ASSERT_EQ(&t2,new_root->get_left()->get_right());

    //Testing heights
    ASSERT_EQ(5,new_root->get_height());
    ASSERT_EQ(4,new_root->get_right()->get_height());
    ASSERT_EQ(4,new_root->get_left()->get_height());
    ASSERT_EQ(3,new_root->get_left()->get_left()->get_height());
    ASSERT_EQ(3,new_root->get_left()->get_right()->get_height());


}
