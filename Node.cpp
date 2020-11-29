#include "Node.h"

Node::Node(int value, int row, int col) {
    this->value = value;
    this->row = row;
    this->col = col;
    this->next = nullptr;
}