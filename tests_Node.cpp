#include <iostream>
#include "gtest/gtest.h"

#include "Node.h"

using namespace ::testing;

TEST(Node_test, ConstructorWithoutParams){
    Node *n = new Node(6);
    ASSERT_EQ(6,n->get_val());
    ASSERT_EQ(nullptr,n->get_left());
    ASSERT_EQ(nullptr,n->get_right());
}