#include "Node.h"

Node::Node(int value, int row, int col) {
    this->value = value;
    this->row = row;
    this->col = col;
    this->next = nullptr;
    this->previous = nullptr;
}
bool Node::areNull(Node* other) {
    if (this == nullptr ||
        other == nullptr) {
            return true;
        }
    return false;
}

bool Node::isBehind(Node* other) {
    if (this == nullptr ||
        other == nullptr) {
            return false;
        } else if (this->row < other->row  ||
        (this->row == other->row &&
        this->col < other->col)) {
            return true;
        }
    return false;
}

bool Node::isTied(Node* other) {
    if (this == nullptr ||
        other == nullptr) {
            return false;
        } else if (this->row == other->row &&
        other->col == this->col) {
            return true;
        }
    return false;
}
