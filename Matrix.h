#include "Node.h"

class Matrix {
    private:
        Node* first;
        int rows;
        int cols;

    public:
        bool isEmpty();
        void print();
        bool canBeAdded(Matrix other);
        Matrix add(Matrix other);
        bool canBeMultiplied(Matrix other);
        Matrix multiply(Matrix multiply);
};