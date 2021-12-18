#include "Node.h"

Node::Node(int val,Node *right,Node *left):
value(val),
right(right),
left(left){}

Node::Node(int val,int height,Node *right,Node *left):
value(val),
height(height),
right(right),
left(left){}