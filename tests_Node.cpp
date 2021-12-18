#include <iostream>
#include "gtest/gtest.h"

#include "Node.h"

using namespace ::testing;

TEST(Node_test, ConstructorWithoutParams){
    Node *n = new Node(6);
    ASSERT_EQ(6,n->get_val());
    ASSERT_EQ(0,n->get_height());
    ASSERT_EQ(nullptr,n->get_left());
    ASSERT_EQ(nullptr,n->get_right());
}

TEST(Node_test, ConstructorWithHeightButNoChildren){
    Node *n = new Node(5,10);
    ASSERT_EQ(5,n->get_val());
    ASSERT_EQ(10,n->get_height());
    ASSERT_EQ(nullptr,n->get_left());
    ASSERT_EQ(nullptr,n->get_right());
}