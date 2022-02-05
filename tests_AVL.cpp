#include <iostream>
#include "gtest/gtest.h"
#include <chrono>

#include "AVL.h"

using namespace ::testing;
using namespace std::chrono;

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

TEST(AVL_test, normalRightRotation){
    Node root(5);
    Node t1(4);
    Node A(7);
    Node t2(6);
    Node t3(8);

    root.set_left(&A);
    root.set_right(&t3);
    root.set_height(6);

    A.set_left(&t1);
    A.set_right(&t2);
    A.set_height(5);

    t1.set_height(4);
    t2.set_height(3);
    t3.set_height(3);

/*
 creating tree
    root
    /  \
   A   T3
  / \
 t1  t2
 */
/*
 expected tree
      A
     / \
    t1 root
       / \
      t2  t3
 */
    AVL_test tester(&root);
    Node *new_root = tester.rotate_right(&root);
    ASSERT_EQ(&A,new_root);
    ASSERT_EQ(&root,new_root->get_right());
    ASSERT_EQ(&t1,new_root->get_left());
    ASSERT_EQ(&t2,new_root->get_right()->get_left());
    ASSERT_EQ(&t3,new_root->get_right()->get_right());

    //Testing heights
    ASSERT_EQ(5,new_root->get_height());
    ASSERT_EQ(4,new_root->get_right()->get_height());
    ASSERT_EQ(4,new_root->get_left()->get_height());
    ASSERT_EQ(3,new_root->get_right()->get_left()->get_height());
    ASSERT_EQ(3,new_root->get_right()->get_right()->get_height());
}

TEST(AVL_test, testBalance){
    Node root(5);
    Node A(7);
    Node t3(8);

    root.set_left(&A);
    root.set_right(&t3);
    root.set_height(5);

    A.set_height(4);

    t3.set_height(4);
    /*
 creating tree
    root
    /  \
   A   t3
 */
    AVL_test tester(&root);
    ASSERT_EQ(0,tester.get_balance(&root));
    ASSERT_EQ(0,tester.get_balance(nullptr));

    A.set_height(3);
    ASSERT_EQ(-1,tester.get_balance(&root));
}
TEST(AVL_test, balanceWithEmptyNode){
    Node root(5);
    AVL_test tester(&root);
    ASSERT_EQ(0,tester.get_balance(&root));
}
TEST(AVL_test, balanceWithEmptyTree){
    AVL_test tester;
    ASSERT_EQ(0,tester.get_balance(tester.get_root()));
}

TEST(AVL_test,basicInsertTest){
    AVL_test tree;
    tree.insert(5);
    ASSERT_EQ(5,tree.get_root()->get_val());
    tree.insert(6);
    ASSERT_EQ(6,tree.get_root()->get_right()->get_val());
    tree.insert(4);
    ASSERT_EQ(4,tree.get_root()->get_left()->get_val());
    ASSERT_EQ(2,tree.get_root()->get_height());
}

TEST(AVL_test,InsertWithRightRotaton){
    AVL_test tree;
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    ASSERT_EQ(5,tree.get_root()->get_val());
    ASSERT_EQ(6,tree.get_root()->get_right()->get_val());
}

TEST(AVL_test,InsertWithLefttRotaton){
    AVL_test tree;
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    ASSERT_EQ(5,tree.get_root()->get_val());
    ASSERT_EQ(6,tree.get_root()->get_right()->get_val());
}

TEST(AVL_test,MoreComplicatedInsert){
    AVL_test tree;
    for(int i=0;i<1024;i++){
        tree.insert(i);
    }

    ASSERT_TRUE(tree.get_root()->get_height() >=9 && tree.get_root()->get_height() <=11);

}
