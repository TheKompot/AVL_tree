#include <iostream>

class NodeError : public std::exception {
    std::string text;
public:
    NodeError(const char *v) { text = v; };

    std::string message() const { return text; };
};

class Node {
    int value;
    Node *right;
    Node *left;
    int height = 0;

    void can_be_child(Node *n);

public:
    Node(int val, Node *right = nullptr, Node *left = nullptr);

    Node(int val, int height, Node *right = nullptr, Node *left = nullptr);

    const int get_val() { return value; }

    void set_left(Node *n);

    void set_right(Node *n);

    Node *get_right() { return right; }

    Node *get_left() { return left; }

    void set_height(int h);

    const int get_height() { return height; }
};
