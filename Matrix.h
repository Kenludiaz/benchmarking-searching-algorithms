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
        Matrix(int rows, int cols);

        ~Matrix();
        void read(std::string fileName);
        bool isEmpty();
        void print();
        bool canBeAdded(Matrix& other);
        Matrix add(Matrix& other);
        bool canBeMultiplied(Matrix& other);
        Matrix multiply(Matrix& multiply);
        void destroyNodes();
};