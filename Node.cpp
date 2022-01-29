#include "Node.h"

Node::Node(int val, Node *right, Node *left) :
        value(val),
        right(right),
        left(left) {}

Node::Node(int val, int height, Node *right, Node *left) :
        value(val),
        height(height),
        right(right),
        left(left) {}

const void Node::can_be_child(Node *n) {
    if (n == this) {
        throw NodeError("Cannot be child with itself");
    }
}

void Node::set_left(Node *n) {

    can_be_child(n);
    left = n;

}

void Node::set_right(Node *n) {
    can_be_child(n);
    right = n;
}

void Node::set_height(int h) {
    if (h < 0) {
        throw NodeError("height cannot be negative");
    }
    height = h;
}