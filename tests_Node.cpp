#include <iostream>
#include "gtest/gtest.h"

#include "Node.h"

using namespace ::testing;

TEST(Node_test, ConstructorWithoutParams) {
    Node *n = new Node(6);
    ASSERT_EQ(6, n->get_val());
    ASSERT_EQ(0, n->get_height());
    ASSERT_EQ(nullptr, n->get_left());
    ASSERT_EQ(nullptr, n->get_right());
}

TEST(Node_test, ConstructorWithHeightButNoChildren) {
    Node *n = new Node(5, 10);
    ASSERT_EQ(5, n->get_val());
    ASSERT_EQ(10, n->get_height());
    ASSERT_EQ(nullptr, n->get_left());
    ASSERT_EQ(nullptr, n->get_right());
}

TEST(Node_test, Constructor) {
    Node *child1 = new Node(6);
    Node *child2 = new Node(6);
    Node *n = new Node(6, child1, child2);
    ASSERT_EQ(6, n->get_val());
    ASSERT_EQ(0, n->get_height());
    ASSERT_EQ(child2, n->get_left());
    ASSERT_EQ(child1, n->get_right());
}

TEST(Node_test, ConstructorWithHeight) {
    Node *child1 = new Node(6);
    Node *child2 = new Node(6);
    Node *n = new Node(5, 10, child1, child2);
    ASSERT_EQ(5, n->get_val());
    ASSERT_EQ(10, n->get_height());
    ASSERT_EQ(child2, n->get_left());
    ASSERT_EQ(child1, n->get_right());
}

TEST(Node_test, TestingSetters) {
    Node *n = new Node(5);
    Node *child = new Node(6);

    n->set_height(2);
    ASSERT_EQ(2, n->get_height());

    n->set_left(child);
    ASSERT_EQ(child, n->get_left());
    ASSERT_NE(child, n->get_right());

    n->set_right(child);
    ASSERT_EQ(child, n->get_right());
}

TEST(Node_test, settingLeftExpection) {
    Node *n = new Node(5);
    std::string exception;
    try {
        n->set_left(n);
    }
    catch (NodeError e) {
        exception = e.message();
    }
    ASSERT_EQ("Cannot be child with itself", exception);
    ASSERT_EQ(nullptr, n->get_left());
}

TEST(Node_test, settingRightExpection) {
    Node *n = new Node(5);
    std::string exception;
    try {
        n->set_right(n);
    }
    catch (NodeError e) {
        exception = e.message();
    }
    ASSERT_EQ("Cannot be child with itself", exception);
    ASSERT_EQ(nullptr, n->get_right());
}

TEST(Node_test, settingHeightExpection) {
    Node *n = new Node(5);
    std::string exception;
    try {
        n->set_height(-1);
    }
    catch (NodeError e) {
        exception = e.message();
    }
    ASSERT_EQ("height cannot be negative", exception);
    ASSERT_EQ(0, n->get_height());
}