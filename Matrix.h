#include "Node.h"
#include <iostream>
#include <string>
#include <fstream>

class Matrix {
    private:
        Node* first;
        Node* iterator;
        int rows;
        int cols;
    

        bool canBeAdded(Matrix& other);
        bool canBeMultiplied(Matrix& other);
        void destroyNodes();
        void deepCopy(Matrix& result);
        void next();
        bool itrAtHead();
        void pushBack(Node* newNode);
        void pushFront(Node* newNode);
        bool end();
        Node* lastNode();
        void insertBehind(Node* newNode);
    
    public:
        Matrix(int rows, int cols);
        ~Matrix();

        void read(std::string fileName);
        bool isEmpty();
        void print();
        Matrix add(Matrix& other);
        Matrix multiply(Matrix& multiply);
};