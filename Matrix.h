#include "Node.h"
#include <iostream>
#include <string>
#include <fstream>

class Matrix {
    private:
        Node* first;
        int rows;
        int cols;

    public:
        void read(std::string fileName, int row, int col);
        bool isEmpty();
        void print();
        bool canBeAdded(Matrix& other);
        Matrix add(Matrix& other);
        bool canBeMultiplied(Matrix& other);
        Matrix multiply(Matrix& multiply);
        void destroyNodes();
};